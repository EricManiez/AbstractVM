//
// Created by Eric MANIEZ on 2/27/16.
//

#ifndef ABSTRACTVM_OPERANDSTACK_HPP
#define ABSTRACTVM_OPERANDSTACK_HPP


#include <deque>
#include "../IOperand.hpp"

class OperandStack
{
	public:
	void push(IOperand const *);
	void pop();
	void dump();
	void assert(IOperand const *);
	void add();
	void sub();
	void mul();
	void div();
	void mod();
	void print();

	class StackTooShortException : public std::exception
	{
		public :
		StackTooShortException() {};

		StackTooShortException(StackTooShortException const &) {};

		virtual ~StackTooShortException() throw() {};
		StackTooShortException const &operator=(StackTooShortException const &);

		virtual const char *what() const throw();
	};

	class AssertFalseException : public std::exception
	{
		public :
		AssertFalseException() {};

		AssertFalseException(AssertFalseException const &) {};

		virtual ~AssertFalseException() throw() {};
		AssertFalseException const &operator=(AssertFalseException const &);

		virtual const char *what() const throw();
	};


	private:
	std::deque<IOperand const *> _operandStack;
};


#endif //ABSTRACTVM_OPERANDSTACK_HPP
