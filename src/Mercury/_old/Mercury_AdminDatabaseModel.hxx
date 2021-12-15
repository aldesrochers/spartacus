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


#ifndef __Mercury_AdminDatabaseModel_hxx__
#define __Mercury_AdminDatabaseModel_hxx__

// Mercury
#include <Mercury_DatabaseModel.hxx>
#include <Mercury_Export.hxx>
#include <Mercury_UsersTableModel.hxx>


// ============================================================================
/*!
 *  \brief Mercury_AdminDatabaseModel
*/
// ============================================================================
class Mercury_AdminDatabaseModel : public Mercury_DatabaseModel
{
    Q_OBJECT

public:
    // constructors
    Mercury_EXPORT Mercury_AdminDatabaseModel(const QSqlDatabase& theDatabase,
                                              QObject* theParent  = nullptr);
    // destructors
    Mercury_EXPORT ~Mercury_AdminDatabaseModel();

public:

    Mercury_EXPORT Mercury_UsersTableModel*     usersTableModel();

private:

    Mercury_UsersTableModel*        myUsersTableModel;

};

#endif // __Mercury_AdminDatabaseModel_hxx__
