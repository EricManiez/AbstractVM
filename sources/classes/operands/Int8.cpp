//
// Created by Eric MANIEZ on 2/25/16.
//

#include "../../../includes/classes/operands/Int8.hpp"

Int8::Int8() : Operand("", eOperandType::Int8), _value(0) {}

Int8::Int8(long double val) : Operand(std::to_string(static_cast<int8_t>(val)), eOperandType::Int8) {
	std::cout << "int8 num construction : " << val << std::endl;
	//Check if value is in int16_t range
	if (INT8_MIN <= val && val <= INT8_MAX) {
		_value = static_cast<int8_t>(val);
	} else {
		throw OutOfRangeException();
	}
}

Int8::Int8(std::string val) : Operand(val, eOperandType::Int8) {
	//Attempt conversion from string to int8_t
	int convertedVal = std::stoi(val, 0, 0);

	//Check if value is in int8_t range
	if (INT8_MIN <= convertedVal && convertedVal <= INT8_MAX) {
		_value = static_cast<int8_t>(convertedVal);
	} else {
		throw OutOfRangeException();
	}
}

Int8::Int8(Int8 const &src) : Operand(src.toString(), eOperandType::Int8), _value(src.getValue()) {
	*this = src;
}

class Int8 &Int8::operator=(Int8 const &rhs) {
	this->_value = rhs.getValue();

	return *this;
}

const int8_t &Int8::getValue() const {
	return this->_value;
}
