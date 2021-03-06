//
// Created by Eric MANIEZ on 2/27/16.
//

#include <sstream>
#include <array>
#include <iostream>
#include "../../includes/classes/Lexer.hpp"
#include "../../includes/AbstractVM.hpp"

Lexer::Lexer(std::string string) : _splitCommand(explode(string, ' ')) {
	if (std::find(string.begin(), string.end(), ';') != string.end()) {
		exit(1);
	}
}

Lexer::Lexer(Lexer const &src) : _splitCommand(src.get_splitCommand()) {}

Lexer const &Lexer::operator=(Lexer const &rhs) {
	_splitCommand = rhs.get_splitCommand();

	return *this;
}

const std::vector<std::string> &Lexer::get_splitCommand() const {
	return _splitCommand;
}

std::vector<std::string> Lexer::explode(std::string str, char delimiter) {
	std::vector<std::string> result;
	std::istringstream iss(str);

	for (std::string token; std::getline(iss, token, delimiter);) {
		result.push_back(std::move(token));
	}

	return result;
}

bool Lexer::isInstructionOk() {
	std::vector<std::string> instructions;
	if (_splitCommand.size() == 1) {
		//Must be unary function
		instructions.push_back("pop");
		instructions.push_back("dump");
		instructions.push_back("add");
		instructions.push_back("sub");
		instructions.push_back("mul");
		instructions.push_back("div");
		instructions.push_back("mod");
		instructions.push_back("print");
		instructions.push_back("exit");
	} else {
		//Must be binary function
		instructions.push_back("push");
		instructions.push_back("assert");
	}
	if (std::find(instructions.begin(), instructions.end(), _splitCommand[0]) == instructions.end()) {
		throw Lexer::InstructionIncorrectException();
	}
	return true;
}

bool Lexer::isOperandOk() {
	std::regex generalPattern("\\b\\w*\\(.+\\)");

	if (!regex_match(_splitCommand[1], generalPattern)) {
		throw Lexer::WrongParameterFormatException();
	}
	std::vector<std::string> operand = explode(_splitCommand[1], '(');
	operand[1] = operand[1].substr(0, operand[1].size() - 1);
	_splitCommand[1] = operand[0];
	_splitCommand.push_back(operand[1]);

	std::vector<std::string> types;
	types.push_back("int8");
	types.push_back("int16");
	types.push_back("int32");
	types.push_back("float");
	types.push_back("double");

	if (std::find(types.begin(), types.end(), operand[0]) == types.end()) {
		throw Lexer::UnknownTypeException();
	}

	return true;
}

std::map<std::string, std::string> Lexer::analyzeExpression() {
	std::map<std::string, std::string> ret;

	isInstructionOk();
	if (_splitCommand.size() > 1) {
		isOperandOk();
	}

	if (DEBUG) {
		for (std::string str : _splitCommand) {
			std::cout << "Lexer::Analyze : " << str << std::endl;
		}
	}

	ret["instruction"] = _splitCommand[0];
	if (_splitCommand.size() > 1) {
		ret["type"] = _splitCommand[1];
		ret["operand"] = _splitCommand[2];
	}

	return ret;
}

Lexer::InstructionIncorrectException::InstructionIncorrectException() : std::runtime_error(
		"[INCORRECT INSTRUCTION] The given instruction is incorrect or has insufficient parameters.") {}

Lexer::WrongParameterFormatException::WrongParameterFormatException() : std::runtime_error(
		"[WRONG VALUE FORMAT] The given parameter is not formatted correctly.") {}

Lexer::UnknownTypeException::UnknownTypeException() : std::runtime_error(
		"[UKNOWN TYPE] Requested type is unknown.") {}