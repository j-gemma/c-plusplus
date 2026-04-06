cmake_minimum_required(VERSION 3.20)

project(CPPSandbox)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#Export compile commands for clangd
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

#Collect sources
file(GLOB SRC_FILES CONFIGFURE_DEPENDS *.cpp)

add_executable(main ${SRC_FILES})
