# CMakeLists.txt for libusetest.

cmake_minimum_required(VERSION 3.10)
project(usetest VERSION 1.0 LANGUAGES CXX )

# Need eictest
find_package(eictest REQUIRED)

# Need ROOT as well
find_package(ROOT 6.10 REQUIRED)

##############################################################################################################

## Optionally, build tests
message(STATUS "-- Adding tests and test files")

add_executable(tester tester.cxx )
target_link_libraries(tester eictest::eictest ${ROOT_LIBRARIES} )
target_include_directories(tester
  PRIVATE
  ${ROOT_INCLUDE_DIRS}
  )

