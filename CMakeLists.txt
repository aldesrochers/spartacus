# =============================================================================
# Copyright (C) 2021-
#
# This library is free software; you can redistribute it and/or
# modify it under the terms of the GNU Lesser General Public
# License as published by the Free Software Foundation; either
# version 2.1 of the License, or (at your option) any later version.
#
# This library is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public
# License along with this library; if not, write to the Free Software
# Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA
#
# Alexis L. Desrochers (alexisdesrochers@gmail.com)
#
# =============================================================================

cmake_minimum_required(VERSION 3.3)
project(SpartacusProject C CXX)

# check for valid system configuration
if(NOT UNIX AND NOT MSYS AND NOT MINGW AND NOT MSVC)
    message(FATAL_ERROR "Only supported on Unix, MSVC, MSYS and MinGW.")
endif()

# check for project cmake files
if(EXISTS ${PROJECT_SOURCE_DIR}/adm/cmakes)
    list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/adm/cmakes)
    include(SpartacusMacros)
else()
    message(FATAL_ERROR "Could not locate project cmake files.")
endif()

###
# options
###
include(CMakeDependentOption)

option(Spartacus_BUILD_DOCUMENTATION    "Build Spartacus documentation ?" ON)
option(Spartacus_BUILD_STANDALONE       "Build Spartacus in stand-alone mode ?" ON)
option(Spartacus_BUILD_TESTS            "Build Spartacus tests ?" ON)
option(Spartacus_USE_QT6                "Build Spartacus using Qt6 ?" ON)

cmake_dependent_option(Spartacus_BUILD_DEVELOPMENT  "Build Spartacus in development mode ?" ON "NOT Spartacus_BUILD_STANDALONE" OFF)
cmake_dependent_option(Spartacus_BUILD_INSTALLER    "Build Spartacus installer ?" ON "Spartacus_BUILD_STANDALONE" OFF)

###
# configuration
###

# always build in shared mode
set(BUILD_SHARED_LIBS ON)

# install directories
set(Spartacus_INSTALL_ROOT      ${CMAKE_INSTALL_PREFIX})
if(Spartacus_BUILD_STANDALONE)
    set(Spartacus_INSTALL_BINARIES  ${Spartacus_INSTALL_ROOT})
    set(Spartacus_INSTALL_CMAKES    ${Spartacus_INSTALL_ROOT}/cmakes)
    set(Spartacus_INSTALL_HEADERS   ${Spartacus_INSTALL_ROOT}/include)
    set(Spartacus_INSTALL_LIBRARIES ${Spartacus_INSTALL_ROOT}/lib)
    set(Spartacus_INSTALL_RCCS      ${Spartacus_INSTALL_ROOT}/resources)
else()
    set(Spartacus_INSTALL_BINARIES  ${Spartacus_INSTALL_ROOT}/bin)
    set(Spartacus_INSTALL_CMAKES    ${Spartacus_INSTALL_ROOT}/lib/cmakes)
    set(Spartacus_INSTALL_HEADERS   ${Spartacus_INSTALL_ROOT}/include/spartacus)
    set(Spartacus_INSTALL_LIBRARIES ${Spartacus_INSTALL_ROOT}/lib/spartacus)
    set(Spartacus_INSTALL_RCCS      ${Spartacus_INSTALL_ROOT}/lib/spartacus)
endif()

# prerequisites
include(SetupBROTLI)
include(SetupBZ2)
include(SetupDOUBLECONVERSION)
include(SetupFREETYPE)
include(SetupGLIB)
include(SetupGRAPHITE)
include(SetupHARFBUZZ)
include(SetupICONV)
include(SetupICU)
include(SetupINTL)
include(SetupMD4C)
include(SetupOPENCASCADE)
include(SetupPCRE)
include(SetupPNG)
include(SetupQT)
include(SetupRUNTIME)
include(SetupTRILINOS)
include(SetupZLIB)
include(SetupZSTD)


###
# sources
###
add_subdirectory(adm)
if(Spartacus_BUILD_DOCUMENTATION)
    add_subdirectory(doc)
endif()
add_subdirectory(etc)
add_subdirectory(res)
add_subdirectory(src)
