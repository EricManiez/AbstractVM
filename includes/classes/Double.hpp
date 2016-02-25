//
// Created by Eric MANIEZ on 2/25/16.
//

#ifndef ABSTRACTVM_DOUBLE_HPP
#define ABSTRACTVM_DOUBLE_HPP

#include "../AOperand.hpp"

class Double : public AOperand
{
	public:
	Double(double val);
	Double(Double const &src);
	Double &operator=(Double const &rhs);
	virtual ~Double(void) {}

	virtual const double &getValue() const;
	virtual int8_t getInt8Value() const;
	virtual int16_t getInt16Value() const;
	virtual int32_t getInt32Value() const;
	virtual float getFloatValue() const;
	virtual double getDoubleValue() const;

	private:
	Double();
	double _value;
};

#endif //ABSTRACTVM_DOUBLE_HPP
