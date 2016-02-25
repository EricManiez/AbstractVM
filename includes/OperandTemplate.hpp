//
// Created by Eric MANIEZ on 2/25/16.
//

#ifndef ABSTRACTVM_OPERANDTEMPLATE_HPP
#define ABSTRACTVM_OPERANDTEMPLATE_HPP

#include "AbstractVM.hpp"
#include "IOperand.hpp"

template<typename T>
class Operand : public IOperand
{
	public:
	Operand(T);
	Operand(Operand const &src);
	Operand &operator=(Operand const &rhs);
	virtual ~Operand(void) {}
	std::ostream &operator<<(std::ostream &o, Operand const &i);

	const T &getValue() const;

	virtual int getPrecision(void) const;
	virtual eOperandType getType(void) const;
	virtual IOperand const *operator+(IOperand const &rhs) const;
	virtual IOperand const *operator-(IOperand const &rhs) const;
	virtual IOperand const *operator*(IOperand const &rhs) const;
	virtual IOperand const *operator/(IOperand const &rhs) const;
	virtual IOperand const *operator%(IOperand const &rhs) const;

	virtual std::string const &toString(void) const;

	private:
	Operand() {};
	T _value;
	eOperandType _type;
	std::string _toString;
};

#endif //ABSTRACTVM_OPERANDTEMPLATE_HPP
