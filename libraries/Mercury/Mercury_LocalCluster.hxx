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


#ifndef __Mercury_LocalCluster_hxx__
#define __Mercury_LocalCluster_hxx__

// Mercury
#include <Mercury_Cluster.hxx>
#include <Mercury_Export.hxx>


// ============================================================================
/*!
 *  \brief Mercury_LocalCluster
 *  Class implementation of local database cluster. A local database cluster
 *  is a cluster based on sqlite.
*/
// ============================================================================
class Mercury_EXPORT Mercury_LocalCluster : public Mercury_Cluster
{

public:
    // constructors
    Mercury_LocalCluster(const QString& theConnectionName,
                         QObject* theParent = nullptr);
    // destructors
    ~Mercury_LocalCluster();

public:

    static Mercury_LocalCluster*    addCluster(const QString& theConnectionName);

public:

    virtual QString         clusterType() const override;
    virtual QString         driverName() const override;
    virtual bool            open() override;

public:

    QString             directoryPath() const;
    QString             filePath() const;
    void                setDirectoryPath(const QString& theDirectoryPath);

private:

    QString             myDirectoryPath;

};

#endif // __Mercury_LocalCluster_hxx__
