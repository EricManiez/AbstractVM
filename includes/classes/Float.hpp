//
// Created by Eric MANIEZ on 2/25/16.
//

#ifndef ABSTRACTVM_FLOAT_HPP
#define ABSTRACTVM_FLOAT_HPP

#include "../AOperand.hpp"

class Float : public AOperand
{
	public:
	Float(float val);
	Float(Float const &src);
	Float &operator=(Float const &rhs);
	virtual ~Float(void) {}

	virtual const float &getValue() const;
	virtual int8_t getInt8Value() const;
	virtual int16_t getInt16Value() const;
	virtual int32_t getInt32Value() const;
	virtual float getFloatValue() const;
	virtual double getDoubleValue() const;

	private:
	Float();
	float _value;
};


#endif //ABSTRACTVM_FLOAT_HPP
