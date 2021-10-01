cmake_minimum_required(VERSION 2.8.9)
set(CMAKE_SYSTEM_NAME Windows)
set(CMAKE_SYSTEM_PROCESSOR i686)
project(Win32HelloWorld)

set(CMAKE_C_COMPILER cl)
set(CMAKE_CXX_COMPILER cl)
set(CMAKE_LINKER link)

file(GLOB PROJ_SOURCES src/*.c)

add_executable(${CMAKE_PROJECT_NAME} WIN32 ${PROJ_SOURCES})