//
// Created by Eric MANIEZ on 2/25/16.
//

#ifndef ABSTRACTVM_AOPERAND_HPP
#define ABSTRACTVM_AOPERAND_HPP


#include "IOperand.hpp"


class AOperand : public IOperand
{
	typedef IOperand const *(AOperand::*ClassCreationFunctionPointer)(long double num) const;

	public:
	AOperand(AOperand const &src);
	AOperand &operator=(AOperand const &rhs);

	virtual ~AOperand(void) {}

	eOperandType choosePrecision(IOperand const &rhs) const;

	virtual std::string getStrValue() const;
	virtual int getPrecision(void) const;
	virtual eOperandType getType(void) const;

	virtual IOperand const *createInt8(long double) const;
	virtual IOperand const *createInt16(long double) const;
	virtual IOperand const *createInt32(long double) const;
	virtual IOperand const *createFloat(long double) const;
	virtual IOperand const *createDouble(long double) const;

	ClassCreationFunctionPointer _functions[5] = {
			&AOperand::createInt8,
			&AOperand::createInt16,
			&AOperand::createInt32,
			&AOperand::createFloat,
			&AOperand::createDouble
	};

	virtual IOperand const *operator+(IOperand const &rhs) const;
	virtual IOperand const *operator-(IOperand const &rhs) const;
	virtual IOperand const *operator*(IOperand const &rhs) const;
	virtual IOperand const *operator/(IOperand const &rhs) const;
	virtual IOperand const *operator%(IOperand const &rhs) const;
	virtual std::string const &toString(void) const;

	class OutOfRangeException : public std::exception
	{
		public :
		OutOfRangeException() {};

		OutOfRangeException(OutOfRangeException const &) {};

		virtual ~OutOfRangeException() throw() {};
		OutOfRangeException const &operator=(OutOfRangeException const &);

		virtual const char *what() const throw();
	};

	virtual int8_t getInt8Value() const;
	virtual int16_t getInt16Value() const;
	virtual int32_t getInt32Value() const;
	virtual float getFloatValue() const;
	virtual double getDoubleValue() const;

	protected:
	AOperand(std::string, eOperandType);
	std::string _strValue;
	eOperandType const _type;

	private:
	AOperand();
};

std::ostream &operator<<(std::ostream &o, class Int8 const &i);

#endif //ABSTRACTVM_AOPERAND_HPP
