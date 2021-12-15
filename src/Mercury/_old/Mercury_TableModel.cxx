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
#include <Mercury_TableModel.hxx>
#include <Mercury_Utilities.hxx>

// Qt
#include <QSqlError>
#include <QSqlQuery>


// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
Mercury_TableModel::Mercury_TableModel(const QSqlDatabase& theDatabase,
                                       QObject* theParent)
    : QSqlTableModel(theParent, theDatabase)
{

}

// ============================================================================
/*!
    \brief Destructor
*/
// ============================================================================
Mercury_TableModel::~Mercury_TableModel()
{

}

// ============================================================================
/*!
 *  \brief create()
 *  Create the table within database using the specified 'create statement'.
*/
// ============================================================================
bool Mercury_TableModel::create()
{
    // check if non empty create statement
    if(createStatement().isEmpty())
        return false;
    // executable 'create statement'
    QSqlQuery aQuery(database());
    if(!aQuery.exec(createStatement())) {
        setLastError(aQuery.lastError());
        return false;
    }
    return true;
}

// ============================================================================
/*!
 *  \brief driverType()
*/
// ============================================================================
Mercury_DriverType Mercury_TableModel::driverType() const
{
    return Mercury_Utilities::driverType(database().driverName());
}

// ============================================================================
/*!
 *  \brief drop()
*/
// ============================================================================
bool Mercury_TableModel::drop()
{
    QSqlQuery aQuery(database());
    if(!aQuery.exec(dropStatement())) {
        setLastError(aQuery.lastError());
        return false;
    }
    return true;
}

// ============================================================================
/*!
 *  \brief dropStatement()
*/
// ============================================================================
QString Mercury_TableModel::dropStatement() const
{
    QString aString = QString("DROP TABLE IF EXISTS %1").arg(tableName());
    return aString;
}

// ============================================================================
/*!
 *  \brief exists()
 *  Check if table exists in database.
*/
// ============================================================================
bool Mercury_TableModel::exists() const
{
    return database().tables().contains(tableName());
}


