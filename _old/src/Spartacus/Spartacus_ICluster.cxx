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
#include <Spartacus_ICluster.hxx>


// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
Spartacus_ICluster::Spartacus_ICluster(const QSqlDatabase& theDatabase)
    : myDatabase(theDatabase)
{

}

// ============================================================================
/*!
    \brief Destructor
*/
// ============================================================================
Spartacus_ICluster::~Spartacus_ICluster()
{

}

// ============================================================================
/*!
    \brief addError()
*/
// ============================================================================
void Spartacus_ICluster::addError(const QSqlError &theError)
{
    myErrors.append(theError);
}

// ============================================================================
/*!
    \brief database()
*/
// ============================================================================
QSqlDatabase Spartacus_ICluster::database() const
{
    return myDatabase;
}

// ============================================================================
/*!
    \brief errors()
*/
// ============================================================================
Spartacus_VectorOfSqlError Spartacus_ICluster::errors() const
{
    return myErrors;
}

// ============================================================================
/*!
    \brief nbErrors()
*/
// ============================================================================
int Spartacus_ICluster::nbErrors() const
{
    return myErrors.size();
}

