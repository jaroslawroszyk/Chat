cmake_minimum_required(VERSION 3.17...3.30)
project(ChatApp)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -Werror -Wno-unused-parameter")

include(FetchContent)
add_subdirectory(submodules/boost EXCLUDE_FROM_ALL)
add_subdirectory(submodules/fmt EXCLUDE_FROM_ALL)
add_subdirectory(submodules/GTest EXCLUDE_FROM_ALL)

set(LOG_LEVEL_TRACE 0)
set(LOG_LEVEL_DEBUG 1)
set(LOG_LEVEL_INFO 2)
add_compile_definitions(LOG_LEVEL LOG_LEVEL_TRACE)

add_subdirectory(Server)
add_subdirectory(Client)