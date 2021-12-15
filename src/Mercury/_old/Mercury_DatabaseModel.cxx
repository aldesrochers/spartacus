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
#include <Mercury_DatabaseModel.hxx>
#include <Mercury_Utilities.hxx>

// Qt
#include <QSqlError>
#include <QSqlQuery>


// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
Mercury_DatabaseModel::Mercury_DatabaseModel(const QSqlDatabase& theDatabase,
                                             QObject* theParent)
    : QObject(theParent),
      myDatabase(theDatabase)
{

}

// ============================================================================
/*!
    \brief Destructor
*/
// ============================================================================
Mercury_DatabaseModel::~Mercury_DatabaseModel()
{

}

// ============================================================================
/*!
 *  \brief database()
*/
// ============================================================================
QSqlDatabase Mercury_DatabaseModel::database() const
{
    return myDatabase;
}

// ============================================================================
/*!
 *  \brief driverType()
*/
// ============================================================================
Mercury_DriverType Mercury_DatabaseModel::driverType() const
{
    return Mercury_Utilities::driverType(database().driverName());
}


