cmake_minimum_required(VERSION 3.1)
project(while1_mutexattr)

set(CMAKE_CXX_STANDARD 14)

add_executable(while1_mutexattr main.cpp)
target_link_libraries(while1_mutexattr pthread)
