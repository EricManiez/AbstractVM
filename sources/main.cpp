//
// Created by Eric MANIEZ on 2/18/16.
//

#include <iostream>
#include <float.h>
#include "../includes/classes/OperandFactory.hpp"
#include "../includes/classes/Parser.hpp"
#include "../includes/classes/OperandStackController.hpp"
#include "../includes/classes/Lexer.hpp"

int main(int argc, char **argv) {

	if (argc != 1 && argc != 2) {
		std::cout << "nope" << std::endl;
		exit(0);
	}

	std::string command;
	Parser	parser(argc == 2 ? argv[1] : "");
	OperandStackController stack;

	std::cout << "Let's get abstract!" << std::endl;
	while (!(command = parser.read()).empty()){
		stack.execute(command);
	}

	return 1;
}