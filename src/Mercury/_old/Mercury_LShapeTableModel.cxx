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
#include <Mercury_LShapeTableModel.hxx>


// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
Mercury_LShapeTableModel::Mercury_LShapeTableModel(const QSqlDatabase& theDatabase,
                                                   QObject* theParent)
    : Mercury_TableModel(theDatabase, theParent)
{

}

// ============================================================================
/*!
    \brief Destructor
*/
// ============================================================================
Mercury_LShapeTableModel::~Mercury_LShapeTableModel()
{

}

// ============================================================================
/*!
 *  \brief createStatement()
*/
// ============================================================================
QString Mercury_LShapeTableModel::createStatement() const
{
    QString aString = QString("CREATE TABLE %1 (").arg(tableName());
    aString += "designation TEXT PRIMARY KEY, ";
    aString += "area REAL NOT NULL, ";
    aString += "Ix REAL NOT NULL, ";
    aString += "Sx REAL NOT NULL, ";
    aString += "rx REAL NOT NULL, ";
    aString += "y REAL NOT NULL, ";
    aString += "Iy REAL NOT NULL, ";
    aString += "Sy REAL NOT NULL, ";
    aString += "ry REAL NOT NULL, ";
    aString += "x REAL NOT NULL, ";
    aString += "J REAL NOT NULL, ";
    aString += "Cw REAL NOT NULL, ";
    aString += "mass REAL NOT NULL, ";
    aString += "d REAL NOT NULL, ";
    aString += "b REAL NOT NULL, ";
    aString += "t REAL NOT NULL, ";
    aString += "rxx REAL NOT NULL, ";
    aString += "y0 REAL NOT NULL, ";
    aString += "ryy REAL NOT NULL, ";
    aString += "x0 REAL NOT NULL, ";
    aString += "r0 REAL NOT NULL, ";
    aString += "omega REAL NOT NULL, ";
    aString += "alpha REAL NOT NULL)";
    return aString;
}
