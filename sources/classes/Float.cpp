//
// Created by Eric MANIEZ on 2/25/16.
//

#include "../../includes/classes/Float.hpp"

Float::Float() : AOperand("", eOperandType::Float, std::to_string(0)), _value(0) {}

Float::Float(long double val) : AOperand(
		std::to_string(static_cast<float>(val)), eOperandType::Float, std::to_string(static_cast<float>(val))) {
	//Check if value in range
	_value = std::stof(_toString);
}

Float::Float(std::string val) : AOperand(val, eOperandType::Float, val) {
	//Attempt conversion from string to float
	_value = std::stof(val);
}

Float::Float(Float const &src) : AOperand(src.toString(), eOperandType::Float, src.toString()), _value(src.getValue()) {
	*this = src;
}

class Float &Float::operator=(Float const &rhs) {
	this->_value = rhs.getValue();
	this->_toString = rhs.toString();

	return *this;
}

const float &Float::getValue() const {
	return this->_value;
}
