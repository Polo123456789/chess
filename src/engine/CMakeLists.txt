add_library(engine dummy.cpp dummy.hpp)
target_include_directories(engine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(engine PRIVATE board)
target_include_directories(engine PRIVATE $<TARGET_PROPERTY:board,INTERFACE_INCLUDE_DIRECTORIES>)