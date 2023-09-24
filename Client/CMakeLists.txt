cmake_minimum_required(VERSION 3.17...3.30)
project(Client)

set(CMAKE_CXX_STANDARD 20)
set(FLAGS -Wall -Wextra -Werror -Wpedantic)

enable_testing()

set(BOOST_INCLUDE_LIBRARIES thread filesystem system asio beast)
set(BOOST_ENABLE_CMAKE ON)

set(SOURCES
    src/Client.cpp)

set(COMMON_INCLUDES ${PROJECT_SOURCE_DIR}/include)
include_directories(${COMMON_INCLUDES})

add_library(${PROJECT_NAME}_lib ${SOURCES})
add_executable(${PROJECT_NAME} src/ChatClient.cpp src/Client.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE ${PROJECT_NAME}_lib ${FLAGS} Boost::thread Boost::filesystem Boost::system Boost::asio Boost::beast fmt::fmt)

file(GLOB TEST_SRC_FILES ${PROJECT_SOURCE_DIR}/tests/*.cpp)

foreach(TEST_SRC_FILE ${TEST_SRC_FILES})
    get_filename_component(TEST_NAME ${TEST_SRC_FILE} NAME_WE)
    add_executable(${TEST_NAME} ${TEST_SRC_FILE})
    target_link_libraries(${TEST_NAME} PRIVATE gtest gmock gtest_main ${PROJECT_NAME}_lib Boost::thread Boost::filesystem Boost::system Boost::asio Boost::beast fmt::fmt)
    add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})
endforeach()

if(WIN32)
    target_link_libraries(${PROJECT_NAME} PRIVATE ws2_32)
    foreach(TEST_NAME ${TEST_NAMES})
        target_link_libraries(${TEST_NAME} PRIVATE ws2_32)
    endforeach()
endif()
