cmake_minimum_required(VERSION 3.31)
project(
  Window_Basics
  VERSION 1.0
  LANGUAGES CXX
)

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(FetchContent)

FetchContent_Declare(
  raylib
  GIT_REPOSITORY https://github.com/raysan5/raylib.git
  GIT_TAG 5.5
)

FetchContent_MakeAvailable(raylib)

add_library(
  window_basics
  src/core.cpp
  src/layer.cpp
)

add_library(WindowBasics::window_basics ALIAS window_basics)

target_include_directories(window_basics PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
  $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/window_basics>
)

target_link_libraries(window_basics PUBLIC raylib)

add_executable(
  Window_Basics_Test
  src/main.cpp
)

target_link_libraries(Window_Basics_Test PRIVATE window_basics)

install(TARGETS window_basics
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

install(DIRECTORY src/
  DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/window_basics
  FILES_MATCHING PATTERN "*.h"
)

configure_package_config_file(
  ${CMAKE_CURRENT_SOURCE_DIR}/cmake/WindowBasicsConfig.cmake.in
  ${CMAKE_CURRENT_BINARY_DIR}/WindowBasicsConfig.cmake
  INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/WindowBasics
  PATH_VARS CMAKE_INSTALL_LIBDIR CMAKE_INSTALL_INCLUDEDIR
)

write_basic_package_version_file(
  ${CMAKE_CURRENT_BINARY_DIR}/WindowBasicsConfigVersion.cmake
  VERSION ${PROJECT_VERSION}
  COMPATIBILITY SameMajorVersion
)

install(FILES
  ${CMAKE_CURRENT_BINARY_DIR}/WindowBasicsConfig.cmake
  ${CMAKE_CURRENT_BINARY_DIR}/WindowBasicsConfigVersion.cmake
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/WindowBasics
)
