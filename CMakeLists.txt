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

cmake_minimum_required(VERSION 3.10)
project(Spartacus VERSION 0.1.0 LANGUAGES C CXX)
cmake_policy(SET CMP0167 NEW)

find_package(ADIOS2 REQUIRED)
find_package(Boost REQUIRED)
find_package(CGAL REQUIRED)
find_package(OpenCASCADE REQUIRED)
find_package(OpenCV REQUIRED)
find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)
find_package(VTK REQUIRED)

add_subdirectory(tests)
add_subdirectory(thirdparty)
add_subdirectory(toolkits)
add_subdirectory(tools)