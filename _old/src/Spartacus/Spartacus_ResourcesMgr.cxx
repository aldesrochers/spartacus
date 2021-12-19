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
#include <Spartacus_Paths.hxx>
#include <Spartacus_ResourcesMgr.hxx>

// Qt
#include <QDebug>
#include <QDir>
#include <QResource>

// Singleton
Spartacus_ResourcesMgr* Spartacus_ResourcesMgr::myResourcesMgr = nullptr;


// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
Spartacus_ResourcesMgr::Spartacus_ResourcesMgr()
{
    registerIconResources();
    registerImageResources();
}

// ============================================================================
/*!
    \brief Destructor
*/
// ============================================================================
Spartacus_ResourcesMgr::~Spartacus_ResourcesMgr()
{

}

// ============================================================================
/*!
    \brief icon()
*/
// ============================================================================
QIcon Spartacus_ResourcesMgr::icon(const QString &theFileName)
{
    QString aFileName = QString(":/spartacus-icons/%1").arg(theFileName);
    return QIcon(aFileName);
}

// ============================================================================
/*!
    \brief pixmap()
*/
// ============================================================================
QPixmap Spartacus_ResourcesMgr::pixmap(const QString &theFileName)
{
    QString aFileName = QString(":/spartacus-images/%1").arg(theFileName);
    return QPixmap(aFileName);
}

// ============================================================================
/*!
    \brief registerIconResources()
*/
// ============================================================================
void Spartacus_ResourcesMgr::registerIconResources()
{
    QString aFileName = Spartacus_Paths::binaryResourcesDirPath() +
            QDir::separator() + QString("SpartacusIcons.rcc");
    if(!QResource::registerResource(aFileName, "/spartacus-icons")) {
        qWarning() << "Spartacus_ResourcesMgr::registerIconResources()";
        qWarning() << QString("Could not register file at path %1").arg(aFileName);
    }
}

// ============================================================================
/*!
    \brief registerImageResources()
*/
// ============================================================================
void Spartacus_ResourcesMgr::registerImageResources()
{
    QString aFileName = Spartacus_Paths::binaryResourcesDirPath() +
            QDir::separator() + QString("SpartacusImages.rcc");
    if(!QResource::registerResource(aFileName, "/spartacus-images")) {
        qWarning() << "Spartacus_ResourcesMgr::registerImageResources()";
        qWarning() << QString("Could not register file at path %1").arg(aFileName);
    }
}

// ============================================================================
/*!
    \brief resourcesMgr()
    Get a reference to the singleton resources manager.
*/
// ============================================================================
Spartacus_ResourcesMgr* Spartacus_ResourcesMgr::resourcesMgr()
{
    if(myResourcesMgr == nullptr)
        myResourcesMgr = new Spartacus_ResourcesMgr();
    return myResourcesMgr;
}
