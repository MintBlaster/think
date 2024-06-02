# - Try to find SDL2_image
# Once done, this will define
#
#  SDL2_IMAGE_INCLUDE_DIR - where to find SDL_image.h
#  SDL2_IMAGE_LIBRARIES   - the libraries to link against
#  SDL2_IMAGE_FOUND       - if false, do not try to use SDL2_image

#=============================================================================
# Copyright 2003-2024 Kitware, Inc.
#
# Distributed under the OSI-approved BSD License (the "License");
# see accompanying file Copyright.txt for details.
#
# This software is distributed WITHOUT ANY WARRANTY; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
# See the License for more information.
#=============================================================================

SET(SDL2_IMAGE_SEARCH_PATHS
        ~/Library/Frameworks
        /Library/Frameworks
        /usr/local
        /usr
        /sw # Fink
        /opt/local # DarwinPorts
        /opt/csw # Blastwave
        /opt
        ${SDL2_IMAGE_PATH}
)

FIND_PATH(SDL2_IMAGE_INCLUDE_DIR SDL_image.h
        HINTS
        $ENV{SDL2_IMAGE_DIR}
        PATH_SUFFIXES include/SDL2 include
        PATHS ${SDL2_IMAGE_SEARCH_PATHS}
)

if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    set(PATH_SUFFIXES lib64 lib/x64 lib)
else()
    set(PATH_SUFFIXES lib/x86 lib)
endif()

FIND_LIBRARY(SDL2_IMAGE_LIBRARY_TEMP
        NAMES SDL2_image
        HINTS
        $ENV{SDL2_IMAGE_DIR}
        PATH_SUFFIXES ${PATH_SUFFIXES}
        PATHS ${SDL2_IMAGE_SEARCH_PATHS}
)

IF(SDL2_IMAGE_LIBRARY_TEMP)
    SET(SDL2_IMAGE_LIBRARY ${SDL2_IMAGE_LIBRARY_TEMP} CACHE STRING "Where the SDL2_image Library can be found")
    SET(SDL2_IMAGE_LIBRARY_TEMP "${SDL2_IMAGE_LIBRARY_TEMP}" CACHE INTERNAL "")
ENDIF(SDL2_IMAGE_LIBRARY_TEMP)

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(SDL2_image REQUIRED_VARS SDL2_IMAGE_LIBRARY SDL2_IMAGE_INCLUDE_DIR)
