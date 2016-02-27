cmake_minimum_required(VERSION 3.3)
project(AbstractVM)

set(42_PROJECT_FLAGS "-Wall -Wextra -Werror")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 ${42_PROJECT_FLAGS}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "./")

set(SOURCE_FILES
    CMakeLists.txt includes/AbstractVM.hpp includes/IOperand.hpp includes/classes/Operand.hpp includes/classes/operands/Double.hpp includes/classes/operands/Float.hpp includes/classes/operands/Int16.hpp includes/classes/operands/Int32.hpp includes/classes/operands/Int8.hpp sources/main.cpp sources/classes/Operand.cpp sources/classes/operands/Double.cpp sources/classes/operands/Float.cpp sources/classes/operands/Int16.cpp sources/classes/operands/Int32.cpp sources/classes/operands/Int8.cpp sources/classes/OperandFactory.cpp includes/classes/OperandFactory.hpp sources/classes/OperandStack.cpp includes/classes/OperandStack.hpp)

add_executable(AbstractVM ${SOURCE_FILES})