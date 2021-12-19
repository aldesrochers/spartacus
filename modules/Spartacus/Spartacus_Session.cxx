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


// Spartacus
#include <Spartacus_Session.hxx>


// ============================================================================
/*!
 *  \brief Constructor
*/
// ============================================================================
Spartacus_Session::Spartacus_Session(QObject* theParent)
    : QObject(theParent),
      myIsOpen(false),
      mySessionType(Spartacus_UnknownSession)
{

}

// ============================================================================
/*!
 *  \brief Constructor
*/
// ============================================================================
Spartacus_Session::Spartacus_Session(const QString& theSessionName,
                                     QObject* theParent)
    : QObject(theParent),
      myIsOpen(false),
      mySessionName(theSessionName),
      mySessionType(Spartacus_UnknownSession)
{

}

// ============================================================================
/*!
 *  \brief Destructor
*/
// ============================================================================
Spartacus_Session::~Spartacus_Session()
{

}

// ============================================================================
/*!
 *  \brief close()
*/
// ============================================================================
bool Spartacus_Session::close()
{
    if(!handle().isOpen())
        return false;
    handle().close();
    return true;
}

// ============================================================================
/*!
 *  \brief directoryPath()
*/
// ============================================================================
QString Spartacus_Session::directoryPath() const
{
    return myDirectoryPath;
}

// ============================================================================
/*!
 *  \brief handle()
 *  Retrives a reference to the session database handle.
*/
// ============================================================================
QSqlDatabase Spartacus_Session::handle(const bool open) const
{
    if(!QSqlDatabase::contains(mySessionName))
        return QSqlDatabase();
    return QSqlDatabase::database(mySessionName, open);
}

// ============================================================================
/*!
 *  \brief hostName()
*/
// ============================================================================
QString Spartacus_Session::hostName() const
{
    return myHostName;
}

// ============================================================================
/*!
 *  \brief isOpen()
*/
// ============================================================================
bool Spartacus_Session::isOpen() const
{
    return myIsOpen;
}

// ============================================================================
/*!
 *  \brief isValid()
*/
// ============================================================================
bool Spartacus_Session::isValid() const
{
    if(mySessionType != Spartacus_UnknownSession)
        return true;
    return false;
}

// ============================================================================
/*!
 *  \brief password()
*/
// ============================================================================
QString Spartacus_Session::password() const
{
    return myPassword;
}

// ============================================================================
/*!
 *  \brief port()
*/
// ============================================================================
int Spartacus_Session::port() const
{
    return myPort;
}

// ============================================================================
/*!
 *  \brief sessionName()
*/
// ============================================================================
QString Spartacus_Session::sessionName() const
{
    return mySessionName;
}

// ============================================================================
/*!
 *  \brief sessionType()
*/
// ============================================================================
Spartacus_SessionType Spartacus_Session::sessionType() const
{
    return mySessionType;
}

// ============================================================================
/*!
 *  \brief setDirectoryPath()
*/
// ============================================================================
void Spartacus_Session::setDirectoryPath(const QString &theDirectoryPath)
{
    if(!isOpen())
        myDirectoryPath = theDirectoryPath;
}

// ============================================================================
/*!
 *  \brief setHostName()
*/
// ============================================================================
void Spartacus_Session::setHostName(const QString &theHostName)
{
    if(!isOpen())
        myHostName = theHostName;
}

// ============================================================================
/*!
 *  \brief setPassword()
*/
// ============================================================================
void Spartacus_Session::setPassword(const QString &thePassword)
{
    if(!isOpen())
        myPassword = thePassword;
}

// ============================================================================
/*!
 *  \brief setPort()
*/
// ============================================================================
void Spartacus_Session::setPort(const int thePort)
{
    if(!isOpen())
        myPort = thePort;
}

// ============================================================================
/*!
 *  \brief setSessionName()
*/
// ============================================================================
void Spartacus_Session::setSessionName(const QString &theSessionName)
{
    if(!isOpen())
        mySessionName = theSessionName;
}

// ============================================================================
/*!
 *  \brief setSessionType()
*/
// ============================================================================
void Spartacus_Session::setSessionType(const Spartacus_SessionType theSessionType)
{
    if(!isOpen())
        mySessionType = theSessionType;
}

// ============================================================================
/*!
 *  \brief setUserName()
*/
// ============================================================================
void Spartacus_Session::setUserName(const QString &theUserName)
{
    if(!isOpen())
        myUserName = theUserName;
}

// ============================================================================
/*!
 *  \brief userName()
*/
// ============================================================================
QString Spartacus_Session::userName() const
{
    return myUserName;
}
