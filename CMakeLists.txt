cmake_minimum_required( VERSION 3.1 )
project (stock)

set (CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall")
set(PROJECT_SOURCE_DIR ./src)

include_directories(${PROJECT_SOURCE_DIR})

file(GLOB_RECURSE SRC_FILES ${PROJECT_SOURCE_DIR}/CSVReader/*.cpp  ${PROJECT_SOURCE_DIR}/StockOrder/*.cpp  ${PROJECT_SOURCE_DIR}/StockExchange/*.cpp ${PROJECT_SOURCE_DIR}/LogHandler/*.cpp)

add_executable(stock src/main.cpp ${SRC_FILES})

target_link_libraries(${PROJECT_NAME} stdc++fs)
