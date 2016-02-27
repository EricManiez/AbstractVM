//
// Created by Eric MANIEZ on 2/18/16.
//

#include <iostream>
#include <float.h>
#include "../includes/classes/OperandFactory.hpp"
#include "../includes/classes/OperandStack.hpp"

int main() {

	OperandFactory factory;
	OperandStack stack;
	stack.push(factory.createOperand(eOperandType::Int8, "60"));
	stack.push(factory.createOperand(eOperandType::Int8, "60"));
	stack.push(factory.createOperand(eOperandType::Int8, "2"));
	stack.push(factory.createOperand(eOperandType::Int16, "0x0f"));
	stack.push(factory.createOperand(eOperandType::Int32, "0xff"));
	stack.push(factory.createOperand(eOperandType::Float, "42.42"));
	stack.push(factory.createOperand(eOperandType::Double, "432.432"));
	stack.assert(factory.createOperand(eOperandType::Double, "432.4320000"));
	stack.push(factory.createOperand(eOperandType::Float, "432.432000.32"));
	stack.push(factory.createOperand(eOperandType::Int8, "97"));
	stack.print();
	stack.dump();

//	std::cout << (*one + *one)->toString() << std::endl;
//	std::cout << six->toString() << std::endl;
//	std::cout << sev->toString() << std::endl;
//	std::cout << (*sev == *six) << std::endl;

	return 1;
}