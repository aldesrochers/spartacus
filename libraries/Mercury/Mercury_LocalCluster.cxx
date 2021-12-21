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
#include <Mercury_LocalCluster.hxx>

// Qt
#include <QDebug>
#include <QDir>
#include <QSqlDatabase>


// ============================================================================
/*!
 *  \brief Constructor
*/
// ============================================================================
Mercury_LocalCluster::Mercury_LocalCluster(const QString& theConnectionName,
                                           QObject* theParent)
    : Mercury_Cluster(theConnectionName, theParent)
{

}

// ============================================================================
/*!
 *  \brief Destructor
*/
// ============================================================================
Mercury_LocalCluster::~Mercury_LocalCluster()
{

}

// ============================================================================
/*!
 *  \brief addCluster()
*/
// ============================================================================
Mercury_LocalCluster* Mercury_LocalCluster::addCluster(const QString& theConnectionName)
{
    cout << "OK" << endl;
    cout << QSqlDatabase::connectionNames().size() << endl;
    QSqlDatabase::removeDatabase("mercury-local-cluster");
    cout << QSqlDatabase::connectionNames().size() << endl;
    cout << "OK" << endl;
}

// ============================================================================
/*!
 *  \brief clusterType()
*/
// ============================================================================
QString Mercury_LocalCluster::clusterType() const
{
    return QString("LOCAL");
}

// ============================================================================
/*!
 *  \brief directoryPath()
*/
// ============================================================================
QString Mercury_LocalCluster::directoryPath() const
{
    return myDirectoryPath;
}

// ============================================================================
/*!
 *  \brief driverName()
*/
// ============================================================================
QString Mercury_LocalCluster::driverName() const
{
    return QString("QSQLITE");
}

// ============================================================================
/*!
 *  \brief filePath()
*/
// ============================================================================
QString Mercury_LocalCluster::filePath() const
{
    QString aFilePath = directoryPath() + QDir::separator()
            + QString("Mercury_Admin.db");
    return aFilePath;
}

// ============================================================================
/*!
 *  \brief open()
*/
// ============================================================================
bool Mercury_LocalCluster::open()
{
    QSqlDatabase aDatabase = QSqlDatabase::addDatabase(driverName(), connectionName());
    aDatabase.setDatabaseName(filePath());
    if(!aDatabase.open())
        return false;

    return true;
}

// ============================================================================
/*!
 *  \brief setDirectoryPath()
*/
// ============================================================================
void Mercury_LocalCluster::setDirectoryPath(const QString &theDirectoryPath)
{
    myDirectoryPath = theDirectoryPath;
}
