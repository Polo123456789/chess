add_library(uci-interface
    "./uci-interface/globals.cpp"
    "./uci-interface/config.cpp"
    "./uci-interface/option.cpp"
    "./uci-interface/engine_interface.cpp"
)

target_include_directories(uci-interface PRIVATE "./include")

if (CHESS_BUILD_TESTS)
    add_subdirectory("./tests")
endif()
