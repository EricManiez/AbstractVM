//
// Created by Eric MANIEZ on 2/25/16.
//

#ifndef ABSTRACTVM_FLOAT_HPP
#define ABSTRACTVM_FLOAT_HPP

#include "../AOperand.hpp"

class Float : public AOperand
{
	public:
	Float(long double val);
	Float(std::string val);
	Float(Float const &src);
	Float &operator=(Float const &rhs);
	virtual ~Float(void) {}

	virtual const float &getValue() const;

	private:
	Float();
	float _value;
};


#endif //ABSTRACTVM_FLOAT_HPP
