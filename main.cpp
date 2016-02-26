//
// Created by Eric MANIEZ on 2/18/16.
//

#include <iostream>
#include <float.h>
#include "includes/classes/OperandFactory.hpp"

int main() {

	OperandFactory factory;
	IOperand const *one = factory.createOperand(eOperandType::Int8, "50");
//	IOperand const *two = factory.createOperand(eOperandType::Int8, "2");
//	IOperand const *three = factory.createOperand(eOperandType::Int16, "0x0f");
//	IOperand const *four = factory.createOperand(eOperandType::Int32, "0xff");
//	IOperand const *five = factory.createOperand(eOperandType::Float, "42.42");
//	IOperand const *six = factory.createOperand(eOperandType::Double, "432.432");

	std::cout << (*one + *one)->toString() << std::endl;

	return 1;
}