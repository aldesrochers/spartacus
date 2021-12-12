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

// Spartacus
#include <Spartacus_Desktop.hxx>
#include <Spartacus_SplashScreen.hxx>
#include <Spartacus_Version.hxx>


// ============================================================================
/*!
    \brief Spartacus_Main
    Implementation of 'Spartacus' application main entry point.
*/
// ============================================================================
int main(int argc, char** argv)
{
    QApplication anApplication(argc, argv);
    anApplication.setApplicationDisplayName("Spartacus");
    anApplication.setApplicationName("spartacus");
    anApplication.setApplicationVersion(Spartacus_VERSION_STRING);
    anApplication.setOrganizationName("spartacus-project");

    // initialize a command-line parser
    QCommandLineParser aParser;

    // option : desktop
    QCommandLineOption optionDesktop(QStringList() << "d" << "desktop");
    aParser.addOption(optionDesktop);

    // option : help
    aParser.addHelpOption();

    // option : version
    aParser.addVersionOption();

    // process command-line options
    aParser.process(anApplication);

    // start in desktop mode ?
    if(argc <= 1 || aParser.isSet(optionDesktop)) {
        Spartacus_SplashScreen aSplashScreen;
        aSplashScreen.show();

        Spartacus_Desktop* aDesktop = new Spartacus_Desktop();
        QThread::sleep(1.);
        aDesktop->show();
        aSplashScreen.finish(aDesktop);
        return anApplication.exec();
    }

    return 0;
}
