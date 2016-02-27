//
// Created by Eric MANIEZ on 2/26/16.
//

#include "../../includes/classes/OperandFactory.hpp"
#include "../../includes/classes/operands/Int8.hpp"
#include "../../includes/classes/operands/Int16.hpp"
#include "../../includes/classes/operands/Int32.hpp"
#include "../../includes/classes/operands/Float.hpp"
#include "../../includes/classes/operands/Double.hpp"

IOperand const *OperandFactory::createOperand(eOperandType type, std::string const &value) const {
	IOperand const *ret = 0;

	try {
		ret = (*this.*_stringFunctions[type])(value);
		//ret = CALL_MEMBER_FN(*this, _stringFunctions[type])(value);
	} catch (Operand::OutOfRangeException &e) {
		std::cout << e.what() << " : submitted value is out of " << _names[type] << " range." << std::endl;
		exit(0);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
		exit(0);
	}

	return ret;
}

IOperand const *OperandFactory::createOperand(eOperandType type, long double const &value) const {
	IOperand const *ret = 0;

	try {
		ret = (*this.*_numberFunctions[type])(value);
		//ret = CALL_MEMBER_FN(*this, _numberFunctions[type])(value);
	} catch (Operand::OutOfRangeException &e) {
		std::cout << e.what() << " : calculated value is out of " << _names[type] << " range." << std::endl;
		exit(0);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
		exit(0);
	}

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
