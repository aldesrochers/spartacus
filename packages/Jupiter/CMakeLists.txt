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
set(Jupiter_VERSION_MAJOR 1)
set(Jupiter_VERSION_MINOR 0)
set(Jupiter_VERSION_PATCH 0)

# configure version
configure_file(Jupiter_Version.hxx.in Jupiter_Version.hxx)

# include directories
include_directories(
    ${CMAKE_CURRENT_BINARY_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${OpenCASCADE_INCLUDE_DIRS}
)

# linked libraries
set(Jupiter_LINKED_LIBRARIES
    ${OpenCASCADE_FoundationClasses_LIBRARIES}
)

# headers
set(Jupiter_HEADERS
    Jupiter_Material.hxx
)

# sources
set(Jupiter_SOURCES
    Jupiter_Material.cxx
)

# uis
set(Jupiter_UIS

)

# resources
if(Spartacus_USE_QT6)
    qt6_add_resources(Jupiter_SOURCES icons/icons.qrc)
else()
    qt5_add_resources(Jupiter_SOURCES icons/icons.qrc)
endif()

# rules
add_library(Jupiter SHARED ${Jupiter_HEADERS} ${Jupiter_SOURCES} ${Jupiter_UIS})
target_link_libraries(Jupiter ${Jupiter_LINKED_LIBRARIES})
Spartacus_INSTALL_LIBRARY(Jupiter)

if(Jupiter_BUILD_DEVELOPMENT)
    install(FILES ${CMAKE_CURRENT_BINARY_DIR}/Jupiter_Version.hxx DESTINATION ${Spartacus_INSTALL_HEADERS}/Jupiter)
    install(FILES ${Jupiter_HEADERS} DESTINATION ${Spartacus_INSTALL_HEADERS}/Jupiter)
endif()



