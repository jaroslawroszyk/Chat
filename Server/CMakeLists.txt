cmake_minimum_required(VERSION 3.17...3.30)
project(Server)

set(CMAKE_CXX_STANDARD 20)
set(FLAGS -Wall -Wextra -Werror -Wpedantic)

enable_testing()

include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        release-1.12.1
)
FetchContent_MakeAvailable(googletest)

set(SOURCES
    src/Server.cpp
    src/UserModel.cpp
    src/ChatModel.cpp
    src/MessageModel.cpp
    src/Connector.cpp)

set(COMMON_INCLUDES ${PROJECT_SOURCE_DIR}/include)
include_directories(${COMMON_INCLUDES})

add_library(${PROJECT_NAME}_lib ${SOURCES})
add_executable(${PROJECT_NAME} src/ChatServer.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE ${PROJECT_NAME}_lib ${FLAGS})

file(GLOB TEST_SRC_FILES ${PROJECT_SOURCE_DIR}/tests/*.cpp)

foreach(TEST_SRC_FILE ${TEST_SRC_FILES})
    get_filename_component(TEST_NAME ${TEST_SRC_FILE} NAME_WE)
    add_executable(${TEST_NAME} ${TEST_SRC_FILE})
    target_link_libraries(${TEST_NAME} PRIVATE gtest gmock gtest_main ${PROJECT_NAME}_lib)
    add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})
endforeach()

add_custom_target(
    ut_build
    COMMAND ${CMAKE_CTEST_COMMAND}
    DEPENDS ${TEST_SRC_FILES})
