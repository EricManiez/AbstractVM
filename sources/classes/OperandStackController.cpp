//
// Created by Eric MANIEZ on 2/27/16.
//

#include "../../includes/classes/OperandStackController.hpp"
#include "../../includes/classes/OperandFactory.hpp"

OperandStackController::OperandStackController() {
	_unaries["pop"] = &OperandStackController::pop;
	_unaries["dump"] = &OperandStackController::dump;
	_unaries["add"] = &OperandStackController::add;
	_unaries["sub"] = &OperandStackController::sub;
	_unaries["mul"] = &OperandStackController::mul;
	_unaries["div"] = &OperandStackController::div;
	_unaries["mod"] = &OperandStackController::mod;
	_unaries["print"] = &OperandStackController::print;
	_unaries["exit"] = &OperandStackController::mExit;

	_binaries["push"] = &OperandStackController::push;
	_binaries["assert"] = &OperandStackController::assert;
};

OperandStackController::OperandStackController(const OperandStackController &controller) :
		_operandStack(controller.get_operandStack()),
		_unaries(controller.get_unaries()),
		_binaries(controller.get_binaries()) {}

OperandStackController const &OperandStackController::operator=(OperandStackController const &rhs) {
	_operandStack = rhs.get_operandStack();
	_binaries = rhs.get_binaries();
	_unaries = rhs.get_unaries();

	return *this;
}

const std::deque<const IOperand *> &OperandStackController::get_operandStack() const {
	return _operandStack;
}

const std::map<std::string, OperandStackController::UnaryControllerFunctionPointer> &OperandStackController::get_unaries() const {
	return _unaries;
}

const std::map<std::string, OperandStackController::BinaryControllerFunctionPointer> &OperandStackController::get_binaries() const {
	return _binaries;
}

void OperandStackController::execute(std::string string) {

	Lexer lexer(string);
	std::map<std::string, std::string> expression = lexer.analyzeExpression();

	if (expression.size() == 1) {
		(this->*_unaries[expression["instruction"]])();
	} else {
		std::map<std::string, eOperandType> types;
		types["Int8"] = eOperandType::Int8;
		types["Int16"] = eOperandType::Int16;
		types["Int32"] = eOperandType::Int32;
		types["Float"] = eOperandType::Float;
		types["Double"] = eOperandType::Double;

		std::cout << expression["instruction"] << std::endl;
		std::cout << expression["operand"] << std::endl;

		OperandFactory factory;
		IOperand const *val = factory.createOperand(types[expression["type"]], expression["operand"]);
		(this->*_binaries[expression["instruction"]])(val);
	}
}

void OperandStackController::push(const IOperand *operand) {
	_operandStack.push_front(operand);
}

void OperandStackController::pop() {
	if (_operandStack.size() >= 1) {
		_operandStack.pop_front();
	} else {
		throw OperandStackController::StackTooShortException();
	}
}

void OperandStackController::dump() {
	for (IOperand const *i : _operandStack) {
		std::cout << i->toString() << std::endl;
	}
}

void OperandStackController::assert(const IOperand *operand) {
	if ((_operandStack[0]->getType() != operand->getType()) || (_operandStack[0]->toString() != operand->toString())) {
		throw OperandStackController::AssertFalseException();
	}
}

void OperandStackController::add() {
	if (_operandStack.size() < 2) {
		throw OperandStackController::StackTooShortException();
	}
	IOperand const *ret = *_operandStack[1] + *_operandStack[0];

	_operandStack.pop_front();
	_operandStack.pop_front();
	_operandStack.push_front(ret);
}

void OperandStackController::sub() {
	if (_operandStack.size() < 2) {
		throw OperandStackController::StackTooShortException();
	}
	IOperand const *ret = *_operandStack[1] - *_operandStack[0];

	_operandStack.pop_front();
	_operandStack.pop_front();
	_operandStack.push_front(ret);
}

void OperandStackController::mul() {
	if (_operandStack.size() < 2) {
		throw OperandStackController::StackTooShortException();
	}
	IOperand const *ret = *_operandStack[1] * *_operandStack[0];

	_operandStack.pop_front();
	_operandStack.pop_front();
	_operandStack.push_front(ret);
}

void OperandStackController::div() {
	if (_operandStack.size() < 2) {
		throw OperandStackController::StackTooShortException();
	}
	IOperand const *ret = *_operandStack[1] / *_operandStack[0];

	_operandStack.pop_front();
	_operandStack.pop_front();
	_operandStack.push_front(ret);
}

void OperandStackController::mod() {
	if (_operandStack.size() < 2) {
		throw OperandStackController::StackTooShortException();
	}
	IOperand const *ret = *_operandStack[1] % *_operandStack[0];

	_operandStack.pop_front();
	_operandStack.pop_front();
	_operandStack.push_front(ret);
}

void OperandStackController::print() {
	if (_operandStack[0]->getType() != eOperandType::Int8) {
		throw OperandStackController::AssertFalseException();
	}
	std::cout << static_cast<char>(stoi(_operandStack[0]->toString())) << std::endl;
}

void OperandStackController::mExit() {
	exit(0);
}

const char *OperandStackController::StackTooShortException::what() const throw() {
	return "The stack is too short to perform part of this command.";
}

const char *OperandStackController::AssertFalseException::what() const throw() {
	return "The result of the assert operation is false.";
}
