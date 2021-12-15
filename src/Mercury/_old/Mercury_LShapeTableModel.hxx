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


#ifndef __Mercury_LShapeTableModel_hxx__
#define __Mercury_LShapeTableModel_hxx__


// Mercury
#include <Mercury_Export.hxx>
#include <Mercury_TableModel.hxx>


// ============================================================================
/*!
 *  \brief Mercury_LShapeTableModel
*/
// ============================================================================
class Mercury_LShapeTableModel : public Mercury_TableModel
{
    Q_OBJECT

public:
    // constructors
    Mercury_EXPORT Mercury_LShapeTableModel(const QSqlDatabase& theDatabase,
                                           QObject* theParent  = nullptr);
    // destructors
    Mercury_EXPORT ~Mercury_LShapeTableModel();

protected:

    Mercury_EXPORT QString              createStatement() const override;

};

#endif // __Mercury_LShapeTableModel_hxx__
