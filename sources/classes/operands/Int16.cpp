//
// Created by Eric MANIEZ on 2/25/16.
//

#include "../../../includes/classes/operands/Int16.hpp"

Int16::Int16() : Operand("", eOperandType::Int16), _value(0) {}

Int16::Int16(long double val) : Operand(std::to_string(static_cast<int16_t>(val)), eOperandType::Int16) {
	std::cout << "int16 num construction : " << val << std::endl;
	//Check if value is in int16_t range
	if (val < INT16_MIN) {
		throw std::underflow_error("[UNDERFLOW] : " +_strValue + " is too low for int16 type");
	} else if (val > INT16_MAX) {
		throw std::overflow_error("[OVERFLOW] : " + _strValue + " is too high for int16 type");
	} else {
		_value = static_cast<int16_t>(val);
	}
}

Int16::Int16(std::string val) : Operand(val, eOperandType::Int16) {
	//Attempt conversion from string to int16_t
	int convertedVal = std::stoi(val, 0, 0);
	std::cout << "int16 string construction : " << convertedVal << std::endl;

	//Check if value is in int8_t range
	if (convertedVal < INT16_MIN) {
		throw std::underflow_error("[UNDERFLOW] : " +_strValue + " is too low for int16 type");
	} else if (convertedVal > INT16_MAX) {
		throw std::overflow_error("[OVERFLOW] : " + _strValue + " is too high for int16 type");
	} else {
		_value = static_cast<int16_t>(convertedVal);
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
