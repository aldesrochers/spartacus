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
#include <QCoreApplication>

// Spartacus
#include <FW_StandardPaths.hxx>
#include <FWR_Manager.hxx>


// ============================================================================
/*!
 *  \brief Test()
*/
// ============================================================================
int main(int argc, char** argv)
{


    cout << FW_StandardPaths::RootDirPath().toStdString() << endl;
    QCoreApplication anApp(argc, argv);
    cout << FW_StandardPaths::RootDirPath().toStdString() << endl;

    cout << FW_StandardPaths::UserHomeDirPath().toStdString() << endl;

    FWR_Manager* aManager = FWR_Manager::Manager();


}
