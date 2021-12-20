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

# set opencascade required components
set(OpenCASCADE_REQUIRED_COMPONENTS
    FoundationClasses
)

# try to locate opencascade using standard macros
find_package(OpenCASCADE REQUIRED)
if(NOT OpenCASCADE_FOUND)
    message(FATAL_ERROR "Could not locate OpenCASCADE.")
endif()
mark_as_advanced(OpenCASCADE_DIR)

# set some additional variables
set(OpenCASCADE_INCLUDE_DIRS ${OpenCASCADE_INCLUDE_DIR})

# install required libraries
if(Spartacus_BUILD_STANDALONE)
    foreach(_component ${OpenCASCADE_REQUIRED_COMPONENTS})
        set(_libraries ${OpenCASCADE_${_component}_LIBRARIES})
        foreach(_library ${_libraries})
            get_target_property(_filename ${_library} LOCATION)
            if(NOT EXISTS ${_filename})
                message(FATAL_ERROR "Could not locate OpenCASCADE library ${_filename}.")
            endif()
            install(FILES ${_filename} DESTINATION ${Spartacus_INSTALL_BINARIES})
        endforeach()
    endforeach()
endif()
