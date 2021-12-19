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
#include <Spartacus_Engine.hxx>
#include <Spartacus_LoginDialog.hxx>
#include <Spartacus_ResourcesMgr.hxx>
#include <Spartacus_SettingsMgr.hxx>
#include "ui_Spartacus_LoginDialog.h"

// Qt
#include <QFileDialog>


// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
Spartacus_LoginDialog::Spartacus_LoginDialog(QWidget *theParent)
    : QDialog(theParent),
      myUI(new Ui::Spartacus_LoginDialog)
{
    myUI->setupUi(this);
    setWindowTitle(tr("Login"));

    // get a reference to the resources manager
    Spartacus_ResourcesMgr* aResMgr = Spartacus_ResourcesMgr::resourcesMgr();

    // group box : session type
    myUI->groupBoxSessionType->setTitle(tr("Session"));
    myUI->radioButtonLocalSession->setText(tr("Local Session"));
    myUI->radioButtonLocalSession->setIcon(aResMgr->icon("LocalCluster.png"));
    myUI->radioButtonRemoteSession->setText(tr("Remote Session"));
    myUI->radioButtonRemoteSession->setIcon(aResMgr->icon("RemoteCluster.png"));

    // group box : local session
    myUI->groupBoxLocalSession->setTitle(tr("Parameters"));
    myUI->labelLocalSessionPassword->setText(tr("Password :"));
    myUI->labelLocalSessionPath->setText(tr("Directory :"));
    myUI->labelLocalSessionUserName->setText(tr("Username :"));
    myUI->pushButtonLocalSessionPath->setText("");
    myUI->pushButtonLocalSessionPath->setIcon(aResMgr->icon("OpenFolder.png"));

    // group box : remote session
    myUI->groupBoxRemoteSession->setTitle(tr("Parameters"));
    myUI->labelRemoteSessionHostName->setText(tr("Hostname :"));
    myUI->labelRemoteSessionPassword->setText(tr("Password :"));
    myUI->labelRemoteSessionPort->setText(tr("Port :"));
    myUI->labelRemoteSessionUserName->setText(tr("Username :"));

    // group box : preferences
    myUI->groupBoxPreferences->setTitle(tr("Preferences"));
    myUI->checkBoxRememberMe->setText(tr("Remember me ?"));
    myUI->checkBoxLoginAutomatically->setText(tr("Login automatically ?"));

    // buttons
    myUI->pushButtonAccept->setText(tr("Accept"));
    myUI->pushButtonAccept->setIcon(aResMgr->icon("Accept.png"));
    myUI->pushButtonCancel->setText(tr("Cancel"));
    myUI->pushButtonCancel->setIcon(aResMgr->icon("Cancel.png"));

    // set some signals & slots
    connect(myUI->radioButtonLocalSession, SIGNAL(toggled(bool)), this, SLOT(updateSelection()));
    connect(myUI->radioButtonRemoteSession, SIGNAL(toggled(bool)), this, SLOT(updateSelection()));
    connect(myUI->pushButtonLocalSessionPath, SIGNAL(clicked(bool)), this, SLOT(selectLocalDirectory()));
    connect(myUI->pushButtonAccept, SIGNAL(clicked(bool)), this, SLOT(onAccept()));
    connect(myUI->pushButtonCancel, SIGNAL(clicked(bool)), this, SLOT(onCancel()));

    // restore configuration
    restoreConfiguration();
}

// ============================================================================
/*!
    \brief Destructor
*/
// ============================================================================
Spartacus_LoginDialog::~Spartacus_LoginDialog()
{
    delete myUI;
}

// ============================================================================
/*!
    \brief onAccept()
*/
// ============================================================================
void Spartacus_LoginDialog::onAccept()
{
    // retrieve a reference to the default session
    Spartacus_Session* aSession = Spartacus_Engine::engine()->defaultSession();

    // set session type
    if(myUI->radioButtonLocalSession->isChecked()) {

    } else  {

    }

}

// ============================================================================
/*!
    \brief onCancel()
*/
// ============================================================================
void Spartacus_LoginDialog::onCancel()
{
    close();
}

// ============================================================================
/*!
    \brief restoreConfiguration()
*/
// ============================================================================
void Spartacus_LoginDialog::restoreConfiguration()
{
    // get a reference to the settings interface
    QSettings* aSettings = Spartacus_SettingsMgr::settingsMgr()->sessionSettings();

    // retrieve default session type
    QString sessionType = aSettings->value("default/sessionType", "local").toString();
    if(sessionType.compare("remote") == 0) {
        myUI->radioButtonLocalSession->setChecked(false);
        myUI->radioButtonRemoteSession->setChecked(true);
    } else {
        myUI->radioButtonLocalSession->setChecked(true);
        myUI->radioButtonRemoteSession->setChecked(false);
    }

    // retrieve 'remember me' & 'auto login'
    myUI->checkBoxRememberMe->setChecked(aSettings->value("default/rememberMe", false).toBool());
    myUI->checkBoxLoginAutomatically->setChecked(aSettings->value("default/loginAutomatically", false).toBool());

}

// ============================================================================
/*!
    \brief selectLocalDirectory()
*/
// ============================================================================
void Spartacus_LoginDialog::selectLocalDirectory()
{
    QString aDirectory = QFileDialog::getExistingDirectory();
    myUI->lineEditLocalSessionPath->setText(aDirectory);
}

// ============================================================================
/*!
    \brief updateSelection()
*/
// ============================================================================
void Spartacus_LoginDialog::updateSelection()
{
    if(myUI->radioButtonLocalSession->isChecked()) {
        myUI->groupBoxLocalSession->setVisible(true);
        myUI->groupBoxRemoteSession->setVisible(false);
    } else if(myUI->radioButtonRemoteSession->isChecked()) {
        myUI->groupBoxLocalSession->setVisible(false);
        myUI->groupBoxRemoteSession->setVisible(true);
    }
    setFixedSize(width(), minimumSizeHint().height());
}
