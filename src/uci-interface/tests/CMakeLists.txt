# This one is for quick manual testing, feel free to ignore it

add_executable(manual-test "./manual-test.cpp")
target_include_directories(manual-test PRIVATE "./../include/")
target_link_libraries(manual-test PRIVATE uci-interface)


add_executable(unit-tests 
    "./unit/main.cpp"
    "./unit/info.cpp"
)
target_include_directories(unit-tests PRIVATE "./../include/")
target_include_directories(unit-tests PRIVATE ${CATCH_INCLUDE_PATH})
target_link_libraries(unit-tests PRIVATE uci-interface)

catch_discover_tests(unit-tests)
