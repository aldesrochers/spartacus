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


#ifndef __Spartacus_RemoteCluster_hxx__
#define __Spartacus_RemoteCluster_hxx__

// Spartacus
#include <Spartacus_Cluster.hxx>
#include <Spartacus_Export.hxx>


// ============================================================================
/*!
 *  \brief Spartacus_RemoteCluster
 *  Class implementation of a remote database cluster. A remote cluster
 *  is a database based on postgresql.
*/
// ============================================================================
class Spartacus_EXPORT Spartacus_RemoteCluster : public Spartacus_Cluster
{
    Q_OBJECT

public:
    // constructors
    Spartacus_RemoteCluster(QObject* theParent = nullptr);
    // destructors
    ~Spartacus_RemoteCluster();

public:

    virtual bool            open() override;

};

#endif // __Spartacus_RemoteCluster_hxx__
