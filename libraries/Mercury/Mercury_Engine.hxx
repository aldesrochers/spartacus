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


#ifndef __Mercury_Engine_hxx__
#define __Mercury_Engine_hxx__

// Qt
#include <QSqlDatabase>
#include <QString>
#include <QVersionNumber>

// Mercury
#include <Mercury_Export.hxx>


// ============================================================================
/*!
 *  \brief Mercury_Engine
*/
// ============================================================================
class Mercury_EXPORT Mercury_Engine
{

public:
    // constructors
    Mercury_Engine();
    // destructors
    ~Mercury_Engine();

public:

    bool                createCluster(const QString& theDirectoryPath,
                                      const QString& theAdminUserName,
                                      const QString& theAdminPassword);

    bool                isCluster(const int theClusterId) const;

    bool                openCluster(const int theClusterId,
                                    const QString& theDirectoryPath,
                                    const QString& theUserName,
                                    const QString& thePassword,
                                    const bool isReadOnly = true);

    bool                openCluster(const int theClusterId,
                                    const QString& theHostName,
                                    const int thePort,
                                    const QString& theUserName,
                                    const QString& thePassword);

    QVersionNumber      versionNumber() const;

private:

    QString             clusterConnectionName(const int theClusterId) const;
    QString             clusterDatabaseFilePath(const QString& theDirectoryPath,
                                                const QString& theDatabaseName);

};

#endif // __Mercury_Engine_hxx__
