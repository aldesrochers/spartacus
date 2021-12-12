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
    \brief Constructor
*/
// ============================================================================
Spartacus_Session::Spartacus_Session(Spartacus_Engine* theEngine,
                                     const int theSessionId)
    : myEngine(theEngine),
      mySessionId(theSessionId),
      mySessionType(Spartacus_UnknownSession)
{

}

// ============================================================================
/*!
    \brief Destructor
*/
// ============================================================================
Spartacus_Session::~Spartacus_Session()
{

}

// ============================================================================
/*!
    \brief engine()
*/
// ============================================================================
Spartacus_Engine* Spartacus_Session::engine()
{
    return myEngine;
}

// ============================================================================
/*!
    \brief hostName()
*/
// ============================================================================
QString Spartacus_Session::hostName() const
{
    return myHostName;
}

// ============================================================================
/*!
    \brief password()
*/
// ============================================================================
QString Spartacus_Session::password() const
{
    return myPassword;
}

// ============================================================================
/*!
    \brief port()
*/
// ============================================================================
int Spartacus_Session::port() const
{
    return myPort;
}

// ============================================================================
/*!
    \brief sessionId()
*/
// ============================================================================
int Spartacus_Session::sessionId() const
{
    return mySessionId;
}

// ============================================================================
/*!
    \brief sessionName()
*/
// ============================================================================
QString Spartacus_Session::sessionName() const
{
    QString aName = QString("spartacus-session-%1").arg(sessionId());
    return aName;
}

// ============================================================================
/*!
    \brief sessionType()
*/
// ============================================================================
Spartacus_SessionType Spartacus_Session::sessionType() const
{
    return mySessionType;
}

// ============================================================================
/*!
    \brief setSessionType()
*/
// ============================================================================
void Spartacus_Session::setSessionType(const Spartacus_SessionType theType)
{
    mySessionType = theType;
}

// ============================================================================
/*!
    \brief userName()
*/
// ============================================================================
QString Spartacus_Session::userName() const
{
    return myUserName;
}

