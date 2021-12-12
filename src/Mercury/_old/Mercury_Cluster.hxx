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
#include <QString>

// Mercury
#include <Mercury_ClusterDriver.hxx>
#include <Mercury_ClusterType.hxx>
#include <Mercury_Export.hxx>
#include <Mercury_OpenError.hxx>

// Forward definitions
class Mercury_Cluster;

// Type definitions
typedef QMap<int, Mercury_Cluster>      Mercury_MapOfCluster;



// ============================================================================
/*!
    \brief Mercury_Cluster
    Class implementation of a data cluster.
*/
// ============================================================================
class Mercury_Cluster
{

public:
    // constructors
    Mercury_EXPORT Mercury_Cluster();
    // destructors
    Mercury_EXPORT ~Mercury_Cluster();

protected:
    // constructors
    Mercury_EXPORT Mercury_Cluster(const int theClusterId,
                                   const Mercury_ClusterType theClusterType);

public:

    static Mercury_EXPORT Mercury_Cluster   addCluster(const Mercury_ClusterType theClusterType);
    static Mercury_EXPORT Mercury_Cluster   addCluster(const int theClusterId,
                                                       const Mercury_ClusterType theClusterType);
    static Mercury_EXPORT bool              isCluster(const int theClusterId);
    static Mercury_EXPORT int               nbClusters();
    static Mercury_EXPORT bool              removeCluster(const int theClusterId);

public:

    static Mercury_MapOfCluster             myClusters;

public:

    Mercury_EXPORT Mercury_ClusterDriver*   clusterDriver();
    Mercury_EXPORT int                      clusterId() const;
    Mercury_EXPORT QString                  clusterName() const;
    Mercury_EXPORT Mercury_ClusterType      clusterType() const;
    Mercury_EXPORT QString                  dirPath() const;
    Mercury_EXPORT QString                  hostName() const;
    Mercury_EXPORT bool                     isOpen() const;
    Mercury_EXPORT bool                     isValid() const;
    Mercury_EXPORT bool                     open();
    Mercury_EXPORT bool                     open(const QString& theUserName,
                                                 const QString& thePassword);
    Mercury_EXPORT Mercury_OpenError        openError() const;
    Mercury_EXPORT QString                  password() const;
    Mercury_EXPORT int                      port() const;
    Mercury_EXPORT void                     setDirPath(const QString& theDirPath);
    Mercury_EXPORT void                     setHostName(const QString& theHostName);
    Mercury_EXPORT void                     setPassword(const QString& thePassword);
    Mercury_EXPORT void                     setPort(const int thePort);
    Mercury_EXPORT void                     setUserName(const QString& theUserName);
    Mercury_EXPORT QString                  userName() const;

protected:

    void                        resetClusterDriver();
    void                        setClusterDriver(Mercury_ClusterDriver* theDriver);
    void                        setNotOpen();
    void                        setOpen();
    void                        setOpenError(const Mercury_OpenError theError);

private:

    Mercury_ClusterDriver*      myClusterDriver;
    int                         myClusterId;
    Mercury_ClusterType         myClusterType;
    QString                     myDirPath;
    QString                     myHostName;
    bool                        myIsOpen;
    Mercury_OpenError           myOpenError;
    QString                     myPassword;
    int                         myPort;
    QString                     myUserName;

};

#endif // __Mercury_Cluster_hxx__
