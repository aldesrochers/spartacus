// ============================================================================
// Copyright (C) 2021-
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA
//
// Alexis L. Desrochers (alexisdesrochers@gmail.com)
//
// ============================================================================

#include <iostream>
using namespace std;

// Mercury
#include <Mercury_Engine.hxx>
#include <Mercury_Utilities.hxx>
#include <Mercury_Version.hxx>

// Qt
#include <QDebug>
#include <QDir>
#include <QFileInfo>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlTableModel>
#include <QVariant>


// ============================================================================
/*!
 *  \brief Constructor
*/
// ============================================================================
Mercury_Engine::Mercury_Engine()
{

}

// ============================================================================
/*!
 *  \brief Destructor
*/
// ============================================================================
Mercury_Engine::~Mercury_Engine()
{

}

// ============================================================================
/*!
 *  \brief clusterConnectionName()
*/
// ============================================================================
QString Mercury_Engine::clusterConnectionName(const int theClusterId) const
{
    QString aClusterConnectionName = QString("mercury-cluster-%1").arg(theClusterId);
    return aClusterConnectionName;
}

// ============================================================================
/*!
 *  \brief clusterDatabaseFilePath()
*/
// ============================================================================
QString Mercury_Engine::clusterDatabaseFilePath(const QString &theDirectoryPath,
                                                const QString &theDatabaseName)
{
    QString aFilePath = theDirectoryPath + QDir::separator()
            + QString("Mercury_%1.db").arg(theDatabaseName);
    return aFilePath;
}

// ============================================================================
/*!
 *  \brief createCluster()
 *  Create a new local cluster in the file system. A 'local' cluster is a
 *  database cluster based on SQLite.
*/
// ============================================================================
bool Mercury_Engine::createCluster(const QString &theDirectoryPath,
                                   const QString &theAdminUserName,
                                   const QString &theAdminPassword)
{
    // retrieve the cluster 'admin' database file path
    QString aFileName = clusterDatabaseFilePath(theDirectoryPath, "Admin");

    // define a standard connection name for cluster creation
    QString aClusterConnectionName = QString("mercury-create-local-cluster");

    // check if file already exists
    QFileInfo anInfo(aFileName);
    if(anInfo.exists())
        return false;

    // try to open the database connection
    QSqlDatabase aDatabase = QSqlDatabase::addDatabase("QSQLITE", aClusterConnectionName);
    aDatabase.setDatabaseName(aFileName);
    if(!aDatabase.open())
        return false;

    // initialize a query on the database
    QSqlQuery aQuery(aDatabase);

    // create 'users' table
    QString createUsersTableQuery = QString("CREATE TABLE IF NOT EXISTS users (");
    createUsersTableQuery += "userName TEXT PRIMARY KEY, ";
    createUsersTableQuery += "password TEXT, ";
    createUsersTableQuery += "firstName TEXT, ";
    createUsersTableQuery += "lastName TEXT, ";
    createUsersTableQuery += "email TEXT, ";
    createUsersTableQuery += "canCreateDatabases INTEGER NOT NULL, ";
    createUsersTableQuery += "canCreateRoles INTEGER NOT NULL, ";
    createUsersTableQuery += "canLogin INTEGER NOT NULL, ";
    createUsersTableQuery += "isSuperUser INTEGER NOT NULL, ";
    createUsersTableQuery += "creationDate, ";
    createUsersTableQuery += "expirationDate , ";
    createUsersTableQuery += "firstLoginDate TEXT, ";
    createUsersTableQuery += "lastLoginDate TEXT)";
    if(!aQuery.exec(createUsersTableQuery))
        return false;

    // create 'databases' table
    QString createDatabasesTableQuery = QString("CREATE TABLE IF NOT EXISTS databases (");
    createDatabasesTableQuery += "databaseName TEXT PRIMARY KEY, ";
    createDatabasesTableQuery += "fileName TEXT NOT NULL, ";
    createDatabasesTableQuery += "description TEXT)";
    if(!aQuery.exec(createDatabasesTableQuery))
        return false;

    // insert admin user in database
    QSqlTableModel aModel(0, aDatabase);
    aModel.setTable("users");
    QSqlRecord aRecord = aModel.record();
    aRecord.setValue("userName", theAdminUserName);
    aRecord.setValue("password", Mercury_Utilities::encryptString(theAdminPassword));
    aRecord.setValue("canCreateDatabases", true);
    aRecord.setValue("canCreateRoles", true);
    aRecord.setValue("canLogin", true);
    aRecord.setValue("isSuperUser", true);
    aRecord.setValue("creationDate", QDateTime::currentDateTime());
    aRecord.setValue("expirationDate", Mercury_Utilities::defaultUserExpirationDate());
    if(!aModel.insertRecord(-1, aRecord))
        return false;

    // close the database connection
    aDatabase.close();

    return true;
}

// ============================================================================
/*!
 *  \brief isCluster()
 *  Check if cluster connection if bound within engine.
*/
// ============================================================================
bool Mercury_Engine::isCluster(const int theClusterId) const
{
    // retrive cluster connection name
    QString aClusterConnectionName = clusterConnectionName(theClusterId);
    // check if bound in internal map of connections
    return QSqlDatabase::contains(aClusterConnectionName);
}

// ============================================================================
/*!
 *  \brief openCluster()
 *  Open a local cluster connection.
*/
// ============================================================================
bool Mercury_Engine::openCluster(const int theClusterId,
                                 const QString &theDirectoryPath,
                                 const QString &theUserName,
                                 const QString &thePassword,
                                 const bool isReadOnly)
{
    // retrieve the cluster 'admin' database file path
    QString aFileName = clusterDatabaseFilePath(theDirectoryPath, "Admin");

    // retrive cluster connection name
    QString aClusterConnectionName = clusterConnectionName(theClusterId);

    // check if file already exists
    QFileInfo anInfo(aFileName);
    if(!anInfo.exists())
        return false;

    // try to open the database connection
    QSqlDatabase aDatabase = QSqlDatabase::addDatabase("QSQLITE", aClusterConnectionName);
    aDatabase.setDatabaseName(aFileName);
    if(!aDatabase.open())
        return false;

    // check if valid username / password
    bool aRes = true;
    if(aRes)
        QSqlDatabase::removeDatabase(aClusterConnectionName);

    return true;
}

// ============================================================================
/*!
 *  \brief versionNumber()
*/
// ============================================================================
QVersionNumber Mercury_Engine::versionNumber() const
{
    return QVersionNumber(QVariant(Mercury_VERSION_MAJOR).toInt(),
                          QVariant(Mercury_VERSION_MINOR).toInt(),
                          QVariant(Mercury_VERSION_PATCH).toInt());
}

