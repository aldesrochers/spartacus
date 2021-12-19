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
#include <Mercury_Database.hxx>


// ============================================================================
/*!
 *  \brief Constructor
*/
// ============================================================================
Mercury_Database::Mercury_Database()
{

}

// ============================================================================
/*!
 *  \brief Destructor
*/
// ============================================================================
Mercury_Database::~Mercury_Database()
{

}

// ============================================================================
/*!
 *  \brief connectionName()
*/
// ============================================================================
QString Mercury_Database::connectionName() const
{
    return myConnectionName;
}

// ============================================================================
/*!
 *  \brief driverType()
*/
// ============================================================================
Mercury_DriverType Mercury_Database::driverType() const
{
    return myDriverType;
}

// ============================================================================
/*!
 *  \brief handle()
 *  Retrieve a reference to the underlying database connection handle.
*/
// ============================================================================
QSqlDatabase Mercury_Database::handle(const bool open) const
{
    if(!QSqlDatabase::contains(myConnectionName))
        return QSqlDatabase();
    return QSqlDatabase::database(myConnectionName, open);
}

// ============================================================================
/*!
 *  \brief isOpen()
*/
// ============================================================================
bool Mercury_Database::isOpen() const
{
    if(!handle().isValid())
        return false;
    return handle().isOpen();
}

// ============================================================================
/*!
 *  \brief setConnectionName()
*/
// ============================================================================
void Mercury_Database::setConnectionName(const QString &theConnectionName)
{
    myConnectionName = theConnectionName;
}

// ============================================================================
/*!
 *  \brief setDriverType()
*/
// ============================================================================
void Mercury_Database::setDriverType(const Mercury_DriverType theDriverType)
{
    myDriverType = theDriverType;
}

// ============================================================================
/*!
 *  \brief setFileName()
*/
// ============================================================================
void Mercury_Database::setFileName(const QString &theFileName)
{
    myFileName = theFileName;
}

// ============================================================================
/*!
 *  \brief setHostName()
*/
// ============================================================================
void Mercury_Database::setHostName(const QString &theHostName)
{
    myHostName = theHostName;
}

// ============================================================================
/*!
 *  \brief setPassword()
*/
// ============================================================================
void Mercury_Database::setPassword(const QString &thePassword)
{
    myPassword = thePassword;
}

// ============================================================================
/*!
 *  \brief setPort()
*/
// ============================================================================
void Mercury_Database::setPort(const int thePort)
{
    myPort = thePort;
}

// ============================================================================
/*!
 *  \brief setUserName()
*/
// ============================================================================
void Mercury_Database::setUserName(const QString &theUserName)
{
    myUserName = theUserName;
}
