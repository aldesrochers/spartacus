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

# basic list of required qt5 components
set(Qt_REQUIRED_COMPONENTS Core Gui Widgets)

# additional list of required qt5 components
list(APPEND Qt_REQUIRED_COMPONENTS Sql)

# try to locate components using standard cmake macros
find_package(Qt5 COMPONENTS ${Qt_REQUIRED_COMPONENTS} REQUIRED)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

# rules
foreach(Qt_COMPONENT ${Qt_REQUIRED_COMPONENTS})
    set(Qt_LIBRARY ${Qt5${Qt_COMPONENT}_LIBRARIES})
    get_target_property(Qt_LIBRARY_PATH ${Qt_LIBRARY} LOCATION)
    if(NOT EXISTS ${Qt_LIBRARY_PATH})
        message(FATAL_ERROR "Could not locate Qt library at path ${Qt_LIBRARY_PATH}")
    endif()
    install(FILES ${Qt_LIBRARY_PATH} DESTINATION ${Spartacus_INSTALL_BINARIES})

    # install platform on MINGW
    set(Qt_PLATFORM_PATH $ENV{MINGW_PREFIX}/share/qt5/plugins/platforms/qwindows.dll)
    if(NOT EXISTS ${Qt_PLATFORM_PATH})
        message(FATAL_ERROR "Could not locate Qt platform library at path ${Qt_PLATFORM_PATH}")
    endif()
    install(FILES ${Qt_PLATFORM_PATH} DESTINATION ${Spartacus_INSTALL_BINARIES}/platforms)

    # install style on MINGW
    set(Qt_STYLE_PATH $ENV{MINGW_PREFIX}/share/qt5/plugins/styles/qwindowsvistastyle.dll)
    if(NOT EXISTS ${Qt_STYLE_PATH})
        message(FATAL_ERROR "Could not locate Qt style library at path ${Qt_STYLE_PATH}")
    endif()
    install(FILES ${Qt_STYLE_PATH} DESTINATION ${Spartacus_INSTALL_BINARIES}/styles)
endforeach()

