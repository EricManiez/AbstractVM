//
// Created by Eric MANIEZ on 2/25/16.
//

#include "../../includes/classes/Int32.hpp"

Int32::Int32() : Operand("", eOperandType::Int32), _value(0) {}

Int32::Int32(long double val) : Operand(std::to_string(static_cast<int32_t>(val)), eOperandType::Int32) {
	std::cout << "int32 num construction : " << val << std::endl;
	//Check if value in range
	if (INT_MIN <= val && val <= INT_MAX) {
		_value = static_cast<int32_t>(val);
	} else {
		throw Operand::OutOfRangeException();
	}
}

Int32::Int32(std::string val) : Operand(val, eOperandType::Int32) {
	//Attempt conversion from string to int32_t
	_value = std::stoi(val, 0, 0);
}

Int32::Int32(Int32 const &src) : Operand(src.toString(), eOperandType::Int32), _value(src.getValue()) {
	*this = src;
}

class Int32 &Int32::operator=(Int32 const &rhs) {
	this->_value = rhs.getValue();

	return *this;
}

const int32_t &Int32::getValue() const {
	return this->_value;
}
