//
// Created by Eric MANIEZ on 2/25/16.
//

#include <array>
#include "../../includes/AOperand.hpp"
#include "../../includes/classes/Int8.hpp"
#include "../../includes/classes/Int16.hpp"
#include "../../includes/classes/Int32.hpp"
#include "../../includes/classes/Float.hpp"
#include "../../includes/classes/Double.hpp"

AOperand::AOperand() : _value(""), _type(eOperandType::Int8), _toString("") {}

AOperand::AOperand(std::string val, eOperandType type, std::string str) : _value(val), _type(type), _toString(str) {}

AOperand::AOperand(AOperand const &src) : _type(src.getType()), _toString(src.toString()) {}

AOperand &AOperand::operator=(AOperand const &rhs) {
	this->_toString = rhs.toString();

	return *this;
}

eOperandType AOperand::choosePrecision(IOperand const &rhs) const {
	return rhs.getPrecision() >= this->getPrecision() ? rhs.getType() : this->getType();
}

std::string AOperand::getValue() {
	return this->_value;
}

int AOperand::getPrecision(void) const {
	return this->getType();
}

eOperandType AOperand::getType(void) const {
	return this->_type;
}

IOperand const *AOperand::createInt8(long double d) const {
	IOperand const *ret = new class Int8(d);
	return ret;
}

IOperand const *AOperand::createInt16(long double d) const {
	IOperand const *ret = new class Int16(d);
	return ret;
}

IOperand const *AOperand::createInt32(long double d) const {
	IOperand const *ret = new class Int32(d);
	return ret;
}

IOperand const *AOperand::createFloat(long double d) const {
	IOperand const *ret = new class Float(d);
	return ret;
}

IOperand const *AOperand::createDouble(long double d) const {
	IOperand const *ret = new class Double(d);
	return ret;
}

IOperand const *AOperand::operator+(IOperand const &rhs) const {
	std::cout << "+ operator" << std::endl;
	long double op = this->getDoubleValue() + static_cast<class Double const *>(std::addressof(rhs))->getDoubleValue();

	return (this->*_functions[this->choosePrecision(rhs)])(op);
//	return CALL_MEMBER_FN(*this, _functions[3])(op);
}

IOperand const *AOperand::operator-(IOperand const &rhs) const {
	std::cout << "- operator" << std::endl;
	long double op = this->getDoubleValue() - static_cast<class Double const *>(std::addressof(rhs))->getDoubleValue();

	return (this->*_functions[this->choosePrecision(rhs)])(op);
//	return CALL_MEMBER_FN(*this, _functions[3])(op);
}

IOperand const *AOperand::operator*(IOperand const &rhs) const {
	std::cout << "* operator" << std::endl;
	long double op = this->getDoubleValue() * static_cast<class Double const *>(std::addressof(rhs))->getDoubleValue();

	return (this->*_functions[this->choosePrecision(rhs)])(op);
//	return CALL_MEMBER_FN(*this, _functions[3])(op);
}

IOperand const *AOperand::operator/(IOperand const &rhs) const {
	std::cout << "/ operator" << std::endl;
	long double op = this->getDoubleValue() / static_cast<class Double const *>(std::addressof(rhs))->getDoubleValue();

	return (this->*_functions[this->choosePrecision(rhs)])(op);
//	return CALL_MEMBER_FN(*this, _functions[3])(op);
}

IOperand const *AOperand::operator%(IOperand const &rhs) const {
	std::cout << "% operator" << std::endl;
	long double op = this->getInt32Value() % static_cast<class Int32 const *>(std::addressof(rhs))->getInt32Value();

	return (this->*_functions[this->choosePrecision(rhs)])(op);
//	return CALL_MEMBER_FN(*this, _functions[3])(op);
}

std::string const &AOperand::toString(void) const {
	return _toString;
}

const char *AOperand::OutOfRangeException::what() const throw() {
	return "Submitted value is out of expected range!";
}
