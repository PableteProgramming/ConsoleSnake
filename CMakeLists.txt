cmake_minimum_required(VERSION 3.12)

project(ConsoleSnake)

set(INC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)


set(SRC_FILES
    ${SRC_DIR}/snake.cpp
    ${SRC_DIR}/console.cpp
)

add_executable(${PROJECT_NAME} ${SRC_FILES})

target_include_directories(
    ${PROJECT_NAME} PUBLIC
    ${INC_DIR}
)