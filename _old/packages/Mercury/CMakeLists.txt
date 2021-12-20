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
)

# linked libraries
set(Mercury_LINKED_LIBRARIES
    ${QtCore_LIBRARIES}
    ${QtGui_LIBRARIES}
    ${QtWidgets_LIBRARIES}
    ${QtSql_LIBRARIES}
)

# headers
set(Mercury_HEADERS
    Mercury_Cluster.hxx
    Mercury_Export.hxx
    Mercury_LocalCluster.hxx
    Mercury_TableEditorWidget.hxx
)

# sources
set(Mercury_SOURCES
    Mercury_Cluster.cxx
    Mercury_LocalCluster.cxx
    Mercury_TableEditorWidget.cxx
)

# uis
set(Mercury_UIS
    Mercury_TableEditorWidget.ui
)

# rules
add_library(Mercury SHARED ${Mercury_HEADERS} ${Mercury_SOURCES} ${Mercury_UIS})
target_link_libraries(Mercury ${Mercury_LINKED_LIBRARIES})
Spartacus_INSTALL_LIBRARY(Mercury)

if(Mercury_BUILD_DEVELOPMENT)
    install(FILES ${CMAKE_CURRENT_BINARY_DIR}/Mercury_Version.hxx DESTINATION ${Spartacus_INSTALL_HEADERS}/Mercury)
    install(FILES ${Mercury_HEADERS} DESTINATION ${Spartacus_INSTALL_HEADERS}/Mercury)
endif()



###
# tests
###

# list tests
set(Mercury_TESTS
    Mercury_TestCluster
    Mercury_TestLocalCluster
)

# build executables
if(Spartacus_BUILD_TESTS)
    foreach(_test ${Mercury_TESTS})
        add_executable(${_test} WIN32 tests/${_test}.cxx)
        target_link_libraries(${_test} ${Mercury_LINKED_LIBRARIES} Mercury)
    endforeach()
endif()
