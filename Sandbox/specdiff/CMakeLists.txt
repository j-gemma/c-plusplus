cmake_minimum_required(VERSION 3.20)

project(specdiff LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(specdiff main.cpp)

target_include_directories(specdiff PRIVATE
  ${CMAKE_SOURCE_DIR}/third_party
)


