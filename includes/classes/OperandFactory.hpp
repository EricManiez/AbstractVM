//
// Created by Eric MANIEZ on 2/26/16.
//

#ifndef ABSTRACTVM_OPERANDFACTORY_HPP
#define ABSTRACTVM_OPERANDFACTORY_HPP


#include <array>
#include "../IOperand.hpp"

class OperandFactory
{
	typedef IOperand const *(OperandFactory::*ClassCreationStringFunctionPointer)(std::string const &value) const;
	typedef IOperand const *(OperandFactory::*ClassCreationNumberFunctionPointer)(long double const &value) const;

	public:
	OperandFactory();
	OperandFactory(OperandFactory const &);
	OperandFactory const &operator=(OperandFactory const &rhs);
	~OperandFactory() {};

	const std::array<ClassCreationStringFunctionPointer, 5> &get_stringFunctions() const;
	const std::array<ClassCreationNumberFunctionPointer, 5> &get_numberFunctions() const;
	const std::array<std::string, 5> &get_names() const;

	IOperand const *createOperand(eOperandType type, std::string const &value) const;
	IOperand const *createOperand(eOperandType type, long double const &value) const;

	private:
	IOperand const *createInt8(std::string const &value) const;
	IOperand const *createInt16(std::string const &value) const;
	IOperand const *createInt32(std::string const &value) const;
	IOperand const *createFloat(std::string const &value) const;

	IOperand const *createDouble(std::string const &value) const;
	IOperand const *createInt8(long double const &value) const;
	IOperand const *createInt16(long double const &value) const;
	IOperand const *createInt32(long double const &value) const;
	IOperand const *createFloat(long double const &value) const;
	IOperand const *createDouble(long double const &value) const;

	std::array<ClassCreationStringFunctionPointer, 5> _stringFunctions;
	std::array<ClassCreationNumberFunctionPointer, 5> _numberFunctions;
	std::array<std::string, 5> _names;
};


#endif //ABSTRACTVM_OPERANDFACTORY_HPP
