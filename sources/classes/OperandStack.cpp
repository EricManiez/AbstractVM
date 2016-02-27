//
// Created by Eric MANIEZ on 2/27/16.
//

#include "../../includes/classes/OperandStack.hpp"

void OperandStack::push(const IOperand *operand) {
	_operandStack.push_front(operand);
}

void OperandStack::pop() {
	if (_operandStack.size() >= 1) {
		_operandStack.pop_front();
	} else {
		throw OperandStack::StackTooShortException();
	}
}

void OperandStack::dump() {
	std::deque<IOperand const *>::iterator it;
	it = _operandStack.begin();

	while (it != _operandStack.end()) {
		std::cout << (*it)->toString() << std::endl;
		it++;
	}
}

void OperandStack::assert(const IOperand *operand) {
	std::deque<IOperand const *>::iterator it;
	it = _operandStack.begin();

	if (((*it)->getType() != operand->getType()) || ((*it)->toString() != operand->toString())) {
		throw OperandStack::AssertFalseException();
	}
}

void OperandStack::add() {
	if (_operandStack.size() < 2) {
		throw OperandStack::StackTooShortException();
	}
	IOperand const *rhs = *(_operandStack.begin());
	IOperand const *lhs = *(_operandStack.begin() + 1);
	IOperand const *ret = *lhs + *rhs;

	_operandStack.pop_front();
	_operandStack.pop_front();
	_operandStack.push_front(ret);
}

void OperandStack::sub() {
	if (_operandStack.size() < 2) {
		throw OperandStack::StackTooShortException();
	}
	IOperand const *rhs = *(_operandStack.begin());
	IOperand const *lhs = *(_operandStack.begin() + 1);
	IOperand const *ret = *lhs - *rhs;

	_operandStack.pop_front();
	_operandStack.pop_front();
	_operandStack.push_front(ret);
}

void OperandStack::mul() {
	if (_operandStack.size() < 2) {
		throw OperandStack::StackTooShortException();
	}
	IOperand const *rhs = *(_operandStack.begin());
	IOperand const *lhs = *(_operandStack.begin() + 1);
	IOperand const *ret = *lhs * *rhs;

	_operandStack.pop_front();
	_operandStack.pop_front();
	_operandStack.push_front(ret);
}

void OperandStack::div() {
	if (_operandStack.size() < 2) {
		throw OperandStack::StackTooShortException();
	}
	IOperand const *rhs = *(_operandStack.begin());
	IOperand const *lhs = *(_operandStack.begin() + 1);
	IOperand const *ret = *lhs / *rhs;

	_operandStack.pop_front();
	_operandStack.pop_front();
	_operandStack.push_front(ret);
}

void OperandStack::mod() {
	if (_operandStack.size() < 2) {
		throw OperandStack::StackTooShortException();
	}
	IOperand const *rhs = *(_operandStack.begin());
	IOperand const *lhs = *(_operandStack.begin() + 1);
	IOperand const *ret = *lhs % *rhs;

	_operandStack.pop_front();
	_operandStack.pop_front();
	_operandStack.push_front(ret);
}

void OperandStack::print() {
	if ((*_operandStack.begin())->getType() != eOperandType::Int8){
		throw OperandStack::AssertFalseException();
	}
	std::cout << static_cast<char>(stoi((*_operandStack.begin())->toString())) << std::endl;
}

const char *OperandStack::StackTooShortException::what() const throw() {
	return "The stack is too short to perform part of this command.";
}

const char *OperandStack::AssertFalseException::what() const throw() {
	return "The result of the assert operation is false.";
}
