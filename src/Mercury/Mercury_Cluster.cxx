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


// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
Mercury_Cluster::Mercury_Cluster(const int theClusterId)
    : myClusterId(theClusterId),
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
    QString aName = QString("mercury-cluster-%1").arg(myClusterId);
    return aName.toLower();
}

// ============================================================================
/*!
    \brief clusterType()
*/
// ============================================================================
QString Mercury_Cluster::clusterType() const
{
    return QString();
}

// ============================================================================
/*!
    \brief databaseConnectionName()
*/
// ============================================================================
QString Mercury_Cluster::databaseConnectionName(const QString &theDatabaseName) const
{
    QString aName = QString("%1-%2").arg(clusterName(), theDatabaseName);
    return aName.toLower();
}

// ============================================================================
/*!
    \brief isOpen()
*/
// ============================================================================
bool Mercury_Cluster::isOpen() const
{
    return myIsOpen;
}

// ============================================================================
/*!
    \brief isOpenError()
*/
// ============================================================================
bool Mercury_Cluster::isOpenError() const
{
    if(myOpenError != Mercury_NoError)
        return true;
    return false;
}

// ============================================================================
/*!
    \brief open()
*/
// ============================================================================
bool Mercury_Cluster::open()
{
    return false;
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
    \brief setNotOpen()
*/
// ============================================================================
void Mercury_Cluster::setNotOpen()
{
    myIsOpen = false;
}

// ============================================================================
/*!
    \brief setOpen()
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
    \brief setUserName()
*/
// ============================================================================
void Mercury_Cluster::setUserName(const QString &theUserName)
{
    if(!isOpen())
        myUsername = theUserName;
}

// ============================================================================
/*!
    \brief userName()
*/
// ============================================================================
QString Mercury_Cluster::userName() const
{
    return myUsername;
}
