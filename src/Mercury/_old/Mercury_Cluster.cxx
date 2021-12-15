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
#include <Mercury_Cluster.hxx>

// Qt
#include <QDebug>
#include <QDir>

// Initialize the internal map of clusters
Mercury_MapOfCluster Mercury_Cluster::myClusters = Mercury_MapOfCluster();



// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
Mercury_Cluster::Mercury_Cluster()
    : myDriverType(Mercury_UnknownDriver)
{

}

// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
Mercury_Cluster::Mercury_Cluster(const Mercury_DriverType theDriverType,
                                 const QString& theClusterName)
    : myClusterName(theClusterName),
      myDriverType(theDriverType)
{
    // initialize the database connection
    if(theDriverType == Mercury_SQLiteDriver)
        QSqlDatabase::addDatabase("QSQLITE", connectionName());
    else if(theDriverType == Mercury_PostgresDriver)
        QSqlDatabase::addDatabase("PGSQL", connectionName());
}

// ============================================================================
/*!
    \brief Destructor
*/
// ============================================================================
Mercury_Cluster::~Mercury_Cluster()
{

}

// ============================================================================
/*!
 *  \brief addCluster()
*/
// ============================================================================
Mercury_Cluster Mercury_Cluster::addCluster(const Mercury_DriverType theDriverType,
                                            const QString &theClusterName)
{
    QString aName = theClusterName.toLower();
    // check if existing cluster
    if(myClusters.contains(aName)) {
        qWarning() << "Mercury_Cluster::addCluster()";
        qWarning() << QString("Cluster with name '%1' already exists.").arg(aName);
        qWarning() << "Connection to cluster will be closed automatically.";
        myClusters.remove(aName);
    }
    // initialize a new cluster
    Mercury_Cluster aCluster(theDriverType, aName);
    myClusters.insert(aName, aCluster);
    return aCluster;
}

// ============================================================================
/*!
 *  \brief clusterName()
*/
// ============================================================================
QString Mercury_Cluster::clusterName() const
{
    return myClusterName;
}

// ============================================================================
/*!
 *  \brief connectionName()
*/
// ============================================================================
QString Mercury_Cluster::connectionName() const
{
    QString aConnectionName = QString("%1-admin").arg(myClusterName);
    return aConnectionName.toLower();
}

// ============================================================================
/*!
 *  \brief database()
*/
// ============================================================================
QSqlDatabase Mercury_Cluster::database() const
{
    return QSqlDatabase::database(connectionName());
}

// ============================================================================
/*!
 *  \brief defaultClusterName()
*/
// ============================================================================
QString Mercury_Cluster::defaultClusterName()
{
    return QString("mercury-default-cluster");
}

// ============================================================================
/*!
 *  \brief driverType()
*/
// ============================================================================
Mercury_DriverType Mercury_Cluster::driverType() const
{
    return myDriverType;
}

// ============================================================================
/*!
 *  \brief dirPath()
*/
// ============================================================================
QString Mercury_Cluster::dirPath() const
{
    return database().databaseName();
}

// ============================================================================
/*!
 *  \brief hostName()
*/
// ============================================================================
QString Mercury_Cluster::hostName() const
{
    return database().hostName();
}

// ============================================================================
/*!
 *  \brief nbClusters()
*/
// ============================================================================
int Mercury_Cluster::nbClusters()
{
    return myClusters.size();
}

// ============================================================================
/*!
 *  \brief password()
*/
// ============================================================================
QString Mercury_Cluster::password() const
{
    return database().password();
}

// ============================================================================
/*!
 *  \brief port()
*/
// ============================================================================
int Mercury_Cluster::port() const
{
    return database().port();
}

// ============================================================================
/*!
 *  \brief setDirPath()
*/
// ============================================================================
void Mercury_Cluster::setDirPath(const QString &theDirPath)
{
    database().setDatabaseName(theDirPath);
}

// ============================================================================
/*!
 *  \brief setHostName()
*/
// ============================================================================
void Mercury_Cluster::setHostName(const QString &theHostName)
{
    database().setHostName(theHostName);
}

// ============================================================================
/*!
 *  \brief setPassword()
*/
// ============================================================================
void Mercury_Cluster::setPassword(const QString &thePassword)
{
    database().setPassword(thePassword);
}

// ============================================================================
/*!
 *  \brief setPort()
*/
// ============================================================================
void Mercury_Cluster::setPort(const int thePort)
{
    database().setPort(thePort);
}

// ============================================================================
/*!
 *  \brief setUserName()
*/
// ============================================================================
void Mercury_Cluster::setUserName(const QString &theUserName)
{
    database().setUserName(theUserName);
}

// ============================================================================
/*!
 *  \brief userName()
*/
// ============================================================================
QString Mercury_Cluster::userName() const
{
    return database().userName();
}
