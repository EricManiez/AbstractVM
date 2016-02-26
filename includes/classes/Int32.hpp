//
// Created by Eric MANIEZ on 2/25/16.
//

#ifndef ABSTRACTVM_INT32_HPP
#define ABSTRACTVM_INT32_HPP

#include "../AOperand.hpp"

class Int32 : public AOperand
{
	public:
	Int32(long double val);
	Int32(std::string val);
	Int32(Int32 const &src);
	Int32 &operator=(Int32 const &rhs);
	virtual ~Int32(void) {}

	virtual const int32_t &getValue() const;
	virtual int8_t getInt8Value() const;
	virtual int16_t getInt16Value() const;
	virtual int32_t getInt32Value() const;
	virtual float getFloatValue() const;
	virtual double getDoubleValue() const;

	private:
	Int32();
	int32_t _value;
};


#endif //ABSTRACTVM_INT32_HPP
