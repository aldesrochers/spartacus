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


#ifndef __Mercury_Cluster_hxx__
#define __Mercury_Cluster_hxx__

// Qt
#include <QObject>
#include <QString>

// Mercury
#include <Mercury_Export.hxx>


// ============================================================================
/*!
 *  \brief Mercury_Cluster
*/
// ============================================================================
class Mercury_EXPORT Mercury_Cluster : public QObject
{
    Q_OBJECT

public:
    // constructors
    Mercury_Cluster(const QString& theConnectionName,
                    QObject* theParent = nullptr);
    // destructors
    ~Mercury_Cluster();

public:

    virtual bool            close();
    virtual QString         clusterType() const = 0;
    virtual QString         driverName() const = 0;
    virtual bool            open();

public:

    QString         connectionName() const;
    bool            isOpen() const;
    QString         password() const;
    void            setPassword(const QString& thePassword);
    void            setUserName(const QString& theUserName);
    QString         userName() const;

protected:

    void            setOpen(const bool isOpen);

protected:

    QString         myConnectionName;
    bool            myIsOpen;
    QString         myPassword;
    QString         myUserName;

};

#endif // __Mercury_Cluster_hxx__
