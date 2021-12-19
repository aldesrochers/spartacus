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

// Qt
#include <QApplication>
#include <QCommandLineOption>
#include <QCommandLineParser>
#include <QThread>

// Launcher
#include <Launcher_Version.hxx>

// Spartacus
#include <Spartacus_Desktop.hxx>


// ============================================================================
/*!
    \brief Spartacus_Main
    Implementation of 'Spartacus' application main entry point.
*/
// ============================================================================
int main(int argc, char** argv)
{
    QApplication anApp(argc, argv);
    anApp.setApplicationName("spartacus");
    anApp.setApplicationDisplayName("Spartacus");
    anApp.setApplicationVersion(Launcher_VERSION_STRING);

    // initialize a command-line parser
    QCommandLineParser aParser;

    // process options
    aParser.process(anApp);

    // initialize desktop
    Spartacus_Desktop* aDesktop = new Spartacus_Desktop();
    aDesktop->show();

    return anApp.exec();
}
