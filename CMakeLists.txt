cmake_minimum_required( VERSION 2.8 )
project (stock)

set (CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall")

include_directories(${PROJECT_SOURCE_DIR})

file(GLOB_RECURSE SRC_FILES ${PROJECT_SOURCE_DIR}/*er/*.cpp  ${PROJECT_SOURCE_DIR}/StockExchange/*.cpp ${PROJECT_SOURCE_DIR}/LogHandler/*.cpp)

add_executable(stock main.cpp ${SRC_FILES})

target_link_libraries(${PROJECT_NAME} stdc++fs)
