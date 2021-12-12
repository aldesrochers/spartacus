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
#include <Spartacus_AboutDialog.hxx>
#include <Spartacus_Desktop.hxx>
#include <Spartacus_LoginDialog.hxx>
#include <Spartacus_LogoutDialog.hxx>
#include <Spartacus_PreferencesDialog.hxx>

// Qt
#include <QMenuBar>
#include <QMenu>



// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
Spartacus_Desktop::Spartacus_Desktop(QWidget* theParent)
    : QMainWindow(theParent)
{
    // initialize menus
    initFileMenu();
    initHelpMenu();
    // restore state
    restoreWindowState();
}

// ============================================================================
/*!
    \brief Destructor
*/
// ============================================================================
Spartacus_Desktop::~Spartacus_Desktop()
{

}

// ============================================================================
/*!
    \brief closeEvent()
*/
// ============================================================================
void Spartacus_Desktop::closeEvent(QCloseEvent *theEvent)
{
    saveWindowState();
}

// ============================================================================
/*!
    \brief initFileMenu()
*/
// ============================================================================
void Spartacus_Desktop::initFileMenu()
{
    QMenu* aMenu = menuBar()->addMenu(tr("&File"));

    // action : login
    QAction* loginAction = aMenu->addAction(resourcesMgr()->icon("Login.png"), tr("Login"));
    connect(loginAction, SIGNAL(triggered(bool)), this, SLOT(showLoginDialog()));

    // action : logout
    QAction* logoutAction = aMenu->addAction(resourcesMgr()->icon("Logout.png"), tr("Logout"));
    connect(logoutAction, SIGNAL(triggered(bool)), this, SLOT(showLogoutDialog()));

    // separator
    aMenu->addSeparator();

    // action : preferences dialog
    QAction* preferencesAction = aMenu->addAction(resourcesMgr()->icon("Preferences.png"), tr("Preferences"));
    connect(preferencesAction, SIGNAL(triggered(bool)), this, SLOT(showPreferencesDialog()));

    // separator
    aMenu->addSeparator();

    // action : exit
    QAction* exitAction = aMenu->addAction(resourcesMgr()->icon("Exit.png"), tr("Exit"));
    connect(exitAction, SIGNAL(triggered(bool)), this, SLOT(close()));
}

// ============================================================================
/*!
    \brief initHelpMenu()
*/
// ============================================================================
void Spartacus_Desktop::initHelpMenu()
{
    QMenu* aMenu = menuBar()->addMenu(tr("&Help"));

    // action : about
    QAction* aboutAction = aMenu->addAction(resourcesMgr()->icon("About.png"), tr("About"));
    connect(aboutAction, SIGNAL(triggered(bool)), this, SLOT(showAboutDialog()));
}

// ============================================================================
/*!
    \brief resourcesMgr()
*/
// ============================================================================
Spartacus_ResourcesMgr* Spartacus_Desktop::resourcesMgr()
{
    return Spartacus_ResourcesMgr::resourcesMgr();
}

// ============================================================================
/*!
    \brief restoreWindowState()
*/
// ============================================================================
void Spartacus_Desktop::restoreWindowState()
{
    restoreGeometry(settingsMgr()->windowSettings()->value("desktop/geometry", QSize(800, 600)).toByteArray());
    restoreGeometry(settingsMgr()->windowSettings()->value("desktop/state").toByteArray());
}

// ============================================================================
/*!
    \brief saveWindowState()
*/
// ============================================================================
void Spartacus_Desktop::saveWindowState()
{
    settingsMgr()->windowSettings()->setValue("desktop/geometry", saveGeometry());
    settingsMgr()->windowSettings()->setValue("desktop/state", saveState());
}

// ============================================================================
/*!
    \brief settingsMgr()
*/
// ============================================================================
Spartacus_SettingsMgr* Spartacus_Desktop::settingsMgr()
{
    return Spartacus_SettingsMgr::settingsMgr();
}

// ============================================================================
/*!
    \brief showAboutDialog()
*/
// ============================================================================
void Spartacus_Desktop::showAboutDialog()
{
    Spartacus_AboutDialog* aDialog = new Spartacus_AboutDialog(this);
    aDialog->show();
}

// ============================================================================
/*!
    \brief showLoginDialog()
*/
// ============================================================================
void Spartacus_Desktop::showLoginDialog()
{
    Spartacus_LoginDialog* aDialog = new Spartacus_LoginDialog(this);
    aDialog->show();
}

// ============================================================================
/*!
    \brief showLogoutDialog()
*/
// ============================================================================
void Spartacus_Desktop::showLogoutDialog()
{
    Spartacus_LogoutDialog* aDialog = new Spartacus_LogoutDialog(this);
    aDialog->show();
}

// ============================================================================
/*!
    \brief showPreferencesDialog()
*/
// ============================================================================
void Spartacus_Desktop::showPreferencesDialog()
{
    Spartacus_PreferencesDialog* aDialog = new Spartacus_PreferencesDialog(this);
    aDialog->show();
}

