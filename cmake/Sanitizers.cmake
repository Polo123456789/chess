# Sanitizer flags for clang

if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    option(PSG_THREAD_SANITIZER "" OFF)
    if(PSG_THREAD_SANITIZER)
        add_definitions(-fsanitize=thread -g)
        set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fsanitize=thread")
    endif()

    option(PSG_ADDRESS_SANITIZER "" OFF)
    if(PSG_ADDRESS_SANITIZER)
        add_definitions(-fsanitize=address -g)
        set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fsanitize=address")
    endif()

    option(PSG_UNDEFINED_SANITIZER "" OFF)
    if(PSG_UNDEFINED_SANITIZER)
        add_definitions(-fsanitize=undefined -g)
        set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fsanitize=undefined")
    endif()
endif()
