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
set(Huygens_VERSION_MAJOR 1)
set(Huygens_VERSION_MINOR 0)
set(Huygens_VERSION_PATCH 0)

# configure version
configure_file(Huygens_Version.hxx.in Huygens_Version.hxx)

# include directories
include_directories(
    ${CMAKE_CURRENT_BINARY_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${PROJECT_SOURCE_DIR}/modules/Spartacus
    ${QtCore_INCLUDE_DIRS}
    ${QtGui_INCLUDE_DIRS}
    ${QtWidgets_INCLUDE_DIRS}
)

# linked libraries
set(Huygens_LINKED_LIBRARIES
    ${QtCore_LIBRARIES}
    ${QtGui_LIBRARIES}
    ${QtWidgets_LIBRARIES}
    Spartacus
)

# headers
set(Huygens_HEADERS
    Huygens_Export.hxx
    Huygens_Module.hxx
)

# sources
set(Huygens_SOURCES
    Huygens_Module.cxx
)

# uis
set(Huygens_UIS

)

# resources
if(Spartacus_USE_QT6)
    qt6_add_resources(Huygens_SOURCES icons/icons.qrc)
else()
    qt5_add_resources(Huygens_SOURCES icons/icons.qrc)
endif()

# rules
add_library(Huygens SHARED ${Huygens_HEADERS} ${Huygens_SOURCES} ${Huygens_UIS})
target_link_libraries(Huygens ${Huygens_LINKED_LIBRARIES})
Spartacus_INSTALL_LIBRARY(Huygens)

if(Huygens_BUILD_DEVELOPMENT)
    install(FILES ${CMAKE_CURRENT_BINARY_DIR}/Huygens_Version.hxx DESTINATION ${Spartacus_INSTALL_HEADERS}/Huygens)
    install(FILES ${Huygens_HEADERS} DESTINATION ${Spartacus_INSTALL_HEADERS}/Huygens)
endif()



