cmake_minimum_required(VERSION 3.15)
project(LuaTest)

find_path(LUA_INCLUDE_DIRS lua.h)
include_directories(${LUA_INCLUDE_DIRS})
add_custom_command(
        TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/lua ${CMAKE_CURRENT_BINARY_DIR}/lua)

find_library(LUA_LIBRARY NAMES liblua lua)
link_libraries(${LUA_LIBRARY})

set(CMAKE_CXX_STANDARD 20)

add_executable(LuaTest main.cpp Runtime/LuaRunner.cpp Runtime/LuaRunner.h Test/TestTemplate.h)