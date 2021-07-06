option(PSG_WARNINGS_AS_ERRORS "" OFF)

if(MSVC)
    add_definitions(
        /W4
        /w14545 
        /w34242
        /w34254
        /w34287
        /w44263
        /w44265
        /w44296
        /w44311
        /w44826
        /we4289
        /w14546
        /w14547
        /w14549
        /w14555
        /w14619
        /w14905
        /w14906
        /w14928
    )

    if(MSVC_VERSION STREQUAL "1800")
        add_definitions(/w44640)
    else()
        add_definitions(/w34062)
    endif()

    add_definitions(/bigobj /permissive- /utf-8)

    if (PSG_WARNINGS_AS_ERRORS)
        add_definitions(/Wx)
    endif()



else()
    add_definitions(
        -Wall
        -Wextra
        -Wconversion
        -Wshadow
        -Wnon-virtual-dtor
        -Wold-style-cast
        -Wcast-align
        -Wcast-qual
        -Wunused
        -Woverloaded-virtual
        -Wno-noexcept-type
        -Wpedantic
        -Werror=return-type
    )

    if (PSG_WARNINGS_AS_ERRORS)
        add_definitions(-Werror)
    endif()

    if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
        add_definitions(
            -Weverything
            -Wno-c++98-compat-pedantic
            -Wno-c++98-compat
            -Wno-global-constructors
            -Wno-exit-time-destructors
            -Wno-documentation-unknown-command
        )
    else()
        add_definitions(-Wnoexcept)
    endif()
endif()
