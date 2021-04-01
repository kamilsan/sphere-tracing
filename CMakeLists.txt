cmake_minimum_required(VERSION 2.6)
project(sphere-tracing)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wpedantic")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

set(CMAKE_CXX_STANDARD 17)

set(PROJECT_CODE
  include/Color.hpp
  include/Image.hpp src/Image.cpp)

add_subdirectory(googletest)
include_directories(googletest include)

add_executable(app
  ${PROJECT_CODE}
  src/main.cpp
)

add_executable(app-tests
  ${PROJECT_CODE}
  tests/main.cpp)

target_link_libraries(app-tests gtest gtest_main)
