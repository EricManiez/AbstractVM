//
// Created by Eric MANIEZ on 2/27/16.
//

#ifndef ABSTRACTVM_OPERANDSTACK_HPP
#define ABSTRACTVM_OPERANDSTACK_HPP


#include <deque>
#include "../IOperand.hpp"
#include "Lexer.hpp"

class OperandStackController
{
	typedef void (OperandStackController::*UnaryControllerFunctionPointer)();
	typedef void (OperandStackController::*BinaryControllerFunctionPointer)(IOperand const *);

	public:
	OperandStackController();
	OperandStackController(OperandStackController const &);
	OperandStackController const &operator=(OperandStackController const &rhs);

	~OperandStackController() {};

	const std::deque<const IOperand *> &get_operandStack() const;
	const std::map<std::string, UnaryControllerFunctionPointer> &get_unaries() const;
	const std::map<std::string, BinaryControllerFunctionPointer> &get_binaries() const;

	void execute(std::string);

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
	void mExit();

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
	std::map<std::string, UnaryControllerFunctionPointer> _unaries;
	std::map<std::string, BinaryControllerFunctionPointer> _binaries;
};


#endif //ABSTRACTVM_OPERANDSTACK_HPP
