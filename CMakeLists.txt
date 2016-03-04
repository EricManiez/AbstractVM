cmake_minimum_required(VERSION 3.3)
project(AbstractVM)

set(42_PROJECT_FLAGS "-Wall -Wextra -Werror")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 ${42_PROJECT_FLAGS}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "./")

set(SOURCE_FILES
        CMakeLists.txt
        includes/classes/operands/Double.hpp
        includes/classes/operands/Float.hpp
        includes/classes/operands/Int16.hpp
        includes/classes/operands/Int32.hpp
        includes/classes/operands/Int8.hpp
        includes/classes/Lexer.hpp
        includes/classes/Operand.hpp
        includes/classes/OperandFactory.hpp
        includes/classes/OperandStackController.hpp
        includes/classes/Parser.hpp
        includes/AbstractVM.hpp
        includes/IOperand.hpp
        sources/classes/operands/Double.cpp
        sources/classes/operands/Float.cpp
        sources/classes/operands/Int16.cpp
        sources/classes/operands/Int32.cpp
        sources/classes/operands/Int8.cpp
        sources/classes/Lexer.cpp
        sources/classes/Operand.cpp
        sources/classes/OperandFactory.cpp
        sources/classes/OperandStackController.cpp
        sources/classes/Parser.cpp
        sources/main.cpp
)

add_executable(AbstractVM ${SOURCE_FILES})