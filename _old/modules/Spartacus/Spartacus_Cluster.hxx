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


#ifndef __Spartacus_Cluster_hxx__
#define __Spartacus_Cluster_hxx__

// Qt
#include <QObject>
#include <QSqlDatabase>

// Spartacus
#include <Spartacus_Export.hxx>


// ============================================================================
/*!
 *  \brief Spartacus_Cluster
 *  Base class implementation of a database cluster.
*/
// ============================================================================
class Spartacus_EXPORT Spartacus_Cluster : public QObject
{
    Q_OBJECT

public:
    // constructors
    Spartacus_Cluster(const QString& theDriverName,
                      QObject* theParent = nullptr);
    Spartacus_Cluster(const QString& theDriverName,
                      const QString& theConnectionName,
                      QObject* theParent = nullptr);
    // destructors
    ~Spartacus_Cluster();

public:

    virtual bool        open();

public:

    QSqlDatabase        connection() const;
    QString             connectionName() const;
    QString             driverName() const;
    bool                isOpen() const;
    QString             password() const;
    void                setPassword(const QString& thePassword);
    void                setUserName(const QString& theUserName);
    QString             userName() const;

protected:

    void                createConnection();

private:

    QString             myConnectionName;
    QString             myDriverName;

};

#endif // __Spartacus_Cluster_hxx__
