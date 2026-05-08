add_library(board dummy.cpp dummy.hpp)
target_include_directories(board PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})