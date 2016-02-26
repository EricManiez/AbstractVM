//
// Created by Eric MANIEZ on 2/25/16.
//

#include "../../includes/classes/Double.hpp"

Double::Double() : AOperand("", eOperandType::Double, std::to_string(0)), _value(0) {}

Double::Double(long double val) : AOperand(
		std::to_string(static_cast<double>(val)), eOperandType::Double, std::to_string(static_cast<double>(val))) {
	//Check if value in range
	_value = std::stod(_toString);
}

Double::Double(std::string val) : AOperand(val, eOperandType::Double, val) {
	//Attempt conversion from string to double
	_value = std::stod(val);
}

Double::Double(Double const &src) : AOperand(src.toString(), eOperandType::Double, src.toString()), _value(src.getValue()) {
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
