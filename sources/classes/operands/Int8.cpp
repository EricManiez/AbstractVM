//
// Created by Eric MANIEZ on 2/25/16.
//

#include "../../../includes/classes/operands/Int8.hpp"

Int8::Int8() : Operand("", eOperandType::Int8), _value(0) { }

Int8::Int8(long double val) : Operand(std::to_string(static_cast<int8_t>(val)), eOperandType::Int8) {
    if (DEBUG) {
        std::cout << "int8 num construction : " << val << std::endl;
    }
    //Check if value is in int16_t range
    if (val < INT8_MIN) {
        throw std::underflow_error("[UNDERFLOW] : " + std::to_string(val) + " is too low for int8 type");
    } else if (val > INT8_MAX) {
        throw std::overflow_error("[OVERFLOW] : " + std::to_string(val) + " is too high for int8 type");
    } else {
        _value = static_cast<int8_t>(val);
    }
}

Int8::Int8(std::string val) : Operand(val, eOperandType::Int8) {
    //Attempt conversion from string to int8_t
    int convertedVal = std::stoi(val, 0, 0);
    if (DEBUG) {
        std::cout << "int8 string construction : " << convertedVal << std::endl;
    }

    //Check if value is in int8_t range
    if (convertedVal < INT8_MIN) {
        throw std::underflow_error("[UNDERFLOW] : " + val + " is too low for int8 type");
    } else if (convertedVal > INT8_MAX) {
        throw std::overflow_error("[OVERFLOW] : " + val + " is too high for int8 type");
    } else {
        _value = static_cast<int8_t>(convertedVal);
    }
}

Int8::Int8(Int8 const &src) : Operand(src.toString(), eOperandType::Int8), _value(src.getValue()) {
    *this = src;
}

class Int8 &Int8::operator=(Int8 const &rhs) {
    this->_value = rhs.getValue();

    return *this;
}

const int8_t &Int8::getValue() const {
    return this->_value;
}
