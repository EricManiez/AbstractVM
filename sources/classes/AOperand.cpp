//
// Created by Eric MANIEZ on 2/25/16.
//

#include <array>
#include "../../includes/AOperand.hpp"
#include "../../includes/classes/Int8.hpp"
#include "../../includes/classes/Int16.hpp"
#include "../../includes/classes/Int32.hpp"
#include "../../includes/classes/Float.hpp"
#include "../../includes/classes/Double.hpp"

AOperand::AOperand() : _type(eOperandType::Int8), _toString("null") {}
AOperand::AOperand(eOperandType type, std::string str) : _type(type), _toString(str) {}

AOperand::AOperand(AOperand const &src) : _type(src.getType()), _toString(src.toString()) {}

AOperand &AOperand::operator=(AOperand const &rhs) {
	this->_toString= rhs.toString();

	return *this;
}

eOperandType AOperand::choosePrecision(IOperand const &rhs) const {
	return rhs.getPrecision() >= this->getPrecision() ? rhs.getType() : this->getType();
}

int AOperand::getPrecision(void) const {
	return this->getType();
}

eOperandType AOperand::getType(void) const {
	return this->_type;
}

IOperand const *AOperand::operator+(IOperand const &rhs) const {
	std::array<IOperand const *, 5> res;
	res[eOperandType::Int8] = new class Int8(static_cast<int8_t >(this->getInt8Value()) + static_cast<class Int8 const *>(std::addressof(rhs))->getValue());
	res[eOperandType::Int16]  = new class Int16(static_cast<int16_t >(this->getInt16Value()) + static_cast<class Int16 const *>(std::addressof(rhs))->getValue());
	res[eOperandType::Int32]  = new class Int32(static_cast<int32_t >(this->getInt32Value()) + static_cast<class Int32 const *>(std::addressof(rhs))->getValue());
	res[eOperandType::Float]  = new class Float(static_cast<float >(this->getFloatValue()) + static_cast<class Float const *>(std::addressof(rhs))->getValue());
	res[eOperandType::Double] = new class Double(static_cast<double>(this->getDoubleValue()) + static_cast<class Double const *>(std::addressof(rhs))->getValue());

	return res[this->choosePrecision(rhs)];
}

IOperand const *AOperand::operator-(IOperand const &rhs) const {
	std::array<IOperand const *, 5> res;
	res[eOperandType::Int8] = new class Int8(static_cast<int8_t >(this->getInt8Value()) - static_cast<class Int8 const *>(std::addressof(rhs))->getValue());
	res[eOperandType::Int16]  = new class Int16(static_cast<int16_t >(this->getInt16Value()) - static_cast<class Int16 const *>(std::addressof(rhs))->getValue());
	res[eOperandType::Int32]  = new class Int32(static_cast<int32_t >(this->getInt32Value()) - static_cast<class Int32 const *>(std::addressof(rhs))->getValue());
	res[eOperandType::Float]  = new class Float(static_cast<float >(this->getFloatValue()) - static_cast<class Float const *>(std::addressof(rhs))->getValue());
	res[eOperandType::Double] = new class Double(static_cast<double>(this->getDoubleValue()) - static_cast<class Double const *>(std::addressof(rhs))->getValue());

	return res[this->choosePrecision(rhs)];
}

IOperand const *AOperand::operator*(IOperand const &rhs) const {
	std::array<IOperand const *, 5> res;
	res[eOperandType::Int8] = new class Int8(static_cast<int8_t >(this->getInt8Value()) * static_cast<class Int8 const *>(std::addressof(rhs))->getValue());
	res[eOperandType::Int16]  = new class Int16(static_cast<int16_t >(this->getInt16Value()) * static_cast<class Int16 const *>(std::addressof(rhs))->getValue());
	res[eOperandType::Int32]  = new class Int32(static_cast<int32_t >(this->getInt32Value()) * static_cast<class Int32 const *>(std::addressof(rhs))->getValue());
	res[eOperandType::Float]  = new class Float(static_cast<float >(this->getFloatValue()) * static_cast<class Float const *>(std::addressof(rhs))->getValue());
	res[eOperandType::Double] = new class Double(static_cast<double>(this->getDoubleValue()) * static_cast<class Double const *>(std::addressof(rhs))->getValue());

	return res[this->choosePrecision(rhs)];
}

IOperand const *AOperand::operator/(IOperand const &rhs) const {
	std::array<IOperand const *, 5> res;
	res[eOperandType::Int8] = new class Int8(static_cast<int8_t >(this->getInt8Value()) / static_cast<class Int8 const *>(std::addressof(rhs))->getValue());
	res[eOperandType::Int16]  = new class Int16(static_cast<int16_t >(this->getInt16Value()) / static_cast<class Int16 const *>(std::addressof(rhs))->getValue());
	res[eOperandType::Int32]  = new class Int32(static_cast<int32_t >(this->getInt32Value()) / static_cast<class Int32 const *>(std::addressof(rhs))->getValue());
	res[eOperandType::Float]  = new class Float(static_cast<float >(this->getFloatValue()) / static_cast<class Float const *>(std::addressof(rhs))->getValue());
	res[eOperandType::Double] = new class Double(static_cast<double>(this->getDoubleValue()) / static_cast<class Double const *>(std::addressof(rhs))->getValue());

	return res[this->choosePrecision(rhs)];
}

IOperand const *AOperand::operator%(IOperand const &rhs) const {
	std::array<IOperand const *, 5> res;
	res[eOperandType::Int8] = new class Int8(static_cast<int8_t >(this->getInt8Value()) % static_cast<class Int8 const *>(std::addressof(rhs))->getValue());
	res[eOperandType::Int16]  = new class Int16(static_cast<int16_t >(this->getInt16Value()) % static_cast<class Int16 const *>(std::addressof(rhs))->getValue());
	res[eOperandType::Int32]  = new class Int32(static_cast<int32_t >(this->getInt32Value()) % static_cast<class Int32 const *>(std::addressof(rhs))->getValue());
//	res[eOperandType::Float]  = new class Float(static_cast<float >(this->getFloatValue()) % static_cast<class Float const *>(std::addressof(rhs))->getValue());
//	res[eOperandType::Double] = new class Double(static_cast<double>(this->getDoubleValue()) % static_cast<class Double const *>(std::addressof(rhs))->getValue());

	return res[this->choosePrecision(rhs)];
}

std::string const &AOperand::toString(void) const {
	return _toString;
}

std::ostream &operator<<(std::ostream &o, class Int8 const &i) {
	o << i.toString();

	return o;
}
