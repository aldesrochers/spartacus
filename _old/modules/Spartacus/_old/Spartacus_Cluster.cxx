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

// Spartacus
#include <Spartacus_Cluster.hxx>
#include <Spartacus_Utilities.hxx>

// Qt
#include <QDateTime>
#include <QDebug>
#include <QDir>
#include <QFile>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlTableModel>


// ============================================================================
/*!
 *  \brief Constructor
*/
// ============================================================================
Spartacus_Cluster::Spartacus_Cluster(QObject* theParent)
    : QObject(theParent),
      myFilePrefix("Spartacus"),
      myIsOpen(false),
      myClusterType(Spartacus_UnknownCluster)
{

}

// ============================================================================
/*!
 *  \brief Destructor
*/
// ============================================================================
Spartacus_Cluster::~Spartacus_Cluster()
{

}

// ============================================================================
/*!
 *  \brief close()
*/
// ============================================================================
bool Spartacus_Cluster::close()
{
    if(!QSqlDatabase::contains(myClusterName))
        return false;
    QSqlDatabase::removeDatabase(myClusterName);
    setOpen(false);
    return true;
}

// ============================================================================
/*!
 *  \brief clusterName()
*/
// ============================================================================
QString Spartacus_Cluster::clusterName() const
{
    return myClusterName;
}

// ============================================================================
/*!
 *  \brief clusterType()
*/
// ============================================================================
Spartacus_ClusterType Spartacus_Cluster::clusterType() const
{
    return myClusterType;
}

// ============================================================================
/*!
 *  \brief createLocalAdminDatabase()
 *  Create a new 'local cluster' admin database.
*/
// ============================================================================
bool Spartacus_Cluster::createLocalAdminDatabase(const QString &theFileName)
{
    // make sure 'admin' database does not exists
    QFile aFile(theFileName);
    if(aFile.exists())
        return false;

    // make sure userName / password are properly set
    if(myUserName.isEmpty() || myPassword.isEmpty())
        return false;

    // try to open a new database connection
    QString aConnectionName = QString("spartacus-create-local-cluster");
    QSqlDatabase aDatabase = QSqlDatabase::addDatabase("QSQLITE", aConnectionName);
    aDatabase.setDatabaseName(theFileName);
    if(!aDatabase.open())
        return false;

    // initialize a query on the database
    QSqlQuery aQuery(aDatabase);

    // create table 'roles'
    QString rolesQuery = "CREATE TABLE IF NOT EXISTS users (";
    rolesQuery += "userName TEXT PRIMARY KEY, ";
    rolesQuery += "password TEXT NOT NULL, ";
    rolesQuery += "firstName TEXT, ";
    rolesQuery += "lastName TEXT, ";
    rolesQuery += "email TEXT, ";
    rolesQuery += "canCreateDatabases INTEGER NOT NULL, ";
    rolesQuery += "canCreateRoles INTEGER NOT NULL, ";
    rolesQuery += "canLogin INTEGER NOT NULL, ";
    rolesQuery += "isSuperUser INTEGER NOT NULL, ";
    rolesQuery += "creationDate TEXT NOT NULL, ";
    rolesQuery += "expirationDate TEXT NOT NULL, ";
    rolesQuery += "firstLoginDate TEXT, ";
    rolesQuery += "lastLoginDate TEXT)";
    if(!aQuery.exec(rolesQuery))
        return false;

    // create table 'databases'
    QString databasesQuery = "CREATE TABLE IF NOT EXISTS databases (";
    databasesQuery += "name TEXT PRIMARY KEY, ";
    databasesQuery += "fileName TEXT NOT NULL, ";
    databasesQuery += "description TEXT)";
    if(!aQuery.exec(databasesQuery))
        return false;

    // register 'username'/'password' as cluster superuser
    QSqlTableModel aModel(0, aDatabase);
    aModel.setTable("users");
    aModel.select();
    QSqlRecord aRecord = aModel.record();
    aRecord.setValue("userName", myUserName);
    aRecord.setValue("password", Spartacus_Utilities::encryptString(myPassword));
    aRecord.setValue("canCreateDatabases", true);
    aRecord.setValue("canCreateRoles", true);
    aRecord.setValue("canLogin", true);
    aRecord.setValue("isSuperUser", true);
    aRecord.setValue("creationDate", QDateTime::currentDateTime());
    aRecord.setValue("expirationDate", QDateTime::currentDateTime().addYears(100));
    if(!aModel.insertRecord(-1, aRecord)) {
        return false;
    }

    // close the database connection
    aDatabase.close();
    return true;
}

// ============================================================================
/*!
 *  \brief directoryPath()
*/
// ============================================================================
QString Spartacus_Cluster::directoryPath() const
{
    return myDirectoryPath;
}

// ============================================================================
/*!
 *  \brief filePrefix()
*/
// ============================================================================
QString Spartacus_Cluster::filePrefix() const
{
    return myFilePrefix;
}

// ============================================================================
/*!
 *  \brief handle()
 *  Retrives a reference to the Cluster database handle.
*/
// ============================================================================
QSqlDatabase Spartacus_Cluster::handle(const bool open) const
{
    if(!QSqlDatabase::contains(myClusterName))
        return QSqlDatabase();
    return QSqlDatabase::database(myClusterName, open);
}

// ============================================================================
/*!
 *  \brief hostName()
*/
// ============================================================================
QString Spartacus_Cluster::hostName() const
{
    return myHostName;
}

// ============================================================================
/*!
 *  \brief isOpen()
*/
// ============================================================================
bool Spartacus_Cluster::isOpen() const
{
    return myIsOpen;
}

// ============================================================================
/*!
 *  \brief isValid()
*/
// ============================================================================
bool Spartacus_Cluster::isValid() const
{
    if(myClusterType != Spartacus_UnknownCluster)
        return true;
    return false;
}

// ============================================================================
/*!
 *  \brief lastError()
*/
// ============================================================================
QSqlError Spartacus_Cluster::lastError() const
{
    return myLastError;
}

// ============================================================================
/*!
 *  \brief open()
 *  Try to open the cluster connection. If force and local cluster, attempt
 *  to create a new cluster using 'username'/'password' as superuser.
*/
// ============================================================================
bool Spartacus_Cluster::open(const bool force)
{
    if(myClusterType == Spartacus_LocalCluster)
        return openLocalCluster(force);
    else if(myClusterType == Spartacus_RemoteCluster)
        return openRemoteCluster();
    else
        return false;
}

// ============================================================================
/*!
 *  \brief openLocalCluster()
*/
// ============================================================================
bool Spartacus_Cluster::openLocalCluster(const bool force)
{
    // check if valid directory path
    QDir aDir(myDirectoryPath);
    if(!aDir.exists())
        return false;

    // build root database file name
    QString aFileName = myDirectoryPath + QDir::separator()
            + myFilePrefix + QString("_Admin.db");

    // check if file exists, else initialize new local cluster
    QFile aFile(aFileName);
    if(!aFile.exists() && force) {
        if(!createLocalAdminDatabase(aFileName))
            return false;
    }

    // initialize a connection to the database
    QSqlDatabase aDatabase = QSqlDatabase::addDatabase("QSQLITE", myClusterName);
    aDatabase.setDatabaseName(aFileName);
    if(!aDatabase.open()) {
        setLastError(aDatabase.lastError());
        return false;
    }

    // check user credentials. first check if userName exists,
    // then check if associated password match internal password
    QSqlTableModel aModel(0, aDatabase);
    aModel.setTable("users");
    aModel.setFilter(QString("userName == '%1'").arg(myUserName));
    aModel.select();
    if(aModel.rowCount() != 1) {
        aDatabase.close();
        return false;
    }
    QSqlRecord aRecord = aModel.record(0);
    QString aPassword = Spartacus_Utilities::decryptString(aRecord.value("password").toString());
    if(aPassword.compare(myPassword) != 0) {
        aDatabase.close();
        return false;
    }

    setOpen(true);
    return true;
}

// ============================================================================
/*!
 *  \brief openRemoteCluster()
*/
// ============================================================================
bool Spartacus_Cluster::openRemoteCluster()
{
    QSqlDatabase aDatabase = QSqlDatabase::addDatabase("QPSQL", myClusterName);
    aDatabase.setDatabaseName("postgres");
    aDatabase.setHostName(myHostName);
    aDatabase.setPort(myPort);
    aDatabase.setUserName(myUserName);
    aDatabase.setPassword(myPassword);
    if(!aDatabase.open()) {
        setLastError(aDatabase.lastError());
        return false;
    }

    setOpen(true);
    return true;
}

// ============================================================================
/*!
 *  \brief password()
*/
// ============================================================================
QString Spartacus_Cluster::password() const
{
    return myPassword;
}

// ============================================================================
/*!
 *  \brief port()
*/
// ============================================================================
int Spartacus_Cluster::port() const
{
    return myPort;
}

// ============================================================================
/*!
 *  \brief setClusterName()
*/
// ============================================================================
void Spartacus_Cluster::setClusterName(const QString &theClusterName)
{
    if(!isOpen())
        myClusterName = theClusterName;
}

// ============================================================================
/*!
 *  \brief setClusterType()
*/
// ============================================================================
void Spartacus_Cluster::setClusterType(const Spartacus_ClusterType theClusterType)
{
    if(!isOpen())
        myClusterType = theClusterType;
}

// ============================================================================
/*!
 *  \brief setDirectoryPath()
*/
// ============================================================================
void Spartacus_Cluster::setDirectoryPath(const QString &theDirectoryPath)
{
    if(!isOpen())
        myDirectoryPath = theDirectoryPath;
}

// ============================================================================
/*!
 *  \brief setFilePrefix()
 *  Define the prefix used for files in Cluster. e.g. <Prefix>_File.xx
*/
// ============================================================================
void Spartacus_Cluster::setFilePrefix(const QString &theFilePrefix)
{
    if(!isOpen())
        myFilePrefix = theFilePrefix;
}

// ============================================================================
/*!
 *  \brief setHostName()
*/
// ============================================================================
void Spartacus_Cluster::setHostName(const QString &theHostName)
{
    if(!isOpen())
        myHostName = theHostName;
}

// ============================================================================
/*!
 *  \brief setLastError()
*/
// ============================================================================
void Spartacus_Cluster::setLastError(const QSqlError &theError)
{
    myLastError = theError;
}

// ============================================================================
/*!
 *  \brief setOpen()
 *  Set the open flag internally.
*/
// ============================================================================
void Spartacus_Cluster::setOpen(const bool isOpen)
{
    myIsOpen = isOpen;
}

// ============================================================================
/*!
 *  \brief setPassword()
*/
// ============================================================================
void Spartacus_Cluster::setPassword(const QString &thePassword)
{
    if(!isOpen())
        myPassword = thePassword;
}

// ============================================================================
/*!
 *  \brief setPort()
*/
// ============================================================================
void Spartacus_Cluster::setPort(const int thePort)
{
    if(!isOpen())
        myPort = thePort;
}

// ============================================================================
/*!
 *  \brief setUserName()
*/
// ============================================================================
void Spartacus_Cluster::setUserName(const QString &theUserName)
{
    if(!isOpen())
        myUserName = theUserName;
}

// ============================================================================
/*!
 *  \brief userName()
*/
// ============================================================================
QString Spartacus_Cluster::userName() const
{
    return myUserName;
}
