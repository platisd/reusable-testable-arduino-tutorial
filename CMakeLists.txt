cmake_minimum_required(VERSION 3.15)
project(reusable_and_testable_code_for_arduino)

set(CMAKE_CXX_STANDARD 14)

if(NOT MSVC)
        add_compile_options(
                -Wcast-align
                -Wpedantic
                -Wcast-qual
                -Wconversion
                -Wctor-dtor-privacy
                -Wnon-virtual-dtor
                -Wmissing-include-dirs
                -Wdisabled-optimization
                -Winit-self
                -Wnon-virtual-dtor
                -Wold-style-cast
                -Woverloaded-virtual
                -Wparentheses
                -Wredundant-decls
                -Wshadow
                -Wsign-promo
                -Wstrict-aliasing
                -Wall
                -Wextra
                -Werror
        )
else()
        add_compile_options(
                /W4
                /WX
        )
endif()

set(calculator_dir ${CMAKE_CURRENT_SOURCE_DIR}/sketches/calculator)
set(magiccar_dir ${CMAKE_CURRENT_SOURCE_DIR}/sketches/MagicCarControllerTestable)

enable_testing()
add_subdirectory(test)
