add_library(coin-change coin_change.cpp)

target_include_directories (coin-change INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
