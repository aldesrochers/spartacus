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


#ifndef __Triangle_Triangulate_hxx__
#define __Triangle_Triangulate_hxx__

// OpenCASCADE
#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>

// Spartacus
#include <Triangle_Error.hxx>
#include <Triangle_Model.hxx>
#include <Triangle_Parameters.hxx>



// ============================================================================
/*
    \brief Triangle_Triangulate
*/
// ============================================================================
class Triangle_Triangulate 
{

public:
    // constructors
    Standard_EXPORT Triangle_Triangulate();
    Standard_EXPORT Triangle_Triangulate(const Handle(Triangle_Model)& theInputModel,
                                         const Triangle_Parameters& theParameters = Triangle_Parameters());
    // destructors
    Standard_EXPORT ~Triangle_Triangulate();

public:

    Standard_EXPORT const Triangle_Error&           Error() const;
    Standard_EXPORT const Handle(Triangle_Model)&   InputModel() const;
    Standard_EXPORT Standard_Boolean                IsDone() const;
    Standard_EXPORT const Handle(Triangle_Model)&   OutputModel() const;
    Standard_EXPORT const Triangle_Parameters&      Parameters() const;
    Standard_EXPORT void                            Perform();
    Standard_EXPORT void                            SetInputModel(const Handle(Triangle_Model)& theModel); 
    Standard_EXPORT void                            SetParameters(const Triangle_Parameters& theParameters);
    Standard_EXPORT const Handle(Triangle_Model)&   VoronoiModel() const;

private:

    Triangle_Error          myError;
    Handle(Triangle_Model)  myInputModel;
    Standard_Boolean        myIsDone;
    Handle(Triangle_Model)  myOutputModel;
    Triangle_Parameters     myParameters;
    Handle(Triangle_Model)  myVoronoiModel;

};


#endif // __Triangle_Triangulate_hxx__
