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


#ifndef __CRSA_Error_hxx__
#define __CRSA_Error_hxx__

// ============================================================================
/*!
 *  \brief CRSA_Error
 *  Enumeration of standard analysis errors.
*/
// ============================================================================
enum CRSA_Error
{
    CRSA_InvalidSectionModel,
    CRSA_InvalidSpanLength,
    CRSA_NoError,
    CRSA_NoSaggingHistory,
    CRSA_SaggingHistoryError,
    CRSA_SolutionNotFound
};

#endif  // __CRSA_Error_hxx__
