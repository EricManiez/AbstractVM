//
// Created by Eric MANIEZ on 2/25/16.
//

#include "../../../includes/classes/operands/Int16.hpp"

Int16::Int16() : Operand("", eOperandType::Int16), _value(0) {}

Int16::Int16(long double val) : Operand(std::to_string(static_cast<int16_t>(val)), eOperandType::Int16) {
	std::cout << "int16 num construction : " << val << std::endl;
	//Check if value is in int16_t range
	if (INT16_MIN <= val && val <= INT16_MAX) {
		_value = static_cast<int16_t>(val);
	} else {
		throw OutOfRangeException();
	}
}

Int16::Int16(std::string val) : Operand(val, eOperandType::Int16) {
	//Attempt conversion from string to int16_t
	int convertedVal = std::stoi(val, 0, 0);

	//Check if value is in int8_t range
	if (INT16_MIN <= convertedVal && convertedVal <= INT16_MAX) {
		_value = static_cast<int16_t>(convertedVal);
	} else {
		throw OutOfRangeException();
	}
}

Int16::Int16(Int16 const &src) : Operand(src.toString(), eOperandType::Int16), _value(src.getValue()) {
	*this = src;
}

class Int16 &Int16::operator=(Int16 const &rhs) {
	this->_value = rhs.getValue();

	return *this;
}

const int16_t &Int16::getValue() const {
	return this->_value;
}