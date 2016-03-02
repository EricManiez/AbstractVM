//
// Created by Eric MANIEZ on 2/27/16.
//

#ifndef ABSTRACTVM_LEXER_HPP
#define ABSTRACTVM_LEXER_HPP

#include <regex>
#include <map>

class Lexer
{

	public:
	Lexer(std::string);
	Lexer(Lexer const &src);
	Lexer const &operator=(Lexer const &rhs);

	~Lexer() {};

	const std::vector<std::string> &get_splitCommand() const;

	std::map<std::string, std::string> analyzeExpression();

	class InstructionIncorrectException : public std::runtime_error
	{
		public :
		InstructionIncorrectException();
	};

	class WrongParameterFormatException : public std::runtime_error
	{
		public :
		WrongParameterFormatException();
	};

	class UnknownTypeException : public std::runtime_error
	{
		public :
		UnknownTypeException();
	};


	private:
	Lexer() {};

	bool isInstructionOk();
	bool isOperandOk();

	std::vector<std::string> explode(std::string, char delimiter);

	std::vector<std::string> _splitCommand;
};


#endif //ABSTRACTVM_LEXER_HPP
