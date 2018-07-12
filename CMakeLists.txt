
cmake_minimum_required(VERSION 3.0)
project(gb_emulator)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE Debug)

add_executable(gb_emulator
        src/main.cpp
        )

target_include_directories(gb_emulator PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        )

target_link_libraries(gb_emulator LINK_PUBLIC
        )
