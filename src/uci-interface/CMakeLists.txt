add_library(uci-interface
    "./uci-interface/globals.cpp"
)
target_include_directories(uci-interface PRIVATE "./include")

add_executable(manual-uci-interface-test "./tests/manual/main.cpp")
target_include_directories(manual-uci-interface-test PRIVATE "./include")
