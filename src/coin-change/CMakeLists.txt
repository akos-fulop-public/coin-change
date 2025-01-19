add_library(coin-change SHARED coin_change.cpp)

target_include_directories(coin-change INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
set_target_properties(coin-change PROPERTIES
	PUBLIC_HEADER coin_change.h
)

install(TARGETS coin-change)
