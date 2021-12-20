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
#include <Spartacus_LocalCluster.hxx>

// Qt
#include <QDir>
#include <QFile>


// ============================================================================
/*!
 *  \brief Constructor
*/
// ============================================================================
Spartacus_LocalCluster::Spartacus_LocalCluster(QObject* theParent)
    : Spartacus_Cluster("QSQLITE", theParent)
{

}

// ============================================================================
/*!
 *  \brief Destructor
*/
// ============================================================================
Spartacus_LocalCluster::~Spartacus_LocalCluster()
{

}

// ============================================================================
/*!
 *  \brief dirPath()
*/
// ============================================================================
QString Spartacus_LocalCluster::dirPath() const
{
    return myDirPath;
}

// ============================================================================
/*!
 *  \brief isReadOnly()
*/
// ============================================================================
bool Spartacus_LocalCluster::isReadOnly() const
{
    return myIsReadOnly;
}

// ============================================================================
/*!
 *  \brief open()
*/
// ============================================================================
bool Spartacus_LocalCluster::open()
{
    // construct database name
    QString aFilePath = myDirPath + QDir::separator()
            + QString("Spartacus_Admin.db");
    cout << connection().isOpen() << endl;
    cout << connection().isValid() << endl;
    cout << connection().isOpenError() << endl;
    cout << connection().databaseName().toStdString() << endl;
    // check if file exists
    bool isNew = false;
    QFile aFile(aFilePath);
    if(!aFile.exists())
        isNew = true;

    // setup database connection, open
    connection().setDatabaseName(aFilePath);
    if(isReadOnly())
        connection().setConnectOptions("QSQLITE_OPEN_READONLY=1");
    if(!connection().open())
        return false;

    // if new, register current user as superuser

    return true;
}

// ============================================================================
/*!
 *  \brief setDirPath()
*/
// ============================================================================
void Spartacus_LocalCluster::setDirPath(const QString &theDirPath)
{
    myDirPath = theDirPath;
}

// ============================================================================
/*!
 *  \brief setReadOnly()
*/
// ============================================================================
void Spartacus_LocalCluster::setReadOnly(const bool isReadOnly)
{
    myIsReadOnly = isReadOnly;
}

