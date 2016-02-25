//
// Created by Eric MANIEZ on 2/25/16.
//

#include "../../includes/classes/Int16.hpp"

Int16::Int16() : AOperand(eOperandType::Int16, std::to_string(0)), _value(0) {}

Int16::Int16(int16_t val) : AOperand(eOperandType::Int16, std::to_string(val)), _value(val) {}

Int16::Int16(Int16 const &src) : AOperand(eOperandType::Int16, std::to_string(src.getValue())), _value(src.getValue()) {
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
