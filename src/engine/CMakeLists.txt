add_library(engine dummy.cpp dummy.hpp)
target_include_directories(engine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})