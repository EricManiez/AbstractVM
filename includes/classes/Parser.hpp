//
// Created by Eric MANIEZ on 2/27/16.
//

#ifndef ABSTRACTVM_PARSER_HPP
#define ABSTRACTVM_PARSER_HPP


#include <fstream>
#include <sys/stat.h>
#include <iostream>

class Parser
{
	public:
	Parser();
	Parser(std::string fileName);
	Parser(Parser const &src);
	Parser const &operator=(Parser const &rhs);
	~Parser() {};

	const std::string &get_fileName() const;

	std::string read();
	std::string cleanLine(std::string line);

	class EofNoExitException : public std::logic_error
	{
		public :
		EofNoExitException();
	};

	class FilesIsADirectoryException : public std::runtime_error
	{
		public :
		FilesIsADirectoryException();
	};

	class FilePermissionDeniedException : public std::runtime_error
	{
		public :
		FilePermissionDeniedException();
	};

	class FilesInexistantException : public std::runtime_error
	{
		public :
		FilesInexistantException();
	};


	private:
	std::string _fileName;
	std::ifstream _fileStream;
};


#endif //ABSTRACTVM_PARSER_HPP
