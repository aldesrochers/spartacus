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

#ifndef __Spartacus_Paths_hxx__
#define __Spartacus_Paths_hxx__

// Qt
#include <QString>

// Spartacus
#include <Spartacus_Export.hxx>


// ============================================================================
/*!
    \brief Spartacus_Paths
    Class implementation of 'Spartacus' framework standard paths.
*/
// ============================================================================
class Spartacus_Paths
{

public:

    static Spartacus_EXPORT QString     binaryDirPath();
    static Spartacus_EXPORT QString     binaryResourcesDirPath();
    static Spartacus_EXPORT QString     libraryDirPath();
    static Spartacus_EXPORT QString     rootDirPath();
    static Spartacus_EXPORT QString     userDirPath();

};

#endif  // __Spartacus_Paths_hxx__
