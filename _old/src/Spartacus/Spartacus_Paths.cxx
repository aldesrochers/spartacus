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

// Qt
#include <QCoreApplication>
#include <QDir>
#include <QStandardPaths>



// ============================================================================
/*!
    \brief binaryDirPath()
*/
// ============================================================================
QString Spartacus_Paths::binaryDirPath()
{
    QString aPath = rootDirPath() + QDir::separator() + QString("bin");
    return aPath;
}

// ============================================================================
/*!
    \brief binaryResourcesDirPath()
*/
// ============================================================================
QString Spartacus_Paths::binaryResourcesDirPath()
{
    QString aPath = binaryDirPath() + QDir::separator() + QString("resources");
    return aPath;
}

// ============================================================================
/*!
    \brief libraryDirPath()
*/
// ============================================================================
QString Spartacus_Paths::libraryDirPath()
{
    QString aPath = rootDirPath() + QDir::separator() + QString("lib");
    return aPath;
}

// ============================================================================
/*!
    \brief rootDirPath()
    Retrieve the framework root install directory path.
    Should always be one directory up from the running executable.
*/
// ============================================================================
QString Spartacus_Paths::rootDirPath()
{
      QDir aDir(QCoreApplication::applicationDirPath());
      aDir.cdUp();
      return aDir.absolutePath();
}

// ============================================================================
/*!
    \brief userDirPath()
    Retrive the path to the root 'user' configuration directory. On retrieve,
    make sure that the directory already exists.
*/
// ============================================================================
QString Spartacus_Paths::userDirPath()
{
    QString aPath = QStandardPaths::writableLocation(QStandardPaths::HomeLocation);
    aPath += QDir::separator() + QString(".spartacus");
    QDir aDir(aPath);
    if(!aDir.exists())
        QDir().mkpath(aPath);
    return aDir.absolutePath();
}

