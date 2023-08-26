cmake_minimum_required(VERSION 3.8)
add_executable(MessageModelTests MessageModelTests.cpp
)
add_executable(UserModelTests UserModelTests.cpp
 )


target_link_libraries(UserModelTests PUBLIC gtest_main Client)
target_link_libraries(MessageModelTests  PUBLIC gtest_main Client)
add_test(
    NAME UserModelTests
    COMMAND UserModelTests

)
add_test( b
        NAME MessageModelTests
        COMMAND MessageModelTests
)
