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


# =============================================================================
 # Macro : Spartacus_INSTALL_LIBRARY
 # Macro used to install library targets.
# =============================================================================
macro(Spartacus_INSTALL_LIBRARY _target)
    if(Spartacus_BUILD_STANDALONE)
        install(TARGETS ${_target} RUNTIME DESTINATION ${Spartacus_INSTALL_BINARIES})
    else()
        install(TARGETS ${_target}
            ARCHIVE DESTINATION ${Spartacus_INSTALL_LIBRARIES}
            LIBRARY DESTINATION ${Spartacus_INSTALL_LIBRARIES}
            RUNTIME DESTINATION ${Spartacus_INSTALL_BINARIES})
    endif()
endmacro()


# =============================================================================
# Macro : Spartacus_INSTALL_MINGW_LIBRARY
# Macro used to locate a MinGW library and make proper framework configuration.
# =============================================================================
macro(Spartacus_INSTALL_MINGW_LIBRARY _library)
    set(_filename $ENV{MINGW_PREFIX}/bin/${_library})
    if(NOT EXISTS ${_filename})
        message(FATAL_ERROR "Could not locate MINGW runtime library at path ${_filename}")
    endif()
    install(FILES ${_filename} DESTINATION ${Spartacus_INSTALL_BINARIES})
endmacro()


