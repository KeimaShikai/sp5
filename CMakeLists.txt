cmake_minimum_required(VERSION 3.0)
project(sample)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(EXISTS "${CMAKE_CURRENT_BINARY_DIR}/compile_commands.json")
    EXECUTE_PROCESS( COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${CMAKE_CURRENT_BINARY_DIR}/compile_commands.json
        ${CMAKE_CURRENT_SOURCE_DIR}/compile_commands.json
    )
endif()

#headers dirs
list (APPEND X_HEADERS "Sources/hdr")

#src
list (APPEND X_SOURCES "Sources/hdr/CMain.h")
list (APPEND X_SOURCES "Sources/src/CMain.cpp")
list (APPEND X_SOURCES "Sources/main.cpp")

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${X_SOURCE_DIR}/Scripts")

find_package(SDL2 REQUIRED)

include_directories(${X_HEADERS} ${SDL2_INCLUDE_DIR})

add_executable(sample ${X_SOURCES})

target_link_libraries(sample ${SDL2_LIBRARY})
