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


#ifndef __Mercury_TableModel_hxx__
#define __Mercury_TableModel_hxx__

// Qt
#include <QStringList>
#include <QSqlDatabase>
#include <QSqlTableModel>

// Mercury
#include <Mercury_DriverType.hxx>
#include <Mercury_Export.hxx>


// ============================================================================
/*!
 *  \brief Mercury_TableModel
 *  Base class implementation of a table model.
*/
// ============================================================================
class Mercury_TableModel : public QSqlTableModel
{
    Q_OBJECT

public:
    // constructors
    Mercury_EXPORT Mercury_TableModel(const QSqlDatabase& theDatabase,
                                      QObject* theParent  = nullptr);
    // destructors
    Mercury_EXPORT ~Mercury_TableModel();

protected:

    virtual Mercury_EXPORT QString      createStatement() const = 0;
    virtual Mercury_EXPORT QString      dropStatement() const;

public:

    Mercury_EXPORT Mercury_DriverType   driverType() const;
    Mercury_EXPORT bool                 exists() const;

public slots:

    Mercury_EXPORT virtual bool         create();
    Mercury_EXPORT virtual bool         drop();

};

#endif // __Mercury_TableModel_hxx__
