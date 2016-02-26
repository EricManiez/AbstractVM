cmake_minimum_required(VERSION 3.3)
project(AbstractVM)

set(42_PROJECT_FLAGS "-Wall -Wextra -Werror")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 ${42_PROJECT_FLAGS}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "./")

set(SOURCE_FILES
    CMakeLists.txt main.cpp includes/IOperand.hpp includes/AbstractVM.hpp sources/classes/Int8.cpp includes/classes/Int8.hpp sources/classes/Double.cpp includes/classes/Double.hpp sources/classes/AOperand.cpp includes/AOperand.hpp sources/classes/Int16.cpp includes/classes/Int16.hpp sources/classes/Int32.cpp includes/classes/Int32.hpp sources/classes/Float.cpp includes/classes/Float.hpp)

add_executable(AbstractVM ${SOURCE_FILES})