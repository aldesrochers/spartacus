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
#include <Spartacus_Version.hxx>
#include "ui_Spartacus_AboutDialog.h"

// Qt
#include <QIcon>

// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
Spartacus_AboutDialog::Spartacus_AboutDialog(QWidget *theParent)
    : QDialog(theParent),
      myUI(new Ui::Spartacus_AboutDialog)
{
    myUI->setupUi(this);

    // initialize
    initCopyrightLabel();
    initDescriptionLabel();
    initIconLabel();
    initTitleLabel();
    initWarrantyLabel();

    // set fixed size
    setWindowTitle(tr("About"));
    setFixedSize(minimumSizeHint());
}

// ============================================================================
/*!
    \brief Destructor
*/
// ============================================================================
Spartacus_AboutDialog::~Spartacus_AboutDialog()
{
    delete myUI;
}

// ============================================================================
/*!
    \brief initCopyrightLabel()
*/
// ============================================================================
void Spartacus_AboutDialog::initCopyrightLabel()
{
    QString aText = tr("Copyright 2021- The Spartacus Project. All rights reserved.");
    myUI->copyrightLabel->setText(aText);
}

// ============================================================================
/*!
    \brief initDescriptionLabel()
*/
// ============================================================================
void Spartacus_AboutDialog::initDescriptionLabel()
{
    QString aCompilerId = QString(Spartacus_COMPILER_ID);
    QString aCompilerName;
    if(aCompilerId.compare("GNU") == 0)
        aCompilerName = QString("gcc");
    else if(aCompilerId.compare("MSVC") == 0)
        aCompilerName = QString("msvc");
    else
        aCompilerName = QString("unknown");
    QString aText = tr("Based on %1 compiler (version %2)").arg(aCompilerName, Spartacus_COMPILER_VERSION);
    myUI->descriptionLabel->setText(aText);
}

// ============================================================================
/*!
    \brief initIconLabel()
*/
// ============================================================================
void Spartacus_AboutDialog::initIconLabel()
{
    QIcon anIcon = QIcon(":/spartacus.png");
    QPixmap aPixmap(anIcon.pixmap(72, 72));
    myUI->iconLabel->setPixmap(aPixmap);
}

// ============================================================================
/*!
    \brief initTitleLabel()
*/
// ============================================================================
void Spartacus_AboutDialog::initTitleLabel()
{
    QString aText = tr("Spartacus %1").arg(Spartacus_VERSION_STRING);
    QFont aFont;
    aFont.setBold(true);
    aFont.setPointSize(10);
    myUI->titleLabel->setText(aText);
    myUI->titleLabel->setFont(aFont);
}

// ============================================================================
/*!
    \brief initWarrantyLabel()
*/
// ============================================================================
void Spartacus_AboutDialog::initWarrantyLabel()
{
    QString aText = tr("The program is provided as is with no warranty of any kind,\n"
"including the warranty of design, precision and validity\n"
"of computational algorithms.");
    myUI->warrantyLabel->setText(aText);
}
