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
#include <QMap>
#include <QSqlDatabase>
#include <QString>

// Mercury
#include <Mercury_DriverType.hxx>
#include <Mercury_Export.hxx>

// Forward declarations
class Mercury_Cluster;

// Type definitions
typedef QMap<QString, Mercury_Cluster>      Mercury_MapOfCluster;



// ============================================================================
/*!
 *  \brief Mercury_Cluster
*/
// ============================================================================
class Mercury_Cluster
{

public:
    // constructors
    Mercury_EXPORT Mercury_Cluster();
    Mercury_EXPORT Mercury_Cluster(const Mercury_DriverType theDriverType,
                                   const QString& theClusterName);
    // destructors
    Mercury_EXPORT ~Mercury_Cluster();

public:

    static Mercury_EXPORT Mercury_Cluster   addCluster(const Mercury_DriverType theDriverType,
                                                       const QString& theClusterName = defaultClusterName());
    static Mercury_EXPORT QString           defaultClusterName();
    static Mercury_EXPORT int               nbClusters();

public:

    static Mercury_MapOfCluster             myClusters;

public:

    Mercury_EXPORT QString              clusterName() const;
    Mercury_EXPORT Mercury_DriverType   driverType() const;
    Mercury_EXPORT QString              dirPath() const;
    Mercury_EXPORT QString              hostName() const;
    Mercury_EXPORT QString              password() const;
    Mercury_EXPORT int                  port() const;
    Mercury_EXPORT void                 setDirPath(const QString& theDirPath);
    Mercury_EXPORT void                 setHostName(const QString& theHostName);
    Mercury_EXPORT void                 setPassword(const QString& thePassword);
    Mercury_EXPORT void                 setPort(const int thePort);
    Mercury_EXPORT void                 setUserName(const QString& theUserName);
    Mercury_EXPORT QString              userName() const;

protected:

    QString                 connectionName() const;
    QSqlDatabase            database() const;

private:

    QString                 myClusterName;
    Mercury_DriverType      myDriverType;

};

#endif // __Mercury_Cluster_hxx__
