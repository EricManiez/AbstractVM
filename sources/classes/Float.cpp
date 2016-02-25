//
// Created by Eric MANIEZ on 2/25/16.
//

#include "../../includes/classes/Float.hpp"

Float::Float() : AOperand(eOperandType::Float, std::to_string(0)), _value(0) {}

Float::Float(float val) : AOperand(eOperandType::Float, std::to_string(val)), _value(val) {}

Float::Float(Float const &src) : AOperand(eOperandType::Float, std::to_string(src.getValue())), _value(src.getValue()) {
	*this = src;
}

class Float &Float::operator=(Float const &rhs) {
	this->_value = rhs.getValue();
	this->_toString = rhs.toString();

	return *this;
}

const float &Float::getValue() const {
	return this->_value;
}

int8_t Float::getInt8Value() const {
	return static_cast<int8_t>(this->getValue());
}

int16_t Float::getInt16Value() const {
	return static_cast<int16_t>(this->getValue());
}

int32_t Float::getInt32Value() const {
	return static_cast<int32_t>(this->getValue());
}

float Float::getFloatValue() const {
	return static_cast<float>(this->getValue());
}

double Float::getDoubleValue() const {
	return static_cast<double>(this->getValue());
}
