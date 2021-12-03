cmake_minimum_required(VERSION 3.21)
project(posix_semaphores C)

set(CMAKE_C_STANDARD 11)

add_subdirectory(semcreate)
add_subdirectory(semunlink)
add_subdirectory(semgetval)
add_subdirectory(semwait)
add_subdirectory(sempost)