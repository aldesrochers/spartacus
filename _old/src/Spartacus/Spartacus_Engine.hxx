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

#ifndef __Spartacus_Engine_hxx__
#define __Spartacus_Engine_hxx__

// Qt
#include <QMap>
#include <QString>

// Spartacus
#include <Spartacus_Export.hxx>
#include <Spartacus_MapOfSession.hxx>
#include <Spartacus_Session.hxx>

// ============================================================================
/*!
    \brief Spartacus_Engine
    Class implementation of a session manager.
*/
// ============================================================================
class Spartacus_Engine
{

public:
    // constructors
    Spartacus_Engine();
    // destructors
    ~Spartacus_Engine();

public:

    static Spartacus_EXPORT Spartacus_Engine*       engine();

private:

    static Spartacus_Engine*        myEngine;

public:

    Spartacus_EXPORT bool                   createLocalCluster(const QString& theDirPath,
                                                               const QString& theAdminUser,
                                                               const QString& theAdminPassword);
    Spartacus_EXPORT Spartacus_Session*     defaultSession();

private:

    Spartacus_MapOfSession          myMapOfSession;

};

#endif  // __Spartacus_Engine_hxx__
