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

# set qt version
if(Spartacus_USE_QT6)
    set(Qt_VERSION Qt6)
else()
    set(Qt_VERSION Qt5)
endif()

# basic list of required qt5 components
set(Qt_REQUIRED_COMPONENTS Core Gui Widgets)

# additional list of required qt5 components
list(APPEND Qt_REQUIRED_COMPONENTS Sql)

# try to locate components using standard cmake macros
find_package(${Qt_VERSION} COMPONENTS ${Qt_REQUIRED_COMPONENTS} REQUIRED)
if(NOT ${Qt_VERSION}_FOUND)
    message(FATAL_ERROR "Could not locate ${Qt_VERSION}.")
endif()

# mark advanced variables
mark_as_advanced(${Qt_VERSION}_DIR)
mark_as_advanced(${Qt_VERSION}EntryPointPrivate_DIR)
foreach(Qt_COMPONENT ${Qt_REQUIRED_COMPONENTS})
    mark_as_advanced(${Qt_VERSION}${Qt_COMPONENT}_DIR)
    mark_as_advanced(${Qt_VERSION}${Qt_COMPONENT}Tools_DIR)
endforeach()

# configure
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

# define include directories / libraries
foreach(Qt_COMPONENT ${Qt_REQUIRED_COMPONENTS})
    set(Qt${Qt_COMPONENT}_INCLUDE_DIRS ${${Qt_VERSION}${Qt_COMPONENT}_INCLUDE_DIRS})
    set(Qt${Qt_COMPONENT}_LIBRARIES ${${Qt_VERSION}${Qt_COMPONENT}_LIBRARIES})
endforeach()

# rules
foreach(Qt_COMPONENT ${Qt_REQUIRED_COMPONENTS})
    set(Qt_LIBRARY ${${Qt_VERSION}${Qt_COMPONENT}_LIBRARIES})
    get_target_property(Qt_LIBRARY_PATH ${Qt_LIBRARY} LOCATION)
    if(NOT EXISTS ${Qt_LIBRARY_PATH})
        message(FATAL_ERROR "Could not locate Qt library at path ${Qt_LIBRARY_PATH}")
    endif()
    install(FILES ${Qt_LIBRARY_PATH} DESTINATION ${Spartacus_INSTALL_BINARIES})

    # install platform on MINGW
    if(Spartacus_USE_QT6)
        set(Qt_PLATFORM_PATH $ENV{MINGW_PREFIX}/share/qt6/plugins/platforms/qwindows.dll)
    else()
        set(Qt_PLATFORM_PATH $ENV{MINGW_PREFIX}/share/qt5/plugins/platforms/qwindows.dll)
    endif()
    if(NOT EXISTS ${Qt_PLATFORM_PATH})
        message(FATAL_ERROR "Could not locate Qt platform library at path ${Qt_PLATFORM_PATH}")
    endif()
    install(FILES ${Qt_PLATFORM_PATH} DESTINATION ${Spartacus_INSTALL_BINARIES}/platforms)

    # install style on MINGW
    if(Spartacus_USE_QT6)
        set(Qt_STYLE_PATH $ENV{MINGW_PREFIX}/share/qt6/plugins/styles/qwindowsvistastyle.dll)
    else()
        set(Qt_STYLE_PATH $ENV{MINGW_PREFIX}/share/qt5/plugins/styles/qwindowsvistastyle.dll)
    endif()
    if(NOT EXISTS ${Qt_STYLE_PATH})
        message(FATAL_ERROR "Could not locate Qt style library at path ${Qt_STYLE_PATH}")
    endif()
    install(FILES ${Qt_STYLE_PATH} DESTINATION ${Spartacus_INSTALL_BINARIES}/styles)
endforeach()

