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

AOperand::AOperand() : _strValue(""), _type(eOperandType::Int8) {}

AOperand::AOperand(std::string val, eOperandType type) : _strValue(val), _type(type) {}

AOperand::AOperand(AOperand const &src) : _type(src.getType()) {}

AOperand &AOperand::operator=(AOperand const &rhs) {
	this->_strValue = rhs.getStrValue();

	return *this;
}

eOperandType AOperand::choosePrecision(IOperand const &rhs) const {
	return rhs.getPrecision() >= this->getPrecision() ? rhs.getType() : this->getType();
}

std::string AOperand::getStrValue() const {
	return this->_strValue;
}

int AOperand::getPrecision(void) const {
	return this->getType();
}

eOperandType AOperand::getType(void) const {
	return this->_type;
}

IOperand const *AOperand::createInt8(long double d) const {
	return new class Int8(d);
}

IOperand const *AOperand::createInt16(long double d) const {
	return new class Int16(d);
}

IOperand const *AOperand::createInt32(long double d) const {
	return new class Int32(d);
}

IOperand const *AOperand::createFloat(long double d) const {
	return new class Float(d);
}

IOperand const *AOperand::createDouble(long double d) const {
	return new class Double(d);
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
	return _strValue;
}

const char *AOperand::OutOfRangeException::what() const throw() {
	return "Submitted value is out of expected range!";
}

//int8_t AOperand::getInt8Value() const {
//	return std::stoi(this->_strValue);
//}

//int16_t AOperand::getInt16Value() const {
//	return std::stoi(this->_strValue);
//}

int32_t AOperand::getInt32Value() const {
	return std::stoi(this->_strValue);
}

//float AOperand::getFloatValue() const {
//	return std::stof(this->_strValue);
//}

double AOperand::getDoubleValue() const {
	return std::stod(this->_strValue);
}

std::ostream &operator<<(std::ostream &o, class Int8 const &i) {
	o << i.toString();

	return o;
}