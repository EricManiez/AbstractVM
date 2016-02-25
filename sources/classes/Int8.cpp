//
// Created by Eric MANIEZ on 2/25/16.
//

#include "../../includes/classes/Int8.hpp"

Int8::Int8() : AOperand(eOperandType::Int8, std::to_string(0)), _value(0) {}

Int8::Int8(int8_t val) : AOperand(eOperandType::Int8, std::to_string(val)), _value(val) {}

Int8::Int8(Int8 const &src) : AOperand(eOperandType::Int8, std::to_string(src.getValue())), _value(src.getValue()) {
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

int8_t Int8::getInt8Value() const {
	return static_cast<int8_t >(this->getValue());
}

int16_t Int8::getInt16Value() const {
	return static_cast<int16_t >(this->getValue());
}

int32_t Int8::getInt32Value() const {
	return static_cast<int32_t >(this->getValue());
}

float Int8::getFloatValue() const {
	return static_cast<float >(this->getValue());
}

double Int8::getDoubleValue() const {
	return static_cast<double >(this->getValue());
}
