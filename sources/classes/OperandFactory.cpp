//
// Created by Eric MANIEZ on 2/26/16.
//

#include "../../includes/classes/OperandFactory.hpp"
#include "../../includes/classes/operands/Int8.hpp"
#include "../../includes/classes/operands/Int16.hpp"
#include "../../includes/classes/operands/Int32.hpp"
#include "../../includes/classes/operands/Float.hpp"
#include "../../includes/classes/operands/Double.hpp"

typedef IOperand const *(OperandFactory::*ClassCreationStringFunctionPointer)(std::string const &value) const;
typedef IOperand const *(OperandFactory::*ClassCreationNumberFunctionPointer)(long double const &value) const;

OperandFactory::OperandFactory() {
	_numberFunctions[0] = &OperandFactory::createInt8;
	_numberFunctions[1] = &OperandFactory::createInt16;
	_numberFunctions[2] = &OperandFactory::createInt32;
	_numberFunctions[3] = &OperandFactory::createFloat;
	_numberFunctions[4] = &OperandFactory::createDouble;
	_stringFunctions[0] = &OperandFactory::createInt8;
	_stringFunctions[1] = &OperandFactory::createInt16;
	_stringFunctions[2] = &OperandFactory::createInt32;
	_stringFunctions[3] = &OperandFactory::createFloat;
	_stringFunctions[4] = &OperandFactory::createDouble;
	_names[0] = "Int8";
	_names[1] = "Int16";
	_names[2] = "Int32";
	_names[3] = "Float";
	_names[4] = "Double";
}

OperandFactory::OperandFactory(const OperandFactory &factory) :
		_stringFunctions(factory.get_stringFunctions()),
		_numberFunctions(factory.get_numberFunctions()),
		_names(factory.get_names()) {}

OperandFactory const &OperandFactory::operator=(OperandFactory const &rhs) {
	_stringFunctions = rhs.get_stringFunctions();
	_numberFunctions = rhs.get_numberFunctions();
	_names = rhs.get_names();

	return *this;
}

const std::array<ClassCreationStringFunctionPointer, 5> &OperandFactory::get_stringFunctions() const {
	return _stringFunctions;
}

const std::array<ClassCreationNumberFunctionPointer, 5> &OperandFactory::get_numberFunctions() const {
	return _numberFunctions;
}

const std::array<std::string, 5> &OperandFactory::get_names() const {
	return _names;
}

IOperand const *OperandFactory::createOperand(eOperandType type, std::string const &value) const {
	IOperand const *ret = 0;

	ret = (*this.*_stringFunctions[type])(value);
	//ret = CALL_MEMBER_FN(*this, _stringFunctions[type])(value);

	return ret;
}

IOperand const *OperandFactory::createOperand(eOperandType type, long double const &value) const {
	IOperand const *ret = 0;

	ret = (*this.*_numberFunctions[type])(value);
	//ret = CALL_MEMBER_FN(*this, _numberFunctions[type])(value);

	return ret;
}

IOperand const *OperandFactory::createInt8(std::string const &value) const {
	return new class Int8(value);
}

IOperand const *OperandFactory::createInt16(std::string const &value) const {
	return new class Int16(value);
}

IOperand const *OperandFactory::createInt32(std::string const &value) const {
	return new class Int32(value);
}

IOperand const *OperandFactory::createFloat(std::string const &value) const {
	return new class Float(value);
}

IOperand const *OperandFactory::createDouble(std::string const &value) const {
	return new class Double(value);
}

IOperand const *OperandFactory::createInt8(long double const &value) const {
	return new class Int8(value);
}

IOperand const *OperandFactory::createInt16(long double const &value) const {
	return new class Int16(value);
}

IOperand const *OperandFactory::createInt32(long double const &value) const {
	return new class Int32(value);
}

IOperand const *OperandFactory::createFloat(long double const &value) const {
	return new class Float(value);
}

IOperand const *OperandFactory::createDouble(long double const &value) const {
	return new class Double(value);
}
