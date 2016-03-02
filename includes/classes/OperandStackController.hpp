//
// Created by Eric MANIEZ on 2/27/16.
//

#ifndef ABSTRACTVM_OPERANDSTACK_HPP
#define ABSTRACTVM_OPERANDSTACK_HPP


#include <deque>
#include "../IOperand.hpp"
#include "Lexer.hpp"

class OperandStackController {
    typedef void (OperandStackController::*UnaryControllerFunctionPointer)();

    typedef void (OperandStackController::*BinaryControllerFunctionPointer)(IOperand const *);

public:
    OperandStackController();

    OperandStackController(OperandStackController const &);

    OperandStackController const &operator=(OperandStackController const &rhs);

    ~OperandStackController() { };

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

    class StackTooShortException : public std::logic_error {
    public :
        StackTooShortException();
    };

    class AssertFalseException : public std::logic_error {
    public :
        AssertFalseException();
    };


private:
    std::deque<IOperand const *> _operandStack;
    std::map<std::string, UnaryControllerFunctionPointer> _unaries;
    std::map<std::string, BinaryControllerFunctionPointer> _binaries;
};


#endif //ABSTRACTVM_OPERANDSTACK_HPP
