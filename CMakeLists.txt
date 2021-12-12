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
option(Spartacus_BUILD_DEVELOPMENT  "Build Spartacus in development mode ?" ON)
option(Spartacus_BUILD_STANDALONE   "Build Spartacus in stand-alone mode ?" ON)

###
# configuration
###

# always build in shared mode
add_definitions("-DSpartacus_EXPORTS=1")
set(BUILD_SHARED_LIBS ON)

# install directories
set(Spartacus_INSTALL_BINARIES  bin)
set(Spartacus_INSTALL_HEADERS   include)
set(Spartacus_INSTALL_LIBRARIES lib)
set(Spartacus_INSTALL_RCCS      bin/resources)

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
include(SetupPCRE)
include(SetupPNG)
include(SetupQT)
include(SetupRUNTIME)
include(SetupZLIB)
include(SetupZSTD)


###
# sources
###
add_subdirectory(adm)
add_subdirectory(doc)
add_subdirectory(res)
add_subdirectory(src)


