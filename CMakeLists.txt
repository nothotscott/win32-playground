cmake_minimum_required(VERSION 3.3.2)
set(CMAKE_SYSTEM_NAME Windows)
set(CMAKE_SYSTEM_PROCESSOR i686)
project(Win32HelloWorld)

set(CMAKE_C_COMPILER cl)
set(CMAKE_CXX_COMPILER cl)
set(CMAKE_LINKER link)
set(CMAKE_MC_COMPILER mc)
set(CMAKE_RC_COMPILER rc)

file(GLOB PROJ_SOURCES src/*.c)

add_compile_options(
	"$<$<CONFIG:Debug>:/MTd>" "$<$<CONFIG:RelWithDebInfo>:/MT>"
)
add_definitions(-DUNICODE -D_UNICODE)

add_executable(${CMAKE_PROJECT_NAME} WIN32 ${PROJ_SOURCES})