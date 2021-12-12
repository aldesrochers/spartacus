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

#ifndef __Spartacus_Desktop_hxx__
#define __Spartacus_Desktop_hxx__

// Qt
#include <QMainWindow>

// Spartacus
#include <Spartacus_Engine.hxx>
#include <Spartacus_Export.hxx>
#include <Spartacus_ResourcesMgr.hxx>
#include <Spartacus_SettingsMgr.hxx>


// ============================================================================
/*!
    \brief Spartacus_Desktop
*/
// ============================================================================
class Spartacus_Desktop : public QMainWindow
{
    Q_OBJECT

public:
    // constructors
    Spartacus_EXPORT Spartacus_Desktop(QWidget* theParent = nullptr);
    // destructors
    Spartacus_EXPORT ~Spartacus_Desktop();

public:

    Spartacus_EXPORT Spartacus_Engine*          engine();
    Spartacus_EXPORT Spartacus_ResourcesMgr*    resourcesMgr();
    Spartacus_EXPORT Spartacus_SettingsMgr*     settingsMgr();

private:

    virtual void            closeEvent(QCloseEvent* theEvent) override;
    void                    initFileMenu();
    void                    initHelpMenu();
    void                    restoreWindowState();
    void                    saveWindowState();

public slots:

    void                    showAboutDialog();
    void                    showLoginDialog();
    void                    showLogoutDialog();
    void                    showPreferencesDialog();

};

#endif  // __Spartacus_Desktop_hxx__
