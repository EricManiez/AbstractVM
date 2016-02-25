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

	const double &getValue() const;

	private:
	Double();
	double _value;
};

#endif //ABSTRACTVM_DOUBLE_HPP
