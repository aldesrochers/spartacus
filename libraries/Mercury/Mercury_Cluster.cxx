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
 *  \brief Constructor
*/
// ============================================================================
Mercury_Cluster::Mercury_Cluster(const QString& theConnectionName,
                                 QObject* theParent)
    : QObject(theParent),
      myConnectionName(theConnectionName)
{

}

// ============================================================================
/*!
 *  \brief Destructor
*/
// ============================================================================
Mercury_Cluster::~Mercury_Cluster()
{

}

// ============================================================================
/*!
 *  \brief close()
*/
// ============================================================================
bool Mercury_Cluster::close()
{
    return false;
}

// ============================================================================
/*!
 *  \brief connectionName()
*/
// ============================================================================
QString Mercury_Cluster::connectionName() const
{
    return myConnectionName;
}

// ============================================================================
/*!
 *  \brief isOpen()
*/
// ============================================================================
bool Mercury_Cluster::isOpen() const
{
    return myIsOpen;
}

// ============================================================================
/*!
 *  \brief open()
*/
// ============================================================================
bool Mercury_Cluster::open()
{
    return false;
}

// ============================================================================
/*!
 *  \brief password()
*/
// ============================================================================
QString Mercury_Cluster::password() const
{
    return myPassword;
}

// ============================================================================
/*!
 *  \brief setOpen()
*/
// ============================================================================
void Mercury_Cluster::setOpen(const bool isOpen)
{
    myIsOpen = isOpen;
}

// ============================================================================
/*!
 *  \brief setPassword()
*/
// ============================================================================
void Mercury_Cluster::setPassword(const QString &thePassword)
{
    myPassword = thePassword;
}

// ============================================================================
/*!
 *  \brief setUserName()
*/
// ============================================================================
void Mercury_Cluster::setUserName(const QString &theUserName)
{
    myUserName = theUserName;
}

// ============================================================================
/*!
 *  \brief userName()
*/
// ============================================================================
QString Mercury_Cluster::userName() const
{
    return myUserName;
}
