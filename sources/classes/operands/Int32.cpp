//
// Created by Eric MANIEZ on 2/25/16.
//

#include "../../../includes/classes/operands/Int32.hpp"

Int32::Int32() : Operand("", eOperandType::Int32), _value(0) {}

Int32::Int32(long double val) : Operand(std::to_string(static_cast<int32_t>(val)), eOperandType::Int32) {
	if (DEBUG) {
		std::cout << "int32 num construction : " << val << std::endl;
	}
	//Check if value in range
	if (val < INT_MIN) {
		throw std::underflow_error("[UNDERFLOW] : " + std::to_string(val) + " is too low for int32 type");
	} else if (val > INT_MAX) {
		throw std::overflow_error("[OVERFLOW] : " + std::to_string(val) + " is too high for int32 type");
	} else {
		_value = static_cast<int32_t>(val);
	}
}

Int32::Int32(std::string val) : Operand(val, eOperandType::Int32) {
	//Attempt conversion from string to int32_t
	_value = std::stoi(val, 0, 0);
	if (DEBUG) {
		std::cout << "int32 string construction : " << _value << std::endl;
	}
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
