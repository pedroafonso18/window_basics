cmake_minimum_required(VERSION 3.31)
project(
  Window_Basics
  VERSION 1.0
  LANGUAGES CXX
)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(FetchContent)

FetchContent_Declare(
  raylib
  GIT_REPOSITORY https://github.com/raysan5/raylib.git
  GIT_TAG 5.5
)

FetchContent_MakeAvailable(raylib)

add_executable(
  Window_Basics
  src/main.cpp 
)

target_link_libraries(Window_Basics PRIVATE raylib)
