add_library(uci-interface
    "./uci-interface/globals.cpp"
)
target_include_directories(uci-interface PRIVATE "./include")

if (CHESS_BUILD_TESTS)
    add_subdirectory("./tests")
endif()
