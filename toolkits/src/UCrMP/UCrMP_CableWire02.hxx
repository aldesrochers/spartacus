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


#ifndef __UCrMP_CableWire02_hxx__
#define __UCrMP_CableWire02_hxx__

// OpenCascade
#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Real.hxx>

// Spartacus
#include <UCrMP_Model.hxx>


// ============================================================================
/*!
 *  \brief UCrMP_CableWire02
 *  Class implementation of uniaxial law parameters of creep model
 *  CableWire02.
*/
// ============================================================================
class Standard_EXPORT UCrMP_CableWire02 : public UCrMP_Model
{

public:

    DEFINE_STANDARD_ALLOC;

public:
    // constructors
    UCrMP_CableWire02();
    UCrMP_CableWire02(const Standard_Real E,
                      const Standard_Real Eps0,
                      const Standard_Real Eps1,
                      const Standard_Real Eps2,
                      const Standard_Real Eps3,
                      const Standard_Real A0,
                      const Standard_Real A1,
                      const Standard_Real A2,
                      const Standard_Real A3,
                      const Standard_Real B0,
                      const Standard_Real B1,
                      const Standard_Real B2,
                      const Standard_Real B3);
    UCrMP_CableWire02(const Standard_Real E,
                      const Standard_Real Eps0,
                      const Standard_Real Eps1,
                      const Standard_Real Eps2,
                      const Standard_Real Eps3,
                      const Standard_Real A0,
                      const Standard_Real A1,
                      const Standard_Real A2,
                      const Standard_Real A3,
                      const Standard_Real B0,
                      const Standard_Real B1,
                      const Standard_Real B2,
                      const Standard_Real B3,
                      const Standard_Real C);
    UCrMP_CableWire02(const Standard_Real E,
                      const Standard_Real Eps0,
                      const Standard_Real Eps1,
                      const Standard_Real Eps2,
                      const Standard_Real Eps3,
                      const Standard_Real A0,
                      const Standard_Real A1,
                      const Standard_Real A2,
                      const Standard_Real A3,
                      const Standard_Real B0,
                      const Standard_Real B1,
                      const Standard_Real B2,
                      const Standard_Real B3,
                      const Standard_Real C,
                      const Standard_Real T0);
    // destructors
    ~UCrMP_CableWire02();

public:

    Standard_Real           A0() const;
    Standard_Real           A1() const;
    Standard_Real           A2() const;
    Standard_Real           A3() const;
    Standard_Real           B0() const;
    Standard_Real           B1() const;
    Standard_Real           B2() const;
    Standard_Real           B3() const;
    Standard_Real           C() const;
    Standard_Real           E() const;
    Standard_Real           Eps0() const;
    Standard_Real           Eps1() const;
    Standard_Real           Eps2() const;
    Standard_Real           Eps3() const;
    Standard_Real           T0() const;

    void                    SetA0(const Standard_Real A0);
    void                    SetA1(const Standard_Real A1);
    void                    SetA2(const Standard_Real A2);
    void                    SetA3(const Standard_Real A3);
    void                    SetB0(const Standard_Real B0);
    void                    SetB1(const Standard_Real B1);
    void                    SetB2(const Standard_Real B2);
    void                    SetB3(const Standard_Real B3);
    void                    SetC(const Standard_Real C);
    void                    SetE(const Standard_Real E);
    void                    SetEps0(const Standard_Real Eps0);
    void                    SetEps1(const Standard_Real Eps1);
    void                    SetEps2(const Standard_Real Eps2);
    void                    SetEps3(const Standard_Real Eps3);
    void                    SetT0(const Standard_Real T0);

private:

    Standard_Real           myA0;
    Standard_Real           myA1;
    Standard_Real           myA2;
    Standard_Real           myA3;
    Standard_Real           myB0;
    Standard_Real           myB1;
    Standard_Real           myB2;
    Standard_Real           myB3;
    Standard_Real           myC;
    Standard_Real           myE;
    Standard_Real           myEps0;
    Standard_Real           myEps1;
    Standard_Real           myEps2;
    Standard_Real           myEps3;
    Standard_Real           myT0;

};

#endif  // __UCrMP_CableWire02_hxx__
