cmake_minimum_required(VERSION 3.5.0)

project(coin-change)

option(ENABLE_TESTING "Turn on to compile unit tests" OFF)

add_subdirectory(src)

if(ENABLE_TESTING)
	enable_testing()
	add_subdirectory(test)
endif()
