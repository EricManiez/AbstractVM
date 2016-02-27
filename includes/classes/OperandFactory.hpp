//
// Created by Eric MANIEZ on 2/26/16.
//

#ifndef ABSTRACTVM_OPERANDFACTORY_HPP
#define ABSTRACTVM_OPERANDFACTORY_HPP


#include "../IOperand.hpp"

class OperandFactory
{
	typedef IOperand const *(OperandFactory::*ClassCreationStringFunctionPointer)(std::string const &value) const;
	typedef IOperand const *(OperandFactory::*ClassCreationNumberFunctionPointer)(long double const &value) const;

	public:
	OperandFactory() {};
	~OperandFactory() {};

	IOperand const *createOperand(eOperandType type, std::string const &value) const;
	IOperand const *createOperand(eOperandType type, long double const &value) const;

	private:
	IOperand const *createInt8(std::string const &value) const;
	IOperand const *createInt16(std::string const &value) const;
	IOperand const *createInt32(std::string const &value) const;
	IOperand const *createFloat(std::string const &value) const;
	IOperand const *createDouble(std::string const &value) const;

	const ClassCreationStringFunctionPointer _stringFunctions[5] = {
			&OperandFactory::createInt8,
			&OperandFactory::createInt16,
			&OperandFactory::createInt32,
			&OperandFactory::createFloat,
			&OperandFactory::createDouble
	};

	IOperand const *createInt8(long double const &value) const;
	IOperand const *createInt16(long double const &value) const;
	IOperand const *createInt32(long double const &value) const;
	IOperand const *createFloat(long double const &value) const;
	IOperand const *createDouble(long double const &value) const;

	const ClassCreationNumberFunctionPointer _numberFunctions[5] = {
			&OperandFactory::createInt8,
			&OperandFactory::createInt16,
			&OperandFactory::createInt32,
			&OperandFactory::createFloat,
			&OperandFactory::createDouble
	};

	std::string _names[5] = {
			"Int8",
			"Int16",
			"Int32",
			"Float",
			"Double"
	};
};


#endif //ABSTRACTVM_OPERANDFACTORY_HPP
