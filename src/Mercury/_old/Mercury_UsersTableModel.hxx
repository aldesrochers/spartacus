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


#ifndef __Mercury_UsersTableModel_hxx__
#define __Mercury_UsersTableModel_hxx__


// Mercury
#include <Mercury_Export.hxx>
#include <Mercury_TableModel.hxx>


// ============================================================================
/*!
 *  \brief Mercury_UsersTableModel
*/
// ============================================================================
class Mercury_UsersTableModel : public Mercury_TableModel
{
    Q_OBJECT

public:
    // constructors
    Mercury_EXPORT Mercury_UsersTableModel(const QSqlDatabase& theDatabase,
                                           QObject* theParent  = nullptr);
    // destructors
    Mercury_EXPORT ~Mercury_UsersTableModel();

public:

    virtual QVariant                    data(const QModelIndex& theIndex,
                                             int theRole = Qt::DisplayRole) const override;
    virtual bool                        setData(const QModelIndex& theIndex,
                                                const QVariant& theValue, int theRole = Qt::DisplayRole) override;

protected:

    Mercury_EXPORT QString              createStatement() const override;

};

#endif // __Mercury_UsersTableModel_hxx__
