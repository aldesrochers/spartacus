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

#ifndef __Spartacus_ResourcesMgr_hxx__
#define __Spartacus_ResourcesMgr_hxx__

// Qt
#include <QIcon>
#include <QObject>
#include <QPixmap>

// Spartacus
#include <Spartacus_Export.hxx>


// ============================================================================
/*!
    \brief Spartacus_ResourcesMgr
*/
// ============================================================================
class Spartacus_ResourcesMgr : public QObject
{
    Q_OBJECT

public:
    // constructors
    Spartacus_ResourcesMgr();
    // destructors
    ~Spartacus_ResourcesMgr();

public:

    static Spartacus_EXPORT Spartacus_ResourcesMgr*     resourcesMgr();

private:

    static Spartacus_ResourcesMgr*      myResourcesMgr;

public:

    Spartacus_EXPORT QIcon      icon(const QString& theFileName);
    Spartacus_EXPORT QPixmap    pixmap(const QString& theFileName);

private:

    void                        registerIconResources();
    void                        registerImageResources();

};

#endif  // __Spartacus_ResourcesMgr_hxx__
