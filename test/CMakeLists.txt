find_package(GTest REQUIRED)
include(GoogleTest)

add_executable(test-main main.cpp)

target_link_libraries(test-main PRIVATE GTest::gtest_main)

gtest_discover_tests(test-main)
