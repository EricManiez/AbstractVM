//
// Created by Eric MANIEZ on 2/25/16.
//

#include "../../includes/classes/Int8.hpp"

Int8::Int8() : _value(0), AOperand(eOperandType::Int8, std::to_string(0)) {}

Int8::Int8(int8_t val) : _value(val), AOperand(eOperandType::Int8, std::to_string(val)) {}

Int8::Int8(Int8 const &src) : _value(src.getValue()), AOperand(eOperandType::Int8, std::to_string(src.getValue())) {
	*this = src;
}
class Int8 &Int8::operator=(Int8 const &rhs) {
	this->_value = rhs.getValue();
	this->_toString = rhs.toString();

	return *this;
}

const int8_t &Int8::getValue() const {
	return this->_value;
}
