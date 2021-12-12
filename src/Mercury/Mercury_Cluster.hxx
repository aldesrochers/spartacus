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


#ifndef __Mercury_Cluster_hxx__
#define __Mercury_Cluster_hxx__

// Qt
#include <QSqlDatabase>
#include <QString>

// Mercury
#include <Mercury_Export.hxx>
#include <Mercury_OpenError.hxx>


// ============================================================================
/*!
    \brief Mercury_Cluster
    Base class implementation of a cluster connection.
*/
// ============================================================================
class Mercury_Cluster
{

public:
    // constructors
    Mercury_EXPORT Mercury_Cluster(const int theClusterId);
    // destructors
    Mercury_EXPORT ~Mercury_Cluster();

public:

    virtual Mercury_EXPORT QString      clusterType() const;
    virtual Mercury_EXPORT bool         open();

public:

    Mercury_EXPORT int          clusterId() const;
    Mercury_EXPORT QString      clusterName() const;
    Mercury_EXPORT bool         isOpen() const;
    Mercury_EXPORT bool         isOpenError() const;
    Mercury_EXPORT QString      password() const;
    Mercury_EXPORT void         setPassword(const QString& thePassword);
    Mercury_EXPORT void         setUserName(const QString& theUserName);
    Mercury_EXPORT QString      userName() const;

protected:

    QString                     databaseConnectionName(const QString& theDatabaseName) const;
    void                        setNotOpen();
    void                        setOpen();
    void                        setOpenError(const Mercury_OpenError theError);

protected:

    int                 myClusterId;
    bool                myIsOpen;
    Mercury_OpenError   myOpenError;
    QString             myPassword;
    QString             myUsername;

};

#endif // __Mercury_Cluster_hxx__
