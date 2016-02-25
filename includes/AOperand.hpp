//
// Created by Eric MANIEZ on 2/25/16.
//

#ifndef ABSTRACTVM_AOPERAND_HPP
#define ABSTRACTVM_AOPERAND_HPP


#include "IOperand.hpp"

class AOperand : public IOperand
{
	public:
	AOperand(AOperand const &src);
	AOperand &operator=(AOperand const &rhs);
	virtual ~AOperand(void) {}

	eOperandType choosePrecision(IOperand const &rhs) const;

	virtual int getPrecision(void) const;
	virtual eOperandType getType(void) const;
	virtual IOperand const *operator+(IOperand const &rhs) const;
	virtual IOperand const *operator-(IOperand const &rhs) const;
	virtual IOperand const *operator*(IOperand const &rhs) const;
	virtual IOperand const *operator/(IOperand const &rhs) const;
	virtual IOperand const *operator%(IOperand const &rhs) const;
	virtual std::string const &toString(void) const;

	virtual int8_t getInt8Value() const = 0;
	virtual int16_t getInt16Value() const = 0;
	virtual int32_t getInt32Value() const = 0;
	virtual float getFloatValue() const = 0;
	virtual double getDoubleValue() const = 0;

	protected:
	AOperand(eOperandType, std::string);
	eOperandType const _type;
	std::string _toString;

	private:
	AOperand();
};

std::ostream &operator<<(std::ostream &o, class Int8 const &i);

#endif //ABSTRACTVM_AOPERAND_HPP
