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


#ifndef __Mercury_Database_hxx__
#define __Mercury_Database_hxx__

// Qt
#include <QObject>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QString>

// Mercury
#include <Mercury_DriverType.hxx>
#include <Mercury_Export.hxx>




// ============================================================================
/*!
 *  \brief Mercury_Database
*/
// ============================================================================
class Mercury_EXPORT Mercury_Database : public QObject
{
    Q_OBJECT

public:
    // constructors
    Mercury_Database();
    // destructors
    ~Mercury_Database();

public:

    QString             connectionName() const;
    Mercury_DriverType  driverType() const;
    QSqlDatabase        handle(const bool open = true) const;
    bool                isOpen() const;
    void                setConnectionName(const QString& theConnectionName);
    void                setDriverType(const Mercury_DriverType theDriverType);
    void                setFileName(const QString& theFileName);
    void                setHostName(const QString& theHostName);
    void                setPassword(const QString& thePassword);
    void                setPort(const int thePort);
    void                setUserName(const QString& theUserName);

private:

    QString             myConnectionName;
    QString             myDatabaseName;
    Mercury_DriverType  myDriverType;
    QString             myFileName;
    QString             myHostName;
    QString             myPassword;
    int                 myPort;
    QString             myUserName;

};

#endif // __Mercury_Database_hxx__
