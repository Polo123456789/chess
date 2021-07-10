cmake_minimum_required(VERSION 3.18.1)
project(
    chess-libs
    LANGUAGES CXX
    VERSION 0.0.0
)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)

LIST(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

set(CATCH_INCLUDE_PATH "${CMAKE_SOURCE_DIR}/vendor/catch2")
set(GSL_INCLUDE_PATH   "${CMAKE_SOURCE_DIR}/vendor/GSL/include")

# The gsl can be used everywhere, so lets make the include global
include_directories(${GSL_INCLUDE_PATH})

include(CTest)
include(Catch)
include(Warnings)

add_subdirectory("./src/")
