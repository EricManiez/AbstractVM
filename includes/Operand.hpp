//
// Created by Eric MANIEZ on 2/25/16.
//

#ifndef ABSTRACTVM_AOPERAND_HPP
#define ABSTRACTVM_AOPERAND_HPP


#include "IOperand.hpp"


class Operand : public IOperand
{
	typedef IOperand const *(Operand::*ClassCreationFunctionPointer)(long double num) const;

	public:
	Operand(Operand const &src);
	Operand &operator=(Operand const &rhs);

	virtual ~Operand(void) {}

	virtual std::string getStrValue() const;
	virtual int getPrecision(void) const;
	virtual eOperandType getType(void) const;
	virtual std::string const &toString(void) const;

	virtual IOperand const *operator+(IOperand const &rhs) const;
	virtual IOperand const *operator-(IOperand const &rhs) const;
	virtual IOperand const *operator*(IOperand const &rhs) const;
	virtual IOperand const *operator/(IOperand const &rhs) const;
	virtual IOperand const *operator%(IOperand const &rhs) const;

	class OutOfRangeException : public std::exception
	{
		public :
		OutOfRangeException() {};

		OutOfRangeException(OutOfRangeException const &) {};

		virtual ~OutOfRangeException() throw() {};
		OutOfRangeException const &operator=(OutOfRangeException const &);

		virtual const char *what() const throw();
	};

	protected:
	Operand(std::string, eOperandType);
	eOperandType choosePrecision(IOperand const &rhs) const;

	virtual IOperand const *createInt8(long double) const;
	virtual IOperand const *createInt16(long double) const;
	virtual IOperand const *createInt32(long double) const;
	virtual IOperand const *createFloat(long double) const;
	virtual IOperand const *createDouble(long double) const;

//	virtual int8_t getInt8Value() const;
//	virtual int16_t getInt16Value() const;
	virtual int32_t getInt32Value() const;
//	virtual float getFloatValue() const;
	virtual double getDoubleValue() const;

	std::string _strValue;
	eOperandType const _type;

	ClassCreationFunctionPointer _functions[5] = {
			&Operand::createInt8,
			&Operand::createInt16,
			&Operand::createInt32,
			&Operand::createFloat,
			&Operand::createDouble
	};

	private:
	Operand();
};

std::ostream &operator<<(std::ostream &o, class Int8 const &i);

#endif //ABSTRACTVM_AOPERAND_HPP
