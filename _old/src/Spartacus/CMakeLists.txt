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
set(Spartacus_VERSION_MAJOR 1)
set(Spartacus_VERSION_MINOR 0)
set(Spartacus_VERSION_PATCH 0)

# configure version
configure_file(Spartacus_Version.hxx.in Spartacus_Version.hxx)

# include directories
include_directories(
    ${CMAKE_CURRENT_BINARY_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${Qt5Core_INCLUDE_DIRS}
    ${Qt5Gui_INCLUDE_DIRS}
    ${Qt5Widgets_INCLUDE_DIRS}
    ${Qt5Sql_INCLUDE_DIRS}
)

# linked libraries
set(_linked_libraries
    ${Qt5Core_LIBRARIES}
    ${Qt5Gui_LIBRARIES}
    ${Qt5Widgets_LIBRARIES}
    ${Qt5Sql_LIBRARIES}
)

# headers
set(_headers
    Spartacus_AboutDialog.hxx
    Spartacus_Desktop.hxx
    Spartacus_Engine.hxx
    Spartacus_Export.hxx
    Spartacus_ICluster.hxx
    Spartacus_ILocalCluster.hxx
    Spartacus_LoginDialog.hxx
    Spartacus_LogoutDialog.hxx
    Spartacus_MapOfSession.hxx
    Spartacus_Module.hxx
    Spartacus_Paths.hxx
    Spartacus_PreferencesDialog.hxx
    Spartacus_ResourcesMgr.hxx
    Spartacus_Session.hxx
    Spartacus_SessionType.hxx
    Spartacus_SettingsMgr.hxx
    Spartacus_SplashScreen.hxx
    Spartacus_VectorOfSqlError.hxx
)

# sources
set(_sources
    Spartacus_AboutDialog.cxx
    Spartacus_Desktop.cxx
    Spartacus_Engine.cxx
    Spartacus_ICluster.cxx
    Spartacus_ILocalCluster.cxx
    Spartacus_LoginDialog.cxx
    Spartacus_LogoutDialog.cxx
    Spartacus_Module.cxx
    Spartacus_Paths.cxx
    Spartacus_PreferencesDialog.cxx
    Spartacus_ResourcesMgr.cxx
    Spartacus_Session.cxx
    Spartacus_SettingsMgr.cxx
    Spartacus_SplashScreen.cxx
)

# uis
set(_uis
    Spartacus_AboutDialog.ui
    Spartacus_LoginDialog.ui
    Spartacus_LogoutDialog.ui
    Spartacus_PreferencesDialog.ui
)

# rules : library
add_library(Spartacus SHARED ${_headers} ${_sources} ${_uis})
target_link_libraries(Spartacus ${_linked_libraries})
install(TARGETS Spartacus
    ARCHIVE DESTINATION ${Spartacus_INSTALL_LIBRARIES}
    LIBRARY DESTINATION ${Spartacus_INSTALL_LIBRARIES}
    RUNTIME DESTINATION ${Spartacus_INSTALL_BINARIES})

if(Spartacus_BUILD_DEVELOPMENT)
    install(FILES ${CMAKE_CURRENT_BINARY_DIR}/Spartacus_Version.hxx DESTINATION ${Spartacus_INSTALL_HEADERS})
    install(FILES ${_headers} DESTINATION ${Spartacus_INSTALL_HEADERS})
endif()

# rules : executable
add_executable(SpartacusLauncher WIN32 Spartacus_Main.cxx Spartacus.rc)
target_link_libraries(SpartacusLauncher ${_linked_libraries} Spartacus)
set_target_properties(SpartacusLauncher PROPERTIES OUTPUT_NAME Spartacus)
install(TARGETS SpartacusLauncher DESTINATION ${Spartacus_INSTALL_BINS})

