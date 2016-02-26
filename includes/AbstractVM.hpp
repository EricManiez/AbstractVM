//
// Created by Eric MANIEZ on 2/25/16.
//

#ifndef ABSTRACTVM_ABSTRACTVM_HPP
#define ABSTRACTVM_ABSTRACTVM_HPP

#define CALL_MEMBER_FN(object,ptrToMember)  ((object).*(ptrToMember))

#include <string>
#include <iostream>
#include "IOperand.hpp"
//#include "classes/Int8.hpp"
//#include "Int16.hpp"
//#include "Int32.hpp"
//#include "Float.hpp"
//#include "Double.hpp"

enum eOperandType {Int8, Int16, Int32, Float, Double};


#endif //ABSTRACTVM_ABSTRACTVM_HPP
