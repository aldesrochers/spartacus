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
    ${Qt5Sql_INCLUDE_DIRS}
)

# linked libraries
set(Saturn_LINKED_LIBRARIES
    ${Qt5Core_LIBRARIES}
    ${Qt5Sql_LIBRARIES}
)

# headers
set(Saturn_HEADERS
    Saturn_Export.hxx
    Saturn_MeshViewer.hxx
)

# sources
set(Saturn_SOURCES
    Saturn_MeshViewer.cxx
)

# rules
add_library(Saturn SHARED ${Saturn_HEADERS} ${Saturn_SOURCES})
target_link_libraries(Saturn ${Saturn_LINKED_LIBRARIES})
install(TARGETS Saturn
    ARCHIVE DESTINATION ${Spartacus_INSTALL_LIBRARIES}
    LIBRARY DESTINATION ${Spartacus_INSTALL_LIBRARIES}
    RUNTIME DESTINATION ${Spartacus_INSTALL_BINARIES})

if(Saturn_BUILD_DEVELOPMENT)
    install(FILES ${CMAKE_CURRENT_BINARY_DIR}/Saturn_Version.hxx DESTINATION ${Spartacus_INSTALL_HEADERS})
    install(FILES ${Saturn_HEADERS} DESTINATION ${Spartacus_INSTALL_HEADERS})
endif()
