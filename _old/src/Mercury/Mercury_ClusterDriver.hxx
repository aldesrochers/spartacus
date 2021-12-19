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


#ifndef __Mercury_ClusterDriver_hxx__
#define __Mercury_ClusterDriver_hxx__

// Qt
#include <QObject>
#include <QSqlDatabase>

// Mercury
#include <Mercury_Export.hxx>


// ============================================================================
/*!
 *  \brief Mercury_ClusterDriver
 *  Base class implementation of a cluster driver.
*/
// ============================================================================
class Mercury_EXPORT Mercury_ClusterDriver : public QObject
{
    Q_OBJECT

public:
    // constructors
    Mercury_ClusterDriver(QObject* theParent = nullptr);
    // destructors
    ~Mercury_ClusterDriver();

public:

    QString             connectionName() const;
    QString             password() const;
    QString             userName() const;
    void                setConnectionName(const QString& theConnectionName);
    void                setPassword(const QString& thePassword);
    void                setUserName(const QString& theUserName);

private:

    QString             myConnectionName;
    QString             myPassword;
    QString             myUserName;

};

#endif // __Mercury_ClusterDriver_hxx__
