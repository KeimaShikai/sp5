cmake_minimum_required(VERSION 3.0)
project(p1)
project(p2)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(EXISTS "${CMAKE_CURRENT_BINARY_DIR}/compile_commands.json")
    EXECUTE_PROCESS( COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${CMAKE_CURRENT_BINARY_DIR}/compile_commands.json
        ${CMAKE_CURRENT_SOURCE_DIR}/compile_commands.json
    )
endif()

#src
list (APPEND P1_SOURCES "Sources/main_1.cpp")
list (APPEND P2_SOURCES "Sources/main_2.cpp")

add_executable(p1 ${P1_SOURCES})
add_executable(p2 ${P2_SOURCES})
