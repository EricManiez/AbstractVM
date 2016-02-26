//
// Created by Eric MANIEZ on 2/25/16.
//

#include "../../includes/classes/Int8.hpp"

Int8::Int8() : AOperand("", eOperandType::Int8, std::to_string(0)), _value(0) {}

Int8::Int8(long double val) : AOperand(
		std::to_string(static_cast<int8_t>(val)), eOperandType::Int8, std::to_string(static_cast<int8_t>(val))) {
	//Check if value is in int16_t range
	std::cout << "int8 construction : " << val << std::endl;
	if (val >= -128 && val <= 127) {
		_value = val;
	} else {
		throw OutOfRangeException();
	}
}

Int8::Int8(std::string val) : AOperand(val, eOperandType::Int8, val) {
	//Attempt conversion from string to int8_t
	int convertedVal = std::stoi(val, 0, 0);

	//Check if value is in int8_t range
	if (convertedVal >= -128 && convertedVal <= 127) {
		_value = convertedVal;
	} else {
		throw OutOfRangeException();
	}
}

Int8::Int8(Int8 const &src) : AOperand(src.toString(), eOperandType::Int8, src.toString()), _value(src.getValue()) {
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
