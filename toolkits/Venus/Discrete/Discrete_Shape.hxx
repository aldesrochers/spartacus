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


#ifndef __Discrete_Shape_hxx__
#define __Discrete_Shape_hxx__

// OpenCASCADE
#include <Standard.hxx>
#include <Standard_DefineHandle.hxx>
#include <Standard_Transient.hxx>
#include <TopoDS_Shape.hxx>

// Handles
DEFINE_STANDARD_HANDLE(Discrete_Shape, Standard_Transient)


// ============================================================================
/*
    \brief Discrete_Shape
*/
// ============================================================================
class Discrete_Shape : public Standard_Transient
{
    
public:
    // constructors
    Standard_EXPORT Discrete_Shape();
    Standard_EXPORT Discrete_Shape(const TopoDS_Shape& theShape);
    // destructors
    Standard_EXPORT ~Discrete_Shape();

public:

    Standard_EXPORT void                    SetShape(const TopoDS_Shape& theShape);
    Standard_EXPORT const TopoDS_Shape&     Shape() const;

private:

    TopoDS_Shape    myShape;

public:

    DEFINE_STANDARD_RTTIEXT(Discrete_Shape, Standard_Transient)

};

#endif // __Discrete_Shape_hxx__
