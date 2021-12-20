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


#ifndef __Spartacus_Cluster_hxx__
#define __Spartacus_Cluster_hxx__

// Qt
#include <QObject>
#include <QSqlDatabase>
#include <QSqlError>

// Spartacus
#include <Spartacus_Export.hxx>
#include <Spartacus_ClusterType.hxx>


// ============================================================================
/*!
 *  \brief Spartacus_Cluster
 *  Class implementation of a Spartacus cluster.
*/
// ============================================================================
class Spartacus_EXPORT Spartacus_Cluster : public QObject
{
    Q_OBJECT

public:
    // constructors
    Spartacus_Cluster(QObject* theParent = nullptr);
    // destructors
    ~Spartacus_Cluster();

public:

    bool                    addDatabase(const QString& theName,
                                        const QString& theFileName,
                                        const QString& theDescription = QString());
    bool                    close();
    QString                 clusterName() const;
    Spartacus_ClusterType   clusterType() const;
    QString                 directoryPath() const;
    QString                 filePrefix() const;
    QString                 hostName() const;
    bool                    isOpen() const;
    bool                    isValid() const;
    QSqlError               lastError() const;
    bool                    open(const bool force = true);
    QString                 password() const;
    int                     port() const;
    void                    setDirectoryPath(const QString& theDirectoryPath);
    void                    setFilePrefix(const QString& theFilePrefix);
    void                    setHostName(const QString& theHostName);
    void                    setPassword(const QString& thePassword);
    void                    setPort(const int thePort);
    void                    setClusterName(const QString& theClusterName);
    void                    setClusterType(const Spartacus_ClusterType theClusterType);
    void                    setUserName(const QString& theUserName);
    QString                 userName() const;

protected:

    bool                    createLocalAdminDatabase(const QString& theFileName);
    QSqlDatabase            handle(const bool open = true) const;
    bool                    openLocalCluster(const bool force);
    bool                    openRemoteCluster();
    void                    setLastError(const QSqlError& theError);
    void                    setOpen(const bool isOpen);

public:

    QString                 myDirectoryPath;
    QString                 myFilePrefix;
    QString                 myHostName;
    bool                    myIsOpen;
    QSqlError               myLastError;
    QString                 myPassword;
    int                     myPort;
    QString                 myClusterName;
    Spartacus_ClusterType   myClusterType;
    QString                 myUserName;

};

#endif // __Spartacus_Cluster_hxx__
