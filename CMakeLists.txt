cmake_minimum_required(VERSION 3.3)
project(AbstractVM)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    auteur)

add_executable(AbstractVM ${SOURCE_FILES})