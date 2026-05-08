cmake_minimum_required(VERSION 3.10)
project(chess VERSION 1.0.0)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(src/ui)
add_subdirectory(src/engine)
add_subdirectory(src/board)

add_executable(chess src/main.cpp)

target_link_libraries(chess PRIVATE ui engine board)

target_include_directories(chess PRIVATE src/ui src/engine src/board)