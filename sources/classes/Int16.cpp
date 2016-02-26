//
// Created by Eric MANIEZ on 2/25/16.
//

#include "../../includes/classes/Int16.hpp"

Int16::Int16() : AOperand("", eOperandType::Int16, std::to_string(0)), _value(0) {}

Int16::Int16(long double val) : AOperand(
		std::to_string(static_cast<int16_t>(val)), eOperandType::Int16, std::to_string(static_cast<int16_t>(val))) {
	//Check if value is in int16_t range
	std::cout << "int16 construction : " << val << std::endl;
	if (val >= -32768 && val <= 32767) {
		_value = val;
	} else {
		throw OutOfRangeException();
	}
}

Int16::Int16(std::string val) : AOperand(val, eOperandType::Int16, val) {
	//Attempt conversion from string to int16_t
	int convertedVal = std::stoi(val, 0, 0);

	//Check if value is in int8_t range
	if (convertedVal >= -32768 && convertedVal <= 32767) {
		_value = convertedVal;
	} else {
		throw OutOfRangeException();
	}
}

Int16::Int16(Int16 const &src) : AOperand(src.toString(), eOperandType::Int16, src.toString()), _value(src.getValue()) {
	*this = src;
}

class Int16 &Int16::operator=(Int16 const &rhs) {
	this->_value = rhs.getValue();
	this->_toString = rhs.toString();

	return *this;
}

const int16_t &Int16::getValue() const {
	return this->_value;
}

int8_t Int16::getInt8Value() const {
	return static_cast<int8_t >(this->getValue());
}

int16_t Int16::getInt16Value() const {
	return static_cast<int16_t >(this->getValue());
}

int32_t Int16::getInt32Value() const {
	return static_cast<int32_t >(this->getValue());
}

float Int16::getFloatValue() const {
	return static_cast<float >(this->getValue());
}

double Int16::getDoubleValue() const {
	return static_cast<double >(this->getValue());
}
