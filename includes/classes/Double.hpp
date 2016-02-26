//
// Created by Eric MANIEZ on 2/25/16.
//

#ifndef ABSTRACTVM_DOUBLE_HPP
#define ABSTRACTVM_DOUBLE_HPP

#include "../AOperand.hpp"

class Double : public AOperand
{
	public:
	Double(long double val);
	Double(std::string val);
	Double(Double const &src);
	Double &operator=(Double const &rhs);
	virtual ~Double(void) {}

	virtual const double &getValue() const;

	private:
	Double();
	double _value;
};

#endif //ABSTRACTVM_DOUBLE_HPP
