//
// Created by Eric MANIEZ on 2/25/16.
//

#ifndef ABSTRACTVM_INT16_HPP
#define ABSTRACTVM_INT16_HPP

#include "../AOperand.hpp"

class Int16 : public AOperand
{
	public:
	Int16(long double val);
	Int16(std::string val);
	Int16(Int16 const &src);
	Int16 &operator=(Int16 const &rhs);
	virtual ~Int16(void) {}

	virtual const int16_t &getValue() const;
	virtual int8_t getInt8Value() const;
	virtual int16_t getInt16Value() const;
	virtual int32_t getInt32Value() const;
	virtual float getFloatValue() const;
	virtual double getDoubleValue() const;

	private:
	Int16();
	int16_t _value;
};


#endif //ABSTRACTVM_INT16_HPP
