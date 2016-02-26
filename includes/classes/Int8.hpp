//
// Created by Eric MANIEZ on 2/25/16.
//

#ifndef ABSTRACTVM_INT8_HPP
#define ABSTRACTVM_INT8_HPP

#include "../AOperand.hpp"

class Int8 : public AOperand
{
	public:
	Int8(long double val);
	Int8(std::string val);
	Int8(Int8 const &src);
	Int8 &operator=(Int8 const &rhs);
	virtual ~Int8(void) {}

	virtual const int8_t &getValue() const;
	virtual int8_t getInt8Value() const;
	virtual int16_t getInt16Value() const;
	virtual int32_t getInt32Value() const;
	virtual float getFloatValue() const;
	virtual double getDoubleValue() const;

	private:
	Int8();
	int8_t _value;
};

#endif //ABSTRACTVM_INT8_HPP
