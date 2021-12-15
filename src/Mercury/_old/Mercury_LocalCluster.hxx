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
    \brief Mercury_LocalCluster
    Class implementation of a cluster driver for 'local' clusters.
*/
// ============================================================================
class Mercury_LocalCluster : public Mercury_Cluster
{

public:
    // constructors
    Mercury_EXPORT Mercury_LocalCluster(const int theClusterId);
    // destructors
    Mercury_EXPORT ~Mercury_LocalCluster();

public:

    virtual Mercury_EXPORT QString      clusterType() const override;
    virtual Mercury_EXPORT bool         open() override;

public:

    Mercury_EXPORT QString      databaseFileExtension() const;
    Mercury_EXPORT QString      databaseFilePrefix() const;
    Mercury_EXPORT QString      directoryPath() const;
    Mercury_EXPORT void         setDatabaseFileExtension(const QString& theFileExtension);
    Mercury_EXPORT void         setDatabaseFilePrefix(const QString& theFilePrefix);
    Mercury_EXPORT void         setDirectoryPath(const QString& theDirectoryPath);

protected:

    QString                     databaseFileName(const QString& theDatabaseName);

private:

    QString         myDirectoryPath;
    QString         myFileExtension;
    QString         myFilePrefix;

};

#endif // __Mercury_LocalCluster_hxx__
