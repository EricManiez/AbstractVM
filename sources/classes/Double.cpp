//
// Created by Eric MANIEZ on 2/25/16.
//

#include "../../includes/classes/Double.hpp"

Double::Double() : AOperand(eOperandType::Double, std::to_string(0)), _value(0) {}

Double::Double(double val) : AOperand(eOperandType::Double, std::to_string(val)), _value(val) {}

Double::Double(Double const &src) : AOperand(eOperandType::Double, std::to_string(src.getValue())), _value(src.getValue()) {
	*this = src;
}

class Double &Double::operator=(Double const &rhs) {
	this->_value = rhs.getValue();
	this->_toString = rhs.toString();

	return *this;
}

const double &Double::getValue() const {
	return this->_value;
}

int8_t Double::getInt8Value() const {
	return static_cast<int8_t >(this->getValue());
}

int16_t Double::getInt16Value() const {
	return static_cast<int16_t >(this->getValue());
}

int32_t Double::getInt32Value() const {
	return static_cast<int32_t >(this->getValue());
}

float Double::getFloatValue() const {
	return static_cast<float >(this->getValue());
}

double Double::getDoubleValue() const {
	return static_cast<double >(this->getValue());
}
