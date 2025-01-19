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


#ifndef __MeshModel_Edge_hxx__
#define __MeshModel_Edge_hxx__

// Spartacus
#include <MeshModel_Curve.hxx>
#include <MeshModel_Shape.hxx>

// OpenCASCADE
#include <TopoDS_Edge.hxx>

// Handles
DEFINE_STANDARD_HANDLE(MeshModel_Edge, MeshModel_Shape)


// ============================================================================
/*
    \brief MeshModel_Edge
*/
// ============================================================================
class MeshModel_Edge : public MeshModel_Shape
{
    
public:
    // constructors
    Standard_EXPORT MeshModel_Edge(const TopoDS_Edge& theEdge);
    // destructors
    Standard_EXPORT ~MeshModel_Edge();

public:

    Standard_EXPORT const Handle(MeshModel_Curve)&  Curve() const;
    Standard_EXPORT const TopoDS_Edge&              Edge() const;
    Standard_EXPORT void                            SetCurve(const Handle(MeshModel_Curve)& theCurve);

private:

    Handle(MeshModel_Curve)     myCurve;

public:

    DEFINE_STANDARD_RTTIEXT(MeshModel_Edge, MeshModel_Shape)

};

#endif // __MeshModel_Edge_hxx__