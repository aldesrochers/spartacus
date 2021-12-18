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


#ifndef __Mercury_DatabaseDriver_hxx__
#define __Mercury_DatabaseDriver_hxx__

// Qt
#include <QObject>
#include <QSqlDatabase>

// Mercury
#include <Mercury_Export.hxx>




// ============================================================================
/*!
 *  \brief Mercury_DatabaseDriver
*/
// ============================================================================
class Mercury_EXPORT Mercury_DatabaseDriver : public QObject
{

public:
    // constructors
    Mercury_DatabaseDriver(QObject* theParent = nullptr);
    // destructors
    ~Mercury_DatabaseDriver();

public:

    QString             connectionName() const;
    QString             driverName() const;
    QSqlDatabase        handle(const bool open = true) const;
    bool                isOpen() const;
    void                setConnectionName(const QString& theConnectionName);
    void                setDriverName(const QString& theDriverName);

private:

    QString             myConnectionName;
    QString             myDriverName;

};

#endif // __Mercury_DatabaseDriver_hxx__
