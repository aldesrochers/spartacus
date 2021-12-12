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

#ifndef __Spartacus_LogoutDialog_hxx__
#define __Spartacus_LogoutDialog_hxx__

// Qt
#include <QDialog>

// Namespaces
namespace Ui {
    class Spartacus_LogoutDialog;
}


// ============================================================================
/*!
    \brief Spartacus_LogoutDialog
*/
// ============================================================================
class Spartacus_LogoutDialog : public QDialog
{
    Q_OBJECT

public:
    // constructors
    explicit Spartacus_LogoutDialog(QWidget* theParent = nullptr);
    // destructors
    ~Spartacus_LogoutDialog();

private:

    void        initCopyrightLabel();
    void        initDescriptionLabel();
    void        initIconLabel();
    void        initTitleLabel();
    void        initWarrantyLabel();

private:

    Ui::Spartacus_LogoutDialog*  myUI;

};

#endif // __Spartacus_LogoutDialog_hxx__
