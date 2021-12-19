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
#include <Mercury_DatabaseDriver.hxx>


// ============================================================================
/*!
 *  \brief Constructor
*/
// ============================================================================
Mercury_DatabaseDriver::Mercury_DatabaseDriver(QObject* theParent)
    : QObject(theParent)
{

}

// ============================================================================
/*!
 *  \brief Destructor
*/
// ============================================================================
Mercury_DatabaseDriver::~Mercury_DatabaseDriver()
{

}

// ============================================================================
/*!
 *  \brief connectionName()
*/
// ============================================================================
QString Mercury_DatabaseDriver::connectionName() const
{
    return myConnectionName;
}

// ============================================================================
/*!
 *  \brief driverName()
*/
// ============================================================================
QString Mercury_DatabaseDriver::driverName() const
{
    return myDriverName;
}

// ============================================================================
/*!
 *  \brief handle()
*/
// ============================================================================
QSqlDatabase Mercury_DatabaseDriver::handle(const bool open) const
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
bool Mercury_DatabaseDriver::isOpen() const
{
    QSqlDatabase aDatabase = handle();
    if(!aDatabase.isValid())
        return false;
    return aDatabase.isOpen();
}

// ============================================================================
/*!
 *  \brief setConnectionName()
*/
// ============================================================================
void Mercury_DatabaseDriver::setConnectionName(const QString &theConnectionName)
{
    myConnectionName = theConnectionName;
}

// ============================================================================
/*!
 *  \brief setDriverName()
*/
// ============================================================================
void Mercury_DatabaseDriver::setDriverName(const QString &theDriverName)
{
    myDriverName = theDriverName;
}
