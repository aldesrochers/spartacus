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

# version
set(Mercury_VERSION_MAJOR 1)
set(Mercury_VERSION_MINOR 0)
set(Mercury_VERSION_PATCH 0)

# configure version
configure_file(Mercury_Version.hxx.in Mercury_Version.hxx)

# include directories
include_directories(
    ${CMAKE_CURRENT_BINARY_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${QtCore_INCLUDE_DIRS}
    ${QtGui_INCLUDE_DIRS}
    ${QtWidgets_INCLUDE_DIRS}
    ${QtSql_INCLUDE_DIRS}
    ${OpenCASCADE_INCLUDE_DIRS}
)

# linked libraries
set(Mercury_LINKED_LIBRARIES
    ${QtCore_LIBRARIES}
    ${QtGui_LIBRARIES}
    ${QtWidgets_LIBRARIES}
    ${QtSql_LIBRARIES}
    ${OpenCASCADE_FoundationClasses_LIBRARIES}
)

# headers
set(Mercury_HEADERS
    Mercury_Shape.hxx
)

# sources
set(Mercury_SOURCES
    Mercury_Shape.cxx
)

# rules
add_library(Mercury SHARED ${Mercury_HEADERS} ${Mercury_SOURCES})
target_link_libraries(Mercury ${Mercury_LINKED_LIBRARIES})
Spartacus_INSTALL_LIBRARY(Mercury)


if(Mercury_BUILD_DEVELOPMENT)
    install(FILES ${CMAKE_CURRENT_BINARY_DIR}/Mercury_Version.hxx DESTINATION ${Spartacus_INSTALL_HEADERS})
    install(FILES ${Mercury_HEADERS} DESTINATION ${Spartacus_INSTALL_HEADERS})
endif()
