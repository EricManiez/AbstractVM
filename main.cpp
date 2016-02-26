//
// Created by Eric MANIEZ on 2/18/16.
//

#include <iostream>
#include <float.h>
#include "includes/classes/operands/Int8.hpp"
#include "includes/classes/operands/Int16.hpp"
#include "includes/classes/operands/Int32.hpp"
#include "includes/classes/operands/Float.hpp"
#include "includes/classes/operands/Double.hpp"

int main() {
	class Int8 one(070);
	class Int8 two(2);
	class Int16 three(0x0f);
	class Int32 threeandahalf(0xff);
	class Float four(42.42);
	class Double five(432.432);

	std::cout << "teste" << std::endl;
	std::cout << (one % four)->toString() << std::endl;

	return 1;
}