//
// Created by Eric MANIEZ on 2/25/16.
//

#ifndef ABSTRACTVM_ABSTRACTVM_HPP
#define ABSTRACTVM_ABSTRACTVM_HPP
#define STOP_EXEC_ON_ERROR false
#define DEBUG false

#define CALL_MEMBER_FN(object, ptrToMember)  ((object).*(ptrToMember))

#include <string>
#include <iostream>

enum eOperandType
{
	Int8, Int16, Int32, Float, Double
};


#endif //ABSTRACTVM_ABSTRACTVM_HPP
