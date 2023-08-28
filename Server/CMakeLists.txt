cmake_minimum_required(VERSION 3.17...3.30)
project(Server)

set(CMAKE_CXX_STANDARD 20)
set(FLAGS -Wall -Wextra -Werror -Wpedantic)

enable_testing()

# Add boost lib sources
set(BOOST_INCLUDE_LIBRARIES thread filesystem system asio beast)
set(BOOST_ENABLE_CMAKE ON)

# Download and extract the boost library from GitHub
message(STATUS "Downloading and extracting boost library sources. This will take some time...")
include(FetchContent)
set(FETCHCONTENT_QUIET FALSE) # Needed to print downloading progress
FetchContent_Declare(
    Boost
    URL https://github.com/boostorg/boost/releases/download/boost-1.81.0/boost-1.81.0.7z # downloading a zip release speeds up the download
    USES_TERMINAL_DOWNLOAD TRUE 
    GIT_PROGRESS TRUE   
    DOWNLOAD_NO_EXTRACT FALSE
)
FetchContent_MakeAvailable(Boost)

# Include Google Test
include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        release-1.12.1
)
FetchContent_MakeAvailable(googletest)

# Other project settings...
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
target_link_libraries(${PROJECT_NAME} PRIVATE ${PROJECT_NAME}_lib ${FLAGS} Boost::thread Boost::filesystem Boost::system)

file(GLOB TEST_SRC_FILES ${PROJECT_SOURCE_DIR}/tests/*.cpp)

foreach(TEST_SRC_FILE ${TEST_SRC_FILES})
    get_filename_component(TEST_NAME ${TEST_SRC_FILE} NAME_WE)
    add_executable(${TEST_NAME} ${TEST_SRC_FILE})
    target_link_libraries(${TEST_NAME} PRIVATE gtest gmock gtest_main ${PROJECT_NAME}_lib Boost::thread Boost::filesystem Boost::system)
    add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})
endforeach()

add_custom_target(
    ut_build
    COMMAND ${CMAKE_CTEST_COMMAND}
    DEPENDS ${TEST_SRC_FILES})
