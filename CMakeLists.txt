cmake_minimum_required(VERSION 2.8.9)
set(CMAKE_SYSTEM_NAME Windows)
set(CMAKE_SYSTEM_PROCESSOR i686)
project(Win32HelloWorld)

set(CMAKE_C_COMPILER cl)
set(CMAKE_CXX_COMPILER cl)
set(CMAKE_LINKER link)

add_executable(Win32HelloWorld WIN32 src/main.c)