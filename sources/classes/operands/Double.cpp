//
// Created by Eric MANIEZ on 2/25/16.
//

#include <float.h>
#include "../../../includes/classes/operands/Double.hpp"

Double::Double() : Operand("", eOperandType::Double), _value(0) {}

Double::Double(long double val) : Operand(std::to_string(static_cast<double>(val)), eOperandType::Double) {
	std::cout << "Double num construction : " << val << std::endl;
	//Check if value in range
	if (val < DBL_MIN) {
		throw std::underflow_error("[UNDERFLOW] : " +_strValue + " is too low for double type");
	} else if (val > DBL_MAX) {
		throw std::overflow_error("[OVERFLOW] : " + _strValue + " is too high for double type");
	} else {
		_value = static_cast<double>(val);
	}
}

Double::Double(std::string val) : Operand(val, eOperandType::Double) {
	//Attempt conversion from string to double
	_value = std::stod(val);
	std::cout << "double string construction : " << _value << std::endl;
}

Double::Double(Double const &src) : Operand(src.toString(), eOperandType::Double), _value(src.getValue()) {
	*this = src;
}

class Double &Double::operator=(Double const &rhs) {
	this->_value = rhs.getValue();

	return *this;
}

const double &Double::getValue() const {
	return this->_value;
}
