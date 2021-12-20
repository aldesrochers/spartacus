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


#ifndef __Spartacus_LocalCluster_hxx__
#define __Spartacus_LocalCluster_hxx__

// Spartacus
#include <Spartacus_Cluster.hxx>
#include <Spartacus_Export.hxx>


// ============================================================================
/*!
 *  \brief Spartacus_LocalCluster
 *  Class implementation of a local database cluster. A local cluster is
 *  a cluster based on sqlite.
*/
// ============================================================================
class Spartacus_EXPORT Spartacus_LocalCluster : public Spartacus_Cluster
{
    Q_OBJECT

public:
    // constructors
    Spartacus_LocalCluster(QObject* theParent = nullptr);
    // destructors
    ~Spartacus_LocalCluster();

public:

    virtual bool    open() override;

public:

    QString         dirPath() const;
    bool            isReadOnly() const;
    void            setDirPath(const QString& theDirPath);
    void            setReadOnly(const bool isReadOnly);

private:

    bool            createAllTables();
    bool            createDatabasesTable();
    bool            createUsersTable();

private:

    QString         myDirPath;
    bool            myIsReadOnly;

};

#endif // __Spartacus_LocalCluster_hxx__
