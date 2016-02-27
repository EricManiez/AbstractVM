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

	class InstructionIncorrectException : public std::exception
	{
		public :
		InstructionIncorrectException() {};

		InstructionIncorrectException(InstructionIncorrectException const &) {};

		virtual ~InstructionIncorrectException() throw() {};
		InstructionIncorrectException const &operator=(InstructionIncorrectException const &);

		virtual const char *what() const throw();
	};

	class WrongValueFormatException : public std::exception
	{
		public :
		WrongValueFormatException() {};

		WrongValueFormatException(WrongValueFormatException const &) {};

		virtual ~WrongValueFormatException() throw() {};
		WrongValueFormatException const &operator=(WrongValueFormatException const &);

		virtual const char *what() const throw();
	};

	class UnknownTypeException : public std::exception
	{
		public :
		UnknownTypeException() {};

		UnknownTypeException(UnknownTypeException const &) {};

		virtual ~UnknownTypeException() throw() {};
		UnknownTypeException const &operator=(UnknownTypeException const &);

		virtual const char *what() const throw();
	};


	private:
	Lexer() {};

	bool isInstructionOk();
	bool isOperandOk();

	std::vector<std::string> explode(std::string, char delimiter);

	std::vector<std::string> _splitCommand;
};


#endif //ABSTRACTVM_LEXER_HPP
