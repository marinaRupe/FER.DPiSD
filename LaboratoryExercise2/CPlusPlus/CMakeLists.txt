cmake_minimum_required(VERSION 3.6)
project(CPlusPlus)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp ./Task1/test.cpp ./Task1/client.cpp Task2/task2Bad.cpp Task2/task2.cpp ./Task3/task3.cpp)
add_executable(CPlusPlus ${SOURCE_FILES})