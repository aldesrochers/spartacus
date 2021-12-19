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

// Spartacus
#include <Spartacus_ILocalCluster.hxx>

// Qt
#include <QSqlQuery>


// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
Spartacus_ILocalCluster::Spartacus_ILocalCluster(const QSqlDatabase& theDatabase)
    : Spartacus_ICluster(theDatabase)
{

}

// ============================================================================
/*!
    \brief Destructor
*/
// ============================================================================
Spartacus_ILocalCluster::~Spartacus_ILocalCluster()
{

}

// ============================================================================
/*!
    \brief createAllTables()
*/
// ============================================================================
bool Spartacus_ILocalCluster::createAllTables()
{
    int nbErrors = 0;
    nbErrors += createTableDatabases();
    nbErrors += createTableRoles();
    nbErrors += createTableUsers();
    if(nbErrors <= 0)
        return true;
    return false;
}

// ============================================================================
/*!
    \brief createTableDatabase()
*/
// ============================================================================
bool Spartacus_ILocalCluster::createTableDatabases()
{
    QString aString = QString("CREATE TABLE IF NOT EXISTS databases (");
    aString += "name TEXT PRIMARY KEY, ";
    aString += "fileName TEXT NOT NULL, ";
    aString += "description TEXT)";
    QSqlQuery aQuery(database());
    if(!aQuery.exec(aString)) {
        addError(aQuery.lastError());
        return false;
    }
    return true;
}

// ============================================================================
/*!
    \brief createTableRoles()
*/
// ============================================================================
bool Spartacus_ILocalCluster::createTableRoles()
{
    QString aString = QString("CREATE TABLE IF NOT EXISTS roles (");
    aString += "userName TEXT PRIMARY KEY, ";
    aString += "password TEXT NOT NULL, ";
    aString += "canLogin INTEGER NOT NULL, ";
    aString += "canCreateDatabase INTEGER NOT NULL, ";
    aString += "canCreateRole INTEGER NOT NULL, ";
    aString += "isSuperUser INTEGER NOT NULL)";
    QSqlQuery aQuery(database());
    if(!aQuery.exec(aString)) {
        addError(aQuery.lastError());
        return false;
    }
    return true;
}

// ============================================================================
/*!
    \brief createTableUsers()
*/
// ============================================================================
bool Spartacus_ILocalCluster::createTableUsers()
{
    QString aString = QString("CREATE TABLE IF NOT EXISTS users (");
    aString += "userName TEXT PRIMARY KEY, ";
    aString += "firstName TEXT, ";
    aString += "lastName TEXT, ";
    aString += "email TEXT, ";
    aString += "creationDate TEXT NOT NULL, ";
    aString += "firstLogin TEXT, ";
    aString += "lastLogin TEXT)";
    QSqlQuery aQuery(database());
    if(!aQuery.exec(aString)) {
        addError(aQuery.lastError());
        return false;
    }
    return true;
}
