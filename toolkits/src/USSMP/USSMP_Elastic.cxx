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
#include <USSMP_Elastic.hxx>


// ============================================================================
/*!
 *  \brief Constructor
*/
// ============================================================================
USSMP_Elastic::USSMP_Elastic()
    : myE(0.)
{

}

// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
USSMP_Elastic::USSMP_Elastic(const Standard_Real E)
    : myE(E)
{

}

// ============================================================================
/*!
 *  \brief Destructor
*/
// ============================================================================
USSMP_Elastic::~USSMP_Elastic()
{

}

// ============================================================================
/*!
 *  \brief E()
*/
// ============================================================================
Standard_Real USSMP_Elastic::E() const
{
    return myE;
}

// ============================================================================
/*!
 *  \brief SetE()
*/
// ============================================================================
void USSMP_Elastic::SetE(const Standard_Real E)
{
    myE = E;
}

