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
    ${Qt5Core_INCLUDE_DIRS}
    ${Qt5Sql_INCLUDE_DIRS}
)

# linked libraries
set(_linked_libraries
    ${Qt5Core_LIBRARIES}
    ${Qt5Sql_LIBRARIES}
)

# headers
set(_headers
    Mercury_Cluster.hxx
    Mercury_Engine.hxx
    Mercury_Export.hxx
)

# sources
set(_sources
    Mercury_Cluster.cxx
    Mercury_Engine.cxx
)

# uis
set(_uis

)

# rules : library
add_library(Mercury SHARED ${_headers} ${_sources} ${_uis})
target_link_libraries(Mercury ${_linked_libraries})
install(TARGETS Mercury
    ARCHIVE DESTINATION ${Mercury_INSTALL_LIBRARIES}
    LIBRARY DESTINATION ${Mercury_INSTALL_LIBRARIES}
    RUNTIME DESTINATION ${Mercury_INSTALL_BINARIES})

if(Mercury_BUILD_DEVELOPMENT)
    install(FILES ${CMAKE_CURRENT_BINARY_DIR}/Mercury_Version.hxx DESTINATION ${Mercury_INSTALL_HEADERS})
    install(FILES ${_headers} DESTINATION ${Mercury_INSTALL_HEADERS})
endif()

# rules : executable
include_directories(${Qt5Gui_INCLUDE_DIRS} ${Qt5Widgets_INCLUDE_DIRS})
add_executable(TestMercury WIN32 Mercury_Test.cxx)
target_link_libraries(TestMercury ${_linked_libraries} Mercury ${Qt5Gui_LIBRARIES} ${Qt5Widgets_LIBRARIES})
install(TARGETS TestMercury DESTINATION ${Mercury_INSTALL_BINS})

