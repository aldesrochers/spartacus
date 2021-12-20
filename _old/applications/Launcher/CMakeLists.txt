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
set(Launcher_VERSION_MAJOR 1)
set(Launcher_VERSION_MINOR 0)
set(Launcher_VERSION_PATCH 0)

# configure version
configure_file(Launcher_Version.hxx.in Launcher_Version.hxx)

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
set(Launcher_LINKED_LIBRARIES
    ${QtCore_LIBRARIES}
    ${QtGui_LIBRARIES}
    ${QtWidgets_LIBRARIES}
    Spartacus
)

# headers
set(Launcher_HEADERS

)

# sources
set(Launcher_SOURCES
    Launcher_Main.cxx
)

# uis
set(Launcher_UIS

)

# rules
add_executable(Launcher WIN32 ${Launcher_HEADERS} ${Launcher_SOURCES} ${Launcher_UIS} Launcher.rc)
target_link_libraries(Launcher ${Launcher_LINKED_LIBRARIES})
if(WIN32)
    set_target_properties(Launcher PROPERTIES OUTPUT_NAME Spartacus)
else()
    set_target_properties(Launcher PROPERTIES OUTPUT_NAME spartacus)
endif()
install(TARGETS Launcher DESTINATION ${Spartacus_INSTALL_BINARIES})


