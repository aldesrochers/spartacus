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


#ifndef __PSLG_Hole_hxx__
#define __PSLG_Hole_hxx__

// OpenCASCADE
#include <Standard.hxx>
#include <Standard_DefineHandle.hxx>
#include <Standard_Transient.hxx>
#include <gp_Pnt2d.hxx>

// Handles
DEFINE_STANDARD_HANDLE(PSLG_Hole, Standard_Transient)


// ============================================================================
/*
    \brief PSLG_Hole
*/
// ============================================================================
class PSLG_Hole : public Standard_Transient
{
    
public:
    // constructors
    Standard_EXPORT PSLG_Hole();
    Standard_EXPORT PSLG_Hole(const gp_Pnt2d& thePoint);
    // destructors
    Standard_EXPORT ~PSLG_Hole();

public:

    Standard_EXPORT const gp_Pnt2d&             Point() const;
    Standard_EXPORT void                        SetPoint(const gp_Pnt2d& thePoint);
    Standard_EXPORT void                        SetX(const Standard_Real theX);
    Standard_EXPORT void                        SetY(const Standard_Real theY);
    Standard_EXPORT Standard_Real               X() const;
    Standard_EXPORT Standard_Real               Y() const;

private:

    gp_Pnt2d                myPoint;

public:

    DEFINE_STANDARD_RTTIEXT(PSLG_Hole, Standard_Transient)

};

#endif // __PSLG_Hole_hxx__
