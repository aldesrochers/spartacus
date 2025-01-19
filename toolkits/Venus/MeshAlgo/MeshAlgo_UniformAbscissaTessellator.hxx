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


#ifndef __MeshAlgo_UniformAbscissaTessellator_hxx__
#define __MeshAlgo_UniformAbscissaTessellator_hxx__

// Spartacus
#include <MeshAlgo_EdgeTessellator.hxx>

// Handles
DEFINE_STANDARD_HANDLE(MeshAlgo_UniformAbscissaTessellator, MeshAlgo_EdgeTessellator)


// ============================================================================
/*
    \brief MeshAlgo_UniformAbscissaTessellator
*/
// ============================================================================
class MeshAlgo_UniformAbscissaTessellator : public MeshAlgo_EdgeTessellator
{
    
public:
    // constructors
    Standard_EXPORT MeshAlgo_UniformAbscissaTessellator();
    Standard_EXPORT MeshAlgo_UniformAbscissaTessellator(const Handle(MeshModel_Edge)& theEdge);
    // destructors
    Standard_EXPORT ~MeshAlgo_UniformAbscissaTessellator();

public:

    Standard_EXPORT void        Perform() Standard_OVERRIDE;

public:

    Standard_EXPORT Standard_Integer    NbPoints() const;
    Standard_EXPORT void                SetNbPoints(const Standard_Integer theNbPoints);

private:

     Standard_Integer   myNbPoints;

public:

    DEFINE_STANDARD_RTTIEXT(MeshAlgo_UniformAbscissaTessellator, MeshAlgo_EdgeTessellator)

};

#endif // __MeshAlgo_UniformAbscissaTessellator_hxx__