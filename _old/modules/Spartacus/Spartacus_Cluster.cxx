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


// ============================================================================
/*!
 *  \brief Constructor
*/
// ============================================================================
Spartacus_Cluster::Spartacus_Cluster(const QString& theDriverName,
                                     QObject* theParent)
    : QObject(theParent),
      myConnectionName("spartacus-default-cluster"),
      myDriverName(theDriverName)
{
    // initialize a database connection
    createConnection();
}

// ============================================================================
/*!
 *  \brief Constructor
*/
// ============================================================================
Spartacus_Cluster::Spartacus_Cluster(const QString& theDriverName,
                                     const QString& theConnectionName,
                                     QObject* theParent)
    : QObject(theParent),
      myConnectionName(theConnectionName),
      myDriverName(theDriverName)
{
    // initialize a database connection
    createConnection();
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
 *  \brief connection()
 *  Retrieve a reference to the database connection.
*/
// ============================================================================
QSqlDatabase Spartacus_Cluster::connection() const
{
    return QSqlDatabase::database(myConnectionName, false);
}

// ============================================================================
/*!
 *  \brief connectionName()
*/
// ============================================================================
QString Spartacus_Cluster::connectionName() const
{
    return myConnectionName;
}

// ============================================================================
/*!
 *  \brief createConnection()
 *  Create a new connection to a cluster root database.
*/
// ============================================================================
void Spartacus_Cluster::createConnection()
{
    QSqlDatabase::addDatabase(driverName(), myConnectionName);
}

// ============================================================================
/*!
 *  \brief driverName()
*/
// ============================================================================
QString Spartacus_Cluster::driverName() const
{
    return myDriverName;
}

// ============================================================================
/*!
 *  \brief isOpen()
*/
// ============================================================================
bool Spartacus_Cluster::isOpen() const
{
    return connection().isOpen();
}

// ============================================================================
/*!
 *  \brief open()
 *  Default implementation, return false.
*/
// ============================================================================
bool Spartacus_Cluster::open()
{
    return false;
}

// ============================================================================
/*!
 *  \brief password()
*/
// ============================================================================
QString Spartacus_Cluster::password() const
{
    return connection().password();
}

// ============================================================================
/*!
 *  \brief setPassword()
*/
// ============================================================================
void Spartacus_Cluster::setPassword(const QString &thePassword)
{
    connection().setPassword(thePassword);
}

// ============================================================================
/*!
 *  \brief setUserName()
*/
// ============================================================================
void Spartacus_Cluster::setUserName(const QString& theUserName)
{
    connection().setUserName(theUserName);
}

// ============================================================================
/*!
 *  \brief userName()
*/
// ============================================================================
QString Spartacus_Cluster::userName() const
{
    return connection().userName();
}
