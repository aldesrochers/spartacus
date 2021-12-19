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

#ifndef __Spartacus_ICluster_hxx__
#define __Spartacus_ICluster_hxx__

// Qt
#include <QSqlDatabase>

// Spartacus
#include <Spartacus_VectorOfSqlError.hxx>


// ============================================================================
/*!
    \brief Spartacus_ICluster
    Base class implementation of an interface for cluster operations.
*/
// ============================================================================
class Spartacus_ICluster
{

public:
    // cosntructors
    Spartacus_ICluster(const QSqlDatabase& theDatabase);
    // destructors
    ~Spartacus_ICluster();

public:

    QSqlDatabase                database() const;
    Spartacus_VectorOfSqlError  errors() const;
    int                         nbErrors() const;

protected:

    void                        addError(const QSqlError& theError);

private:

    QSqlDatabase                myDatabase;
    Spartacus_VectorOfSqlError  myErrors;

};

#endif  // __Spartacus_ICluster_hxx__
