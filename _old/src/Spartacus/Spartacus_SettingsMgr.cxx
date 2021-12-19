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

#include <iostream>
using namespace std;

// Spartacus
#include <Spartacus_Paths.hxx>
#include <Spartacus_SettingsMgr.hxx>

// Qt
#include <QDir>

// Singleton
Spartacus_SettingsMgr* Spartacus_SettingsMgr::mySettingsMgr = nullptr;



// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
Spartacus_SettingsMgr::Spartacus_SettingsMgr()
{
    initSessionSettings();
    initWindowSettings();
}

// ============================================================================
/*!
    \brief Destructor
*/
// ============================================================================
Spartacus_SettingsMgr::~Spartacus_SettingsMgr()
{

}

// ============================================================================
/*!
    \brief initSessionSettings()
*/
// ============================================================================
void Spartacus_SettingsMgr::initSessionSettings()
{
    QString aFileName = Spartacus_Paths::userDirPath()
            + QDir::separator() + QString("Spartacus_Session.ini");
    mySessionSettings = new QSettings(aFileName, QSettings::IniFormat);
}

// ============================================================================
/*!
    \brief initWindowSettings()
*/
// ============================================================================
void Spartacus_SettingsMgr::initWindowSettings()
{
    QString aFileName = Spartacus_Paths::userDirPath()
            + QDir::separator() + QString("Spartacus_WindowState.ini");
    myWindowSettings = new QSettings(aFileName, QSettings::IniFormat);
}

// ============================================================================
/*!
    \brief sessionSettings()
*/
// ============================================================================
QSettings* Spartacus_SettingsMgr::sessionSettings()
{
    return mySessionSettings;
}

// ============================================================================
/*!
    \brief settingsMgr()
*/
// ============================================================================
Spartacus_SettingsMgr* Spartacus_SettingsMgr::settingsMgr()
{
    if(mySettingsMgr == nullptr)
        mySettingsMgr = new Spartacus_SettingsMgr();
    return mySettingsMgr;
}

// ============================================================================
/*!
    \brief windowSettings()
*/
// ============================================================================
QSettings* Spartacus_SettingsMgr::windowSettings()
{
    return myWindowSettings;
}
