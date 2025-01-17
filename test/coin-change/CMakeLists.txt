add_executable(coin-chane-test coin_change_test.cpp)

target_link_libraries(coin-chane-test
	PRIVATE GTest::gtest_main
	PRIVATE coin-change
)

gtest_discover_tests(coin-chane-test)
