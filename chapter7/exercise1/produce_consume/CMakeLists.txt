cmake_minimum_required(VERSION 3.0)
project(pthread_produce_consume)

set(CMAKE_CXX_STANDARD 14)

add_executable(pthread_produce_consume main.cpp)
target_link_libraries(pthread_produce_consume pthread)
