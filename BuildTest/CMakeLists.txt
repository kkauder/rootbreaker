# CMakeLists.txt for libeictest.
#
# To build using cmake, create a build directory, navigate
# to it and run cmake. e.g. 
#  mkdir build
#  cd build
#  cmake .. (or whatever the path to the source directory is)

# You can specify an install directory via
#  -DCMAKE_INSTALL_PREFIX=<path>

cmake_minimum_required(VERSION 3.10)
project(eictest VERSION 1.0 LANGUAGES CXX )

# cmake needs a bit of help to find modules
set(
   CMAKE_MODULE_PATH
   ${CMAKE_MODULE_PATH}
   ${CMAKE_SOURCE_DIR}/cmake/Modules/
   ${CMAKE_SOURCE_DIR}/cmake/
   )

# Need ROOT first to define some macros
find_package(ROOT 6.10 REQUIRED)

##############################################################################################################

# Main target is the libeictest library
# staying away from wildcards and variables
add_library(
   eictest
   SHARED
   ${CMAKE_CURRENT_BINARY_DIR}/dicttestDict.cxx
   ${CMAKE_CURRENT_BINARY_DIR}/smearDict.cxx
   src/BuildTree.cxx
   src/EventDis.cxx
   src/EventMC.cxx
   src/EventStupid.cxx
   src/EventPythia.cxx
   src/SmearTree.cxx
   )

 
# include directories
target_include_directories(eictest
  PUBLIC 
  $<INSTALL_INTERFACE:include>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  
  PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/cint
  ${ROOT_INCLUDE_DIRS}
  )


# Require at least c++11. Could require individual features instead too
target_compile_features(eictest PUBLIC cxx_std_11)

# Can add addtional options here
target_compile_options(eictest PRIVATE -Wall -Wextra -pedantic -g)

##############################################################################################################
# Generate various CINT dictionaries.

#----------------------------------------------------------------------------
# Arguments are:
# function custom_generate_root_dict( dictionary
#                                    header1 header2 ...
#                                    LINKDEF linkdef1 ...
#                                    OPTIONS opt1...
#                                    INCPATH includepath1...)
# I tried my best to pull the include directories out of the target
# but it chokes on $<INSTALL_INTERFACE>,   $<BUILD_INTERFACE>
# so we're passing them by hand
# include( custom_generate_root_dict )
# Get the generate dictionary command from ROOT

if(ROOT_VERSION VERSION_LESS 6.20)
  include("${ROOT_DIR}/modules/RootNewMacros.cmake")
else()
  include("${ROOT_DIR}/RootMacros.cmake")
endif()
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/cmake")


# Main eRHIC dictionary.
set(
  ERHIC_HEADERS
  functions.h
  EventDis.h
  EventMC.h
  EventStupid.h
  EventPythia.h
  VirtualEvent.h
  )
set( ERHIC_INCPATHS
  ${CMAKE_SOURCE_DIR}/include
  ${CMAKE_SOURCE_DIR}/cint
  ${ROOT_INCLUDE_DIRS}
  )

   
ROOT_GENERATE_DICTIONARY( dicttestDict
  NODEPHEADERS ${ERHIC_HEADERS}
  LINKDEF cint/LinkDef.h
  # OPTIONS -rml libeicsmear -rmf libeicsmear.rootmap -s libeicsmear -multiDict
  # INCPATH ${ERHIC_INCPATHS}
  )

# Smearing code dictionary.
ROOT_GENERATE_DICTIONARY( smearDict
  NODEPHEADERS
  smear/functions.h
  LINKDEF cint/smearLinkDef.h
  # OPTIONS -rml libeicsmear -rmf libeicsmear.rootmap -s libeicsmear -multiDict
  # INCPATH ${CMAKE_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR}/cint ${ROOT_INCLUDE_DIRS}
  )

##############################################################################################################
## Link
target_link_libraries(eictest ${ROOT_LIBRARIES} -L${ROOT_LIBRARY_DIR} -lz -lEG )

##############################################################################################################

## Install library
# Could also use include(GNUInstallDirs)
# and then destinations of the form ${CMAKE_INSTALL_INCLUDEDIR}
install(TARGETS eictest
  EXPORT eictest-export
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
  )

## Ideally, one would have a small list of headers
## matched to the target via set_target_properties(eicsmear PROPERTIES  PUBLIC_HEADER eicsmear/functions.h  )
## and then use PUBLIC_HEADER DESTINATION include above.
## However, ROOT wants to see all headers, so we just copy them into place by hand

## Install headers and pcm files
install (DIRECTORY ${CMAKE_SOURCE_DIR}/include/
  DESTINATION  include/
  )
INSTALL(DIRECTORY ${CMAKE_SOURCE_DIR}/include/smear
  DESTINATION DESTINATION  include/smear
  )

INSTALL(FILES ${CMAKE_SOURCE_DIR}/include/functions.h
  DESTINATION include
  )

INSTALL(FILES
  ${CMAKE_CURRENT_BINARY_DIR}/libdicttestDict_rdict.pcm
  ${CMAKE_CURRENT_BINARY_DIR}/libsmearDict_rdict.pcm
  ${CMAKE_CURRENT_BINARY_DIR}/libdicttestDict.rootmap
  ${CMAKE_CURRENT_BINARY_DIR}/libsmearDict.rootmap
  DESTINATION lib
  )

## Generate configuration file
install(EXPORT eictest-export
  FILE
    eictestConfig.cmake
  NAMESPACE
    eictest::
  DESTINATION
  cmake
  )

