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

// Qt
#include <QMenu>
#include <QMenuBar>


// ============================================================================
/*!
 *  \brief Constructor
*/
// ============================================================================
Spartacus_Desktop::Spartacus_Desktop(QWidget* theParent)
    : QMainWindow(theParent)
{
    // createialize resources
    Q_INIT_RESOURCE(icons);
    // create menus
    createFileMenu();
    createHelpMenu();
}

// ============================================================================
/*!
 *  \brief Destructor
*/
// ============================================================================
Spartacus_Desktop::~Spartacus_Desktop()
{

}

// ============================================================================
/*!
 *  \brief createFileMenu()
*/
// ============================================================================
void Spartacus_Desktop::createFileMenu()
{
    QMenu* aMenu = menuBar()->addMenu(tr("&File"));

    // action : quit
    QAction* quitAction = aMenu->addAction(QIcon(":/quit.png"), tr("Quit"));
    connect(quitAction, SIGNAL(triggered(bool)), this, SLOT(close()));
}

// ============================================================================
/*!
 *  \brief createHelpMenu()
*/
// ============================================================================
void Spartacus_Desktop::createHelpMenu()
{
    QMenu* aMenu = menuBar()->addMenu(tr("&Help"));

    // action : about
    QAction* aboutAction = aMenu->addAction(QIcon(":/about.png"), tr("About"));
    connect(aboutAction, SIGNAL(triggered(bool)), this, SLOT(showAboutDialog()));
}

// ============================================================================
/*!
 *  \brief showAboutDialog()
*/
// ============================================================================
void Spartacus_Desktop::showAboutDialog()
{
    Spartacus_AboutDialog* aDialog = new Spartacus_AboutDialog(this);
    aDialog->show();
}
