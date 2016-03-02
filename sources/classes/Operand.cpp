//
// Created by Eric MANIEZ on 2/25/16.
//

#include <array>
#include <sstream>
#include "../../includes/classes/Operand.hpp"
#include "../../includes/classes/operands/Int8.hpp"
#include "../../includes/classes/operands/Int16.hpp"
#include "../../includes/classes/operands/Int32.hpp"
#include "../../includes/classes/operands/Float.hpp"
#include "../../includes/classes/operands/Double.hpp"
#include "../../includes/classes/OperandFactory.hpp"

Operand::Operand() : _strValue(""), _type(eOperandType::Int8) {}

Operand::Operand(std::string val, eOperandType type) : _type(type) {
	std::stringstream sstream;

	if (type == eOperandType::Int8 ||type == eOperandType::Int16 ||type == eOperandType::Int32) {
		sstream << stoi(val, 0, 0);
	} else if (type == eOperandType::Float) {
		sstream << stof(val);
	} else if (type == eOperandType::Double) {
		sstream << stod(val);
	}

	_strValue = sstream.str();
}

Operand::Operand(Operand const &src) : _type(src.getType()) {}

Operand &Operand::operator=(Operand const &rhs) {
	this->_strValue = rhs.getStrValue();

	return *this;
}

eOperandType Operand::choosePrecision(IOperand const &rhs) const {
	return rhs.getPrecision() >= this->getPrecision() ? rhs.getType() : this->getType();
}

std::string Operand::getStrValue() const {
	return this->_strValue;
}

int Operand::getPrecision(void) const {
	return this->getType();
}

eOperandType Operand::getType(void) const {
	return this->_type;
}

IOperand const *Operand::operator+(IOperand const &rhs) const {
	std::cout << "+ operator" << std::endl;

	OperandFactory factory;
	long double op = this->getDoubleValue() + static_cast<class Double const *>(std::addressof(rhs))->getDoubleValue();

	return factory.createOperand(choosePrecision(rhs), op);
}

IOperand const *Operand::operator-(IOperand const &rhs) const {
	std::cout << "- operator" << std::endl;

	OperandFactory factory;
	long double op = this->getDoubleValue() - static_cast<class Double const *>(std::addressof(rhs))->getDoubleValue();

	return factory.createOperand(choosePrecision(rhs), op);
}

IOperand const *Operand::operator*(IOperand const &rhs) const {
	std::cout << "* operator" << std::endl;

	OperandFactory factory;
	long double op = this->getDoubleValue() * static_cast<class Double const *>(std::addressof(rhs))->getDoubleValue();

	return factory.createOperand(choosePrecision(rhs), op);
}

IOperand const *Operand::operator/(IOperand const &rhs) const {
	std::cout << "/ operator" << std::endl;

	OperandFactory factory;
	long double op = this->getDoubleValue() / static_cast<class Double const *>(std::addressof(rhs))->getDoubleValue();

	return factory.createOperand(choosePrecision(rhs), op);
}

IOperand const *Operand::operator%(IOperand const &rhs) const {
	std::cout << "% operator" << std::endl;

	OperandFactory factory;
	long double op = this->getInt32Value() % static_cast<class Int32 const *>(std::addressof(rhs))->getInt32Value();

	return factory.createOperand(choosePrecision(rhs), op);
}

std::string const &Operand::toString(void) const {
	return _strValue;
}

//int8_t AOperand::getInt8Value() const {
//	return std::stoi(this->_strValue);
//}

//int16_t AOperand::getInt16Value() const {
//	return std::stoi(this->_strValue);
//}

int32_t Operand::getInt32Value() const {
	return std::stoi(this->_strValue);
}

//float AOperand::getFloatValue() const {
//	return std::stof(this->_strValue);
//}

double Operand::getDoubleValue() const {
	return std::stod(this->_strValue);
}

std::ostream &operator<<(std::ostream &o, class Int8 const &i) {
	o << i.toString();

	return o;
}

bool Operand::operator==(IOperand const &rhs) const {
	std::cout << "==" << std::endl;
	return (getType() == rhs.getType()) && (toString() == rhs.toString());
}
bool Operand::operator!=(IOperand const &rhs) const {
	std::cout << "!=" << std::endl;
	return (getType() != rhs.getType()) || (toString() != rhs.toString());
}
