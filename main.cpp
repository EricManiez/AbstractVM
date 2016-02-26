//
// Created by Eric MANIEZ on 2/18/16.
//

#include <iostream>
#include <float.h>
#include "includes/classes/Int8.hpp"
#include "includes/classes/Int16.hpp"
#include "includes/classes/Int32.hpp"
#include "includes/classes/Float.hpp"
#include "includes/classes/Double.hpp"

int main() {
	class Int8 one(127);
	class Int8 two(2);
	class Int16 three(127);
	class Float four(FLT_MAX);
	class Double five(FLT_MAX);

	std::cout << "teste" << std::endl;
	std::cout << (one * three)->toString() << std::endl;

	return 1;
}