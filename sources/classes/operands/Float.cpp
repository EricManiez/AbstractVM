//
// Created by Eric MANIEZ on 2/25/16.
//

#include <float.h>
#include "../../../includes/classes/operands/Float.hpp"

Float::Float() : Operand("", eOperandType::Float), _value(0) {}

Float::Float(long double val) : Operand(std::to_string(static_cast<float>(val)), eOperandType::Float) {
	std::cout << "Float num construction : " << val << std::endl;
	//Check if value in range
	if (val < FLT_MIN) {
		throw std::underflow_error("[UNDERFLOW] : " +std::to_string(val) + " is too low for float type");
	} else if (val > FLT_MAX) {
		throw std::overflow_error("[OVERFLOW] : " + std::to_string(val) + " is too high for float type");
	} else {
		_value = static_cast<float>(val);
	}
}

Float::Float(std::string val) : Operand(val, eOperandType::Float) {
	//Attempt conversion from string to float
	_value = std::stof(val);
	std::cout << "float string construction : " << _value << std::endl;
}

Float::Float(Float const &src) : Operand(src.toString(), eOperandType::Float), _value(src.getValue()) {
	*this = src;
}

class Float &Float::operator=(Float const &rhs) {
	this->_value = rhs.getValue();

	return *this;
}

const float &Float::getValue() const {
	return this->_value;
}
