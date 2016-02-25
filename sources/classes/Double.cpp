//
// Created by Eric MANIEZ on 2/25/16.
//

#include "../../includes/classes/Double.hpp"

Double::Double() : _value(0), AOperand(eOperandType::Double, std::to_string(0)) {}

Double::Double(double val) : _value(val), AOperand(eOperandType::Double, std::to_string(val)) {}

Double::Double(Double const &src) : _value(src.getValue()), AOperand(eOperandType::Double, std::to_string(src.getValue())) {
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
