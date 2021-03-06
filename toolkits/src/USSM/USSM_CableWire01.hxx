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


#ifndef __USSM_CableWire01_hxx__
#define __USSM_CableWire01_hxx__

// Spartacus
#include <USSM_Model.hxx>
#include <USSMP_CableWire01.hxx>

// Forward declarations
class USSM_CableWire01;

// Handles
DEFINE_STANDARD_HANDLE(USSM_CableWire01, USSM_Model);


// ============================================================================
/*!
    \brief USSM_CableWire01

    Class implementation of a generic cable wire material with a polynomial
    monotonic stress-strain curve and a menegotto-pinto unloading/reloading
    curve.
*/
// ============================================================================
class Standard_EXPORT USSM_CableWire01 : public USSM_Model
{

public:
    // constructors
    USSM_CableWire01(const USSMP_CableWire01& theParameters);
    // destructors
    ~USSM_CableWire01();

public:

    virtual Standard_Boolean    CommitState() Standard_OVERRIDE;
    virtual Standard_Real       GetInitialStiffness() Standard_OVERRIDE;
    virtual Standard_Real       GetTrialStiffness() Standard_OVERRIDE;
    virtual Standard_Real       GetTrialStrain() Standard_OVERRIDE;
    virtual Standard_Real       GetTrialStress() Standard_OVERRIDE;
    virtual Standard_Boolean    RevertToCommitState() Standard_OVERRIDE;
    virtual Standard_Boolean    RevertToInitialState() Standard_OVERRIDE;
    virtual Standard_Boolean    SetTrialStrain(const Standard_Real theStrain) Standard_OVERRIDE;

private:

    Standard_Real               MenegottoStiffness(const Standard_Real Eps,
                                                   const Standard_Real B);
    Standard_Real               MenegottoStress(const Standard_Real Eps,
                                                const Standard_Real B);
    Standard_Real               MonotonicStiffness(const Standard_Real Eps);
    Standard_Real               MonotonicStress(const Standard_Real Eps);
    Standard_Real               PolynomialStiffness(const Standard_Real Eps);
    Standard_Real               PolynomialStress(const Standard_Real Eps);
    Standard_Boolean            UpdateInternalState();

private:

    // Parameters
    USSMP_CableWire01           myParameters;

    // History
    Standard_Real               myCommitStrain;
    Standard_Real               myCommitStress;
    Standard_Integer            myCurrentDirection;
    Standard_Real               myCurrentMaxStrain;
    Standard_Real               myCurrentMaxStress;
    Standard_Real               myCurrentMinStrain;
    Standard_Real               myCurrentMinStress;
    Standard_Integer            myIsInitialLoading;
    Standard_Integer            myPreviousDirection;
    Standard_Real               myTrialStiffness;
    Standard_Real               myTrialStrain;
    Standard_Real               myTrialStress;

public:

    DEFINE_STANDARD_RTTIEXT(USSM_CableWire01, USSM_Model);

};

#endif  // __USSM_CableWire01_hxx__
