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
#include <QObject>
#include <QSqlDatabase>

// Spartacus
#include <Spartacus_Export.hxx>
#include <Spartacus_SessionType.hxx>


// ============================================================================
/*!
 *  \brief Spartacus_Session
 *  Class implementation of a Spartacus session.
*/
// ============================================================================
class Spartacus_EXPORT Spartacus_Session : public QObject
{
    Q_OBJECT

public:
    // constructors
    Spartacus_Session(QObject* theParent = nullptr);
    Spartacus_Session(const QString& theSessionName,
                      QObject* theParent = nullptr);
    // destructors
    ~Spartacus_Session();

public:

    bool                    close();
    QString                 directoryPath() const;
    QString                 hostName() const;
    bool                    isOpen() const;
    bool                    isValid() const;
    QString                 password() const;
    int                     port() const;
    QString                 sessionName() const;
    Spartacus_SessionType   sessionType() const;
    void                    setDirectoryPath(const QString& theDirectoryPath);
    void                    setHostName(const QString& theHostName);
    void                    setPassword(const QString& thePassword);
    void                    setPort(const int thePort);
    void                    setSessionName(const QString& theSessionName);
    void                    setSessionType(const Spartacus_SessionType theSessionType);
    void                    setUserName(const QString& theUserName);
    QString                 userName() const;

protected:

    QSqlDatabase            handle(const bool open = true) const;

public:

    QString                 myDirectoryPath;
    QString                 myHostName;
    bool                    myIsOpen;
    QString                 myPassword;
    int                     myPort;
    QString                 mySessionName;
    Spartacus_SessionType   mySessionType;
    QString                 myUserName;

};

#endif // __Spartacus_Session_hxx__
