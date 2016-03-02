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

    _fileStream.open(fileName);
    i = stat(fileName.c_str(), &st);
    if (S_ISDIR(st.st_mode)) {

    } else if (access(fileName.c_str(), R_OK) < 0 && i >= 0) {

    } else if (_fileStream.fail()) {

    }
}

Parser::Parser(Parser const &src) : _fileName(src.get_fileName()) { }

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
        "[EOF] End of file reached - no exit instruction") { }
