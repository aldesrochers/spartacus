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
set(Spartacus_VERSION_MAJOR 1)
set(Spartacus_VERSION_MINOR 0)
set(Spartacus_VERSION_PATCH 0)

# configure version
configure_file(Spartacus_Version.hxx.in Spartacus_Version.hxx)

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
set(Spartacus_LINKED_LIBRARIES
    ${QtCore_LIBRARIES}
    ${QtGui_LIBRARIES}
    ${QtWidgets_LIBRARIES}
    ${QtSql_LIBRARIES}
)

# headers
set(Spartacus_HEADERS
    Spartacus_AboutDialog.hxx
    Spartacus_Desktop.hxx
    Spartacus_Export.hxx
    Spartacus_Module.hxx
    Spartacus_Session.hxx
    Spartacus_SessionType.hxx
)

# sources
set(Spartacus_SOURCES
    Spartacus_AboutDialog.cxx
    Spartacus_Desktop.cxx
    Spartacus_Module.cxx
    Spartacus_Session.cxx
)

# uis
set(Spartacus_UIS
    Spartacus_AboutDialog.ui
)

# resources
if(Spartacus_USE_QT6)
    qt6_add_resources(Spartacus_SOURCES icons/icons.qrc)
else()
    qt5_add_resources(Spartacus_SOURCES icons/icons.qrc)
endif()

# rules
add_library(Spartacus SHARED ${Spartacus_HEADERS} ${Spartacus_SOURCES} ${Spartacus_UIS})
target_link_libraries(Spartacus ${Spartacus_LINKED_LIBRARIES})
Spartacus_INSTALL_LIBRARY(Spartacus)

if(Spartacus_BUILD_DEVELOPMENT)
    install(FILES ${CMAKE_CURRENT_BINARY_DIR}/Spartacus_Version.hxx DESTINATION ${Spartacus_INSTALL_HEADERS}/Spartacus)
    install(FILES ${Spartacus_HEADERS} DESTINATION ${Spartacus_INSTALL_HEADERS}/Spartacus)
endif()



