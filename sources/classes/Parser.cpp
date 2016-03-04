//
// Created by Eric MANIEZ on 2/27/16.
//

#include <regex>
#include "../../includes/classes/Parser.hpp"

Parser::Parser() : _fileName("") {

}

Parser::Parser(std::string fileName) : _fileName(fileName) {
	struct stat st;
	int i;

	try {
		_fileStream.open(fileName);
		i = stat(fileName.c_str(), &st);
		if (S_ISDIR(st.st_mode)) {
			throw FilesIsADirectoryException();
		} else if (access(fileName.c_str(), R_OK) < 0 && i >= 0) {
			throw FilePermissionDeniedException();
		} else if (_fileStream.fail()) {
			throw FilesInexistantException();
		}
	} catch (std::exception &e) {
		std::cout << "\033[1;31m" << "[ERROR] " << e.what() << "\033[0m" << std::endl;
		exit(0);
	}
}

Parser::Parser(Parser const &src) : _fileName(src.get_fileName()) {}

Parser const &Parser::operator=(Parser const &rhs) {
	_fileName = rhs.get_fileName();

	return *this;
}

const std::string &Parser::get_fileName() const {
	return _fileName;
}


std::string Parser::read() {
	std::string line;

	if (_fileName.empty()) {
		std::cout << "\033[1;32m" << "[AbstractVM]> " << "\033[0m";
		std::getline(std::cin, line);
	} else if (!_fileStream.eof()) {
		std::getline(_fileStream, line);
	} else {
		//no exit instruction exception
		throw EofNoExitException();
	}

	std::string ret = cleanLine(line);
	if (ret.empty()) {
		return read();
	}

	return ret;
}

//Look for comments and filter them out of the line
std::string Parser::cleanLine(std::string line) {
	std::regex comment(";[^;\\n].*");
	std::regex multiSpace("\\s+");

	line = regex_replace(line, comment, "");
	line = regex_replace(line, multiSpace, " ");

	return line;
}

Parser::EofNoExitException::EofNoExitException() : std::logic_error(
		"[EOF] End of file reached - no exit instruction") {}

Parser::FilesIsADirectoryException::FilesIsADirectoryException() : std::runtime_error(
		"[ISDIR] Selected file is a directory") {}

Parser::FilePermissionDeniedException::FilePermissionDeniedException() : std::runtime_error(
		"[DENIED] You do not have necessary permission to access this file") {}

Parser::FilesInexistantException::FilesInexistantException() : std::runtime_error(
		"[?] No such file or directory") {}
