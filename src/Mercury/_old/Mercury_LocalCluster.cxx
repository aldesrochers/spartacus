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


// Mercury
#include <Mercury_LocalCluster.hxx>

// Qt
#include <QDebug>
#include <QDir>


// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
Mercury_LocalCluster::Mercury_LocalCluster(const int theClusterId)
    : Mercury_Cluster(theClusterId),
      myFileExtension("db"),
      myFilePrefix("Mercury")
{

}

// ============================================================================
/*!
    \brief Destructor
*/
// ============================================================================
Mercury_LocalCluster::~Mercury_LocalCluster()
{

}

// ============================================================================
/*!
    \brief clusterType()
*/
// ============================================================================
QString Mercury_LocalCluster::clusterType() const
{
    return QString("local");
}

// ============================================================================
/*!
    \brief databaseFileExtension()
*/
// ============================================================================
QString Mercury_LocalCluster::databaseFileExtension() const
{
    return myFileExtension;
}

// ============================================================================
/*!
    \brief databaseFileName()
*/
// ============================================================================
QString Mercury_LocalCluster::databaseFileName(const QString &theDatabaseName)
{
    QString aFileName = myDirectoryPath + QDir::separator()
            + myFilePrefix + QString("_") + theDatabaseName
            + QString(".") + myFileExtension;
    return aFileName;
}

// ============================================================================
/*!
    \brief databaseFilePrefix()
*/
// ============================================================================
QString Mercury_LocalCluster::databaseFilePrefix() const
{
    return myFilePrefix;
}

// ============================================================================
/*!
    \brief directoryPath()
*/
// ============================================================================
QString Mercury_LocalCluster::directoryPath() const
{
    return myDirectoryPath;
}

// ============================================================================
/*!
    \brief open()
*/
// ============================================================================
bool Mercury_LocalCluster::open()
{
    // check if valid directory path
    QDir aDir(myDirectoryPath);
    if(!aDir.exists()) {
        setOpenError(Mercury_InexistingDirectoryPathError);
        return false;
    }
    // check if valid username
    if(myUsername.isEmpty()) {
        setOpenError(Mercury_EmptyUserNameError);
        return false;
    }
    // check if valid password
    if(myPassword.isEmpty()) {
        setOpenError(Mercury_EmptyPasswordError);
        return false;
    }
    // get connection name for 'admin' database
    QString aConnectionName = databaseConnectionName("Admin");
    // get filename for 'admin' database
    QString aFileName = databaseFileName("Admin");
    // create database connection
    QSqlDatabase aDatabase = QSqlDatabase::addDatabase("QSQLITE", aConnectionName);
    aDatabase.setDatabaseName(aFileName);
    if(!aDatabase.open()) {
        setOpenError(Mercury_ConnectionError);
        return false;
    }

    return true;
}

// ============================================================================
/*!
    \brief setDatabaseFileExtension()
*/
// ============================================================================
void Mercury_LocalCluster::setDatabaseFileExtension(const QString &theFileExtension)
{
    if(!isOpen())
        myFileExtension = theFileExtension;
}

// ============================================================================
/*!
    \brief setDatabaseFilePrefix()
*/
// ============================================================================
void Mercury_LocalCluster::setDatabaseFilePrefix(const QString &theFilePrefix)
{
    if(!isOpen())
        myFilePrefix = theFilePrefix;
}

// ============================================================================
/*!
    \brief setDirectoryPath()
*/
// ============================================================================
void Mercury_LocalCluster::setDirectoryPath(const QString &thedirectoryPath)
{
    if(!isOpen())
        myDirectoryPath = thedirectoryPath;
}

