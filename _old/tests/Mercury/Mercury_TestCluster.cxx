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

// Qt
#include <QApplication>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>

// OpenCascade
#include <UnitsAPI.hxx>
#include <UnitsAPI_SystemUnits.hxx>


// ============================================================================
/*!
 *  \brief Mercury_TestCluster
*/
// ============================================================================
int main(int argc, char** argv)
{
    QSqlDatabase aDatabase = QSqlDatabase::addDatabase("QSQLITE");
    aDatabase.setDatabaseName("test.db");
    cout << aDatabase.open() << endl;

    QSqlQuery aQuery(aDatabase);
    cout << aQuery.exec("CREATE TABLE IF NOT EXISTS shape_l (designation TEXT, d REAL)") << endl;

    cout << UnitsAPI::AnyToAny(10., "mm**1", "m**1") << endl;

}
