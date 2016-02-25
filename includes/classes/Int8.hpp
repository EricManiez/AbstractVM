//
// Created by Eric MANIEZ on 2/25/16.
//

#ifndef ABSTRACTVM_INT8_HPP
#define ABSTRACTVM_INT8_HPP

#include "../AOperand.hpp"

class Int8 : public AOperand
{
	public:
	Int8(int8_t val);
	Int8(Int8 const &src);
	Int8 &operator=(Int8 const &rhs);
	virtual ~Int8(void) {}

	const int8_t &getValue() const;

	private:
	Int8();
	int8_t _value;
};

#endif //ABSTRACTVM_INT8_HPP
