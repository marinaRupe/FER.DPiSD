cmake_minimum_required(VERSION 3.6)
project(LaboratoryExercise1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES task1.c task2.c task3.cpp task5.cpp task6.cpp)
add_executable(LaboratoryExercise1 ${SOURCE_FILES})