cmake_minimum_required(VERSION 3.11)
set(CMAKE_C_COMPILER "gcc")
set(CMAKE_CXX_COMPILER "g++")
project(28University.cpp)
set(CMAKE_CXX_STANDARD 17)
add_executable(28University 28Universityy.cpp 28Universityy.h 28University_test.cpp)
if(WIN32)
    target_link_libraries(28University C:/msys64/mingw64/lib/libjson-c.a)
else()
    target_link_libraries(28University json-c)
endif()
