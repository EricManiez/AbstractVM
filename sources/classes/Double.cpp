//
// Created by Eric MANIEZ on 2/25/16.
//

#include <float.h>
#include "../../includes/classes/Double.hpp"

Double::Double() : AOperand("", eOperandType::Double), _value(0) {}

Double::Double(long double val) : AOperand(std::to_string(static_cast<double>(val)), eOperandType::Double) {
	std::cout << "Double num construction : " << val << std::endl;
	//Check if value in range
	if (DBL_MIN <= val && val <= DBL_MAX) {
		_value = static_cast<double>(val);
	} else {
		throw AOperand::OutOfRangeException();
	}
}

Double::Double(std::string val) : AOperand(val, eOperandType::Double) {
	//Attempt conversion from string to double
	_value = std::stod(val);
}

Double::Double(Double const &src) : AOperand(src.toString(), eOperandType::Double), _value(src.getValue()) {
	*this = src;
}

class Double &Double::operator=(Double const &rhs) {
	this->_value = rhs.getValue();

	return *this;
}

const double &Double::getValue() const {
	return this->_value;
}
