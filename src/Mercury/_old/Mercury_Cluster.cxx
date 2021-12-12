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


// Mercury
#include <Mercury_Cluster.hxx>

// Qt
#include <QDebug>

// Initialize internal map of clusters
Mercury_MapOfCluster Mercury_Cluster::myClusters = Mercury_MapOfCluster();


// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
Mercury_Cluster::Mercury_Cluster()
    : myClusterId(-1),
      myClusterType(Mercury_UnknownCluster),
      myIsOpen(false),
      myOpenError(Mercury_NoError)
{

}

// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
Mercury_Cluster::Mercury_Cluster(const int theClusterId,
                                 const Mercury_ClusterType theClusterType)
    : myClusterId(theClusterId),
      myClusterType(theClusterType),
      myIsOpen(false),
      myOpenError(Mercury_NoError)
{

}

// ============================================================================
/*!
    \brief Destructor
*/
// ============================================================================
Mercury_Cluster::~Mercury_Cluster()
{

}

// ============================================================================
/*!
    \brief addCluster()
    Initialize a new cluster. Since no cluster id is provided, a free cluster
    id is retrieve automatically.
*/
// ============================================================================
Mercury_Cluster Mercury_Cluster::addCluster(const Mercury_ClusterType theClusterType)
{
    // fetch a free clusterid
    int aClusterId = 0;
    while(myClusters.contains(aClusterId))
        aClusterId += 1;
    // add a new cluster using standard constructor
    return addCluster(aClusterId, theClusterType);
}

// ============================================================================
/*!
    \brief addCluster()
*/
// ============================================================================
Mercury_Cluster Mercury_Cluster::addCluster(const int theClusterId,
                                            const Mercury_ClusterType theClusterType)
{
    // check if valid id
    if(theClusterId < 0) {
        qWarning() << "Mercury_Cluster::addCluster()";
        qWarning() << "Cluster id must be greater than 0";
        qWarning() << "An invalid cluster will be returned.";
        return Mercury_Cluster();
    }
    // check if cluster connection already exists
    if(myClusters.contains(theClusterId)) {
        qWarning() << "Mercury_Cluster::addCluster()";
        qWarning() << QString("Cluster with id %1 already exists.").arg(theClusterId);
        qWarning() << "Connection will be closd automatically.";
        myClusters.remove(theClusterId);
    }
    // initialize a new cluster connection
    Mercury_Cluster aCluster(theClusterId, theClusterType);
    myClusters.insert(theClusterId, aCluster);
    return aCluster;
}

// ============================================================================
/*!
    \brief clusterId()
*/
// ============================================================================
int Mercury_Cluster::clusterId() const
{
    return myClusterId;
}

// ============================================================================
/*!
    \brief clusterName()
*/
// ============================================================================
QString Mercury_Cluster::clusterName() const
{
    QString aName = QString("mercury-cluster-%1").arg(clusterId());
    return aName.toLower();
}

// ============================================================================
/*!
    \brief clusterType()
*/
// ============================================================================
Mercury_ClusterType Mercury_Cluster::clusterType() const
{
    return myClusterType;
}

// ============================================================================
/*!
    \brief dirPath()
    Retrieve the cluster directory path. Only valid for local clusters.
*/
// ============================================================================
QString Mercury_Cluster::dirPath() const
{
    return myDirPath;
}

// ============================================================================
/*!
    \brief hostName()
*/
// ============================================================================
QString Mercury_Cluster::hostName() const
{
    return myHostName;
}

// ============================================================================
/*!
    \brief isCluster()
*/
// ============================================================================
bool Mercury_Cluster::isCluster(const int theClusterId)
{
    return myClusters.contains(theClusterId);
}

// ============================================================================
/*!
    \brief isOpen()
    Check if cluster connection is propery opened.
*/
// ============================================================================
bool Mercury_Cluster::isOpen() const
{
    return myIsOpen;
}

// ============================================================================
/*!
    \brief isValid()
    Check for valid cluster (i.e. valid type & valid id)
*/
// ============================================================================
bool Mercury_Cluster::isValid() const
{
    if(myClusterType != Mercury_UnknownCluster && myClusterId >= 0)
        return true;
    return false;
}

// ============================================================================
/*!
    \brief nbClusters()
*/
// ============================================================================
int Mercury_Cluster::nbClusters()
{
    return myClusters.size();
}

// ============================================================================
/*!
    \brief open()
*/
// ============================================================================
bool Mercury_Cluster::open()
{

}

// ============================================================================
/*!
    \brief open()
    Convenient shortcut used to open a cluster connection providing
    username and password.
*/
// ============================================================================
bool Mercury_Cluster::open(const QString &theUserName,
                           const QString &thePassword)
{
    setUserName(theUserName);
    setPassword(thePassword);
    return open();
}

// ============================================================================
/*!
    \brief openError()
    Retrieve the cluster connection open error, if any.
*/
// ============================================================================
Mercury_OpenError Mercury_Cluster::openError() const
{
    return myOpenError;
}

// ============================================================================
/*!
    \brief password()
*/
// ============================================================================
QString Mercury_Cluster::password() const
{
    return myPassword;
}

// ============================================================================
/*!
    \brief port()
*/
// ============================================================================
int Mercury_Cluster::port() const
{
    return myPort;
}

// ============================================================================
/*!
    \brief removeCluster()
    Remove a cluster connection, if exists, from internal map of clusters.
*/
// ============================================================================
bool Mercury_Cluster::removeCluster(const int theClusterId)
{
    if(myClusters.remove(theClusterId) > 0)
        return true;
    return false;
}

// ============================================================================
/*!
    \brief resetClusterDriver()
    Set the internal cluster driver to a null pointer.
*/
// ============================================================================
void Mercury_Cluster::resetClusterDriver()
{
    myClusterDriver = nullptr;
}

// ============================================================================
/*!
    \brief setClusterDriver()
    Set the internal cluster driver.
*/
// ============================================================================
void Mercury_Cluster::setClusterDriver(Mercury_ClusterDriver *theDriver)
{
    myClusterDriver = theDriver;
}

// ============================================================================
/*!
    \brief setDirPath()
    Set the cluster directory path. Only valid for local clusters.
*/
// ============================================================================
void Mercury_Cluster::setDirPath(const QString &theDirPath)
{
    if(!isOpen())
        myDirPath = theDirPath;
}

// ============================================================================
/*!
    \brief setHostName()
*/
// ============================================================================
void Mercury_Cluster::setHostName(const QString &theHostName)
{
    if(!isOpen())
        myHostName = theHostName;
}

// ============================================================================
/*!
    \brief setNotOpen()
    Set the 'not open' flag internally.
*/
// ============================================================================
void Mercury_Cluster::setNotOpen()
{
    myIsOpen = false;
}

// ============================================================================
/*!
    \brief setOpen()
    Set the 'open' flag internally.
*/
// ============================================================================
void Mercury_Cluster::setOpen()
{
    myIsOpen = true;
}

// ============================================================================
/*!
    \brief setOpenError()
*/
// ============================================================================
void Mercury_Cluster::setOpenError(const Mercury_OpenError theError)
{
    myOpenError = theError;
}

// ============================================================================
/*!
    \brief setPassword()
*/
// ============================================================================
void Mercury_Cluster::setPassword(const QString &thePassword)
{
    if(!isOpen())
        myPassword = thePassword;
}

// ============================================================================
/*!
    \brief setPort()
*/
// ============================================================================
void Mercury_Cluster::setPort(const int thePort)
{
    if(!isOpen())
        myPort = thePort;
}

// ============================================================================
/*!
    \brief setUserName()
*/
// ============================================================================
void Mercury_Cluster::setUserName(const QString &theUserName)
{
    if(!isOpen())
        myUserName = theUserName;
}

// ============================================================================
/*!
    \brief userName()
*/
// ============================================================================
QString Mercury_Cluster::userName() const
{
    return myUserName;
}

