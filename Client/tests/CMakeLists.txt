cmake_minimum_required(VERSION 3.8)
add_executable(ClientTests ExampleTests.cpp)
target_link_libraries(ClientTests PUBLIC gtest_main Server)
add_test(
    NAME ClientTests
    COMMAND ClientTests
)
