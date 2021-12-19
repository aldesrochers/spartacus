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

#ifndef __Spartacus_Session_hxx__
#define __Spartacus_Session_hxx__

// Qt
#include <QString>

// Spartacus
#include <Spartacus_Export.hxx>
#include <Spartacus_SessionType.hxx>

// Forward declarations
class Spartacus_Engine;


// ============================================================================
/*!
    \brief Spartacus_Session
*/
// ============================================================================
class Spartacus_Session
{

public:
    // constructors
    Spartacus_Session(Spartacus_Engine* theEngine,
                      const int theSessionId);
    // destructors
    ~Spartacus_Session();

public:

    Spartacus_EXPORT Spartacus_Engine*          engine();
    Spartacus_EXPORT QString                    hostName() const;
    Spartacus_EXPORT QString                    password() const;
    Spartacus_EXPORT int                        port() const;
    Spartacus_EXPORT int                        sessionId() const;
    Spartacus_EXPORT QString                    sessionName() const;
    Spartacus_EXPORT Spartacus_SessionType      sessionType() const;
    Spartacus_EXPORT void                       setSessionType(const Spartacus_SessionType theType);
    Spartacus_EXPORT QString                    userName() const;

private:

    Spartacus_Engine*           myEngine;
    QString                     myHostName;
    QString                     myPassword;
    int                         myPort;
    QString                     myUserName;
    int                         mySessionId;
    Spartacus_SessionType       mySessionType;

};

#endif  // __Spartacus_Session_hxx__
