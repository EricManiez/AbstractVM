//
// Created by Eric MANIEZ on 2/25/16.
//

#include "../../includes/classes/Int32.hpp"

Int32::Int32() : AOperand("", eOperandType::Int32, std::to_string(0)), _value(0) {}

Int32::Int32(long double val) : AOperand(
		std::to_string(static_cast<int32_t>(val)), eOperandType::Int32, std::to_string(static_cast<int32_t>(val))) {
	//Check if value in range
	_value = std::stoi(_toString);
}

Int32::Int32(std::string val) : AOperand(val, eOperandType::Int32, val) {
	//Attempt conversion from string to int32_t
	_value = std::stoi(val, 0, 0);
}

Int32::Int32(Int32 const &src) : AOperand(src.toString(), eOperandType::Int32, src.toString()), _value(src.getValue()) {
	*this = src;
}

class Int32 &Int32::operator=(Int32 const &rhs) {
	this->_value = rhs.getValue();
	this->_toString = rhs.toString();

	return *this;
}

const int32_t &Int32::getValue() const {
	return this->_value;
}
