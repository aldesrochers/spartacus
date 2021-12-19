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
project(Saturn)
set(Saturn_VERSION_MAJOR 1)
set(Saturn_VERSION_MINOR 0)
set(Saturn_VERSION_PATCH 0)

# configure version
configure_file(Saturn_Version.hxx.in Saturn_Version.hxx)

# include directories
include_directories(
    ${CMAKE_CURRENT_BINARY_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${Qt5Core_INCLUDE_DIRS}
    ${Qt5Gui_INCLUDE_DIRS}
    ${Qt5Widgets_INCLUDE_DIRS}
    ${Qt5Sql_INCLUDE_DIRS}
    ${OpenCASCADE_INCLUDE_DIRS}
)

# linked libraries
set(Saturn_LINKED_LIBRARIES
    ${Qt5Core_LIBRARIES}
    ${Qt5Gui_LIBRARIES}
    ${Qt5Widgets_LIBRARIES}
    ${Qt5Sql_LIBRARIES}
    ${OpenCASCADE_FoundationClasses_LIBRARIES}
)

# headers
set(Saturn_HEADERS

)

# sources
set(Saturn_SOURCES

)

# uis
set(Saturn_UIS

)

# rules : library
add_library(Saturn SHARED ${Saturn_HEADERS} ${Saturn_SOURCES} ${Saturn_UIS})
target_link_libraries(Saturn ${Saturn_LINKED_LIBRARIES})
Spartacus_INSTALL_LIBRARY(Saturn)

if(Saturn_BUILD_DEVELOPMENT)
    install(FILES ${CMAKE_CURRENT_BINARY_DIR}/Saturn_Version.hxx DESTINATION ${Spartacus_INSTALL_HEADERS}/Saturn)
    install(FILES ${Saturn_HEADERS} DESTINATION ${Spartacus_INSTALL_HEADERS}/Saturn)
endif()



