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

// Spartacus
#include <Spartacus_Engine.hxx>
#include <Spartacus_ILocalCluster.hxx>

// Qt
#include <QDir>
#include <QSqlDatabase>

// Singleton
Spartacus_Engine* Spartacus_Engine::myEngine = nullptr;


// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
Spartacus_Engine::Spartacus_Engine()
{

}

// ============================================================================
/*!
    \brief Destructor
*/
// ============================================================================
Spartacus_Engine::~Spartacus_Engine()
{

}

// ============================================================================
/*!
    \brief createLocalCluster()
    Create a local cluster in directory.
*/
// ============================================================================
bool Spartacus_Engine::createLocalCluster(const QString &theDirPath,
                                          const QString &theAdminUser,
                                          const QString &theAdminPassword)
{
    QString aConnectionName = QString("spartacus-create-local-cluster");
    QString aFileName = theDirPath + QDir::separator() + QString("Spartacus_Admin.db");
    QSqlDatabase aDatabase = QSqlDatabase::addDatabase("QSQLITE", aConnectionName);
    aDatabase.setDatabaseName(aFileName);
    if(!aDatabase.open())
        return false;

    // create all tables in cluster
    Spartacus_ILocalCluster i(aDatabase);
    bool isError = i.createAllTables();

    // close database connection
    aDatabase.close();
    return isError;
}

// ============================================================================
/*!
    \brief defaultSession()
    Retrieve the default session. The default session always has id 0.
*/
// ============================================================================
Spartacus_Session* Spartacus_Engine::defaultSession()
{
    int aSessionId = 0;
    Spartacus_Session* aSession;
    if(myMapOfSession.contains(aSessionId)) {
        aSession = myMapOfSession.value(aSessionId);
    } else {
        aSession = new Spartacus_Session(this, aSessionId);
        myMapOfSession.insert(aSessionId, aSession);
    }
    return aSession;
}

// ============================================================================
/*!
    \brief engine()
*/
// ============================================================================
Spartacus_Engine* Spartacus_Engine::engine()
{
    if(myEngine == nullptr)
        myEngine = new Spartacus_Engine();
    return myEngine;
}

