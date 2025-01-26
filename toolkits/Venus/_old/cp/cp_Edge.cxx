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
#include <cp_Edge.hxx>



// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
cp_Edge::cp_Edge()
    : myNodes(1, 2)
{
    
}

// ============================================================================
/*!
    \brief Destructor
*/
// ============================================================================
cp_Edge::~cp_Edge()    
{
    
}

// ============================================================================
/*!
    \brief FirstNode()
*/
// ============================================================================
Standard_Integer cp_Edge::FirstNode() const
{
    return myNodes.Value(1);
}

// ============================================================================
/*!
    \brief LastNode()
*/
// ============================================================================
Standard_Integer cp_Edge::LastNode() const
{
    return myNodes.Value(2);
}

// ============================================================================
/*!
    \brief NbNodes()
*/
// ============================================================================
Standard_Integer cp_Edge::NbNodes() const
{
    return myNodes.Size();
}

// ============================================================================
/*!
    \brief Node()
*/
// ============================================================================
Standard_Integer cp_Edge::Node(const Standard_Integer theIndex) const
{
    return myNodes.Value(theIndex);
}

// ============================================================================
/*!
    \brief SetNode()
*/
// ============================================================================
void cp_Edge::SetNode(const Standard_Integer theIndex,
                      const Standard_Integer theNode)
{
    myNodes.SetValue(theIndex, theNode);
}