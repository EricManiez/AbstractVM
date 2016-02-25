//
// Created by Eric MANIEZ on 2/25/16.
//

#include <sstream>
#include "../includes/OperandTemplate.hpp"

template <typename T>
Operand(T t) : _value(t) {}
Operand::Operand(Operand const &src) {
	*this = src;
}

Operand &Operand::operator=(Operand const &rhs) {
	this->_value = rhs.getValue();

	return *this;
}

std::ostream &Operand::operator<<(std::ostream &o, Operand const &i) {
	o << this->toString();

	return o;
}

template <typename T>
T Operand::getValue() const {
	return this->_value;
}

int Operand::getPrecision(void) const {
	return 0;
}

eOperandType Operand::getType(void) const {
	return this->_type;
}

IOperand const *Operand::operator+(IOperand const &rhs) const {
	return nullptr;
}

IOperand const *Operand::operator-(IOperand const &rhs) const {
	return nullptr;
}

IOperand const *Operand::operator*(IOperand const &rhs) const {
	return nullptr;
}

IOperand const *Operand::operator/(IOperand const &rhs) const {
	return nullptr;
}

IOperand const *Operand::operator%(IOperand const &rhs) const {
	return nullptr;
}

std::string const &Operand::toString(void) const {
	if (this->_toString.empty()) {
		this->_toString = std::to_string(this->_value);
	}
	return this->_toString;
}
