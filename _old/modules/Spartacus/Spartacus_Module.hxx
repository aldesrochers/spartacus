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


#ifndef __Spartacus_Module_hxx__
#define __Spartacus_Module_hxx__

// Qt
#include <QIcon>
#include <QObject>
#include <QString>
#include <QVersionNumber>

// Spartacus
#include <Spartacus_Export.hxx>


// ============================================================================
/*!
 *  \brief Spartacus_Module
 *  Base class implementation of a Spartacus application module.
*/
// ============================================================================
class Spartacus_EXPORT Spartacus_Module : public QObject
{
    Q_OBJECT

public:
    // constructors
    Spartacus_Module(QObject* theParent = nullptr);
    // destructors
    ~Spartacus_Module();

public:

    virtual QString         moduleDescription() const = 0;
    virtual QIcon           moduleIcon() const = 0;
    virtual QString         moduleName() const = 0;
    virtual QVersionNumber  moduleVersion() const = 0;

};

#endif // __Spartacus_Module_hxx__
