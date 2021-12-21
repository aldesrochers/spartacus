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
#include <QSqlDatabase>

// Mercury
#include <Mercury_LocalCluster.hxx>


// ============================================================================
/*!
 *  \brief Mercury_TestCluster
*/
// ============================================================================
int main(int argc, char** argv)
{
    Mercury_LocalCluster* aCluster = new Mercury_LocalCluster("mercury-local-cluster");
    cout << aCluster->connectionName().toStdString() << endl;
    cout << aCluster->driverName().toStdString() << endl;
    aCluster->setDirectoryPath("C:/Projects/spartacus/libraries/Mercury/cluster");
    aCluster->setPassword("test");
    aCluster->setUserName("alexis");
    cout << aCluster->open() << endl;


    Mercury_LocalCluster* aCluster2 = Mercury_LocalCluster::addCluster("mercury-local-cluster-2");
    cout << aCluster2->connectionName().toStdString() << endl;

}
