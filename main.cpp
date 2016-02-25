//
// Created by Eric MANIEZ on 2/18/16.
//

#include <iostream>
#include "includes/classes/Int8.hpp"
#include "includes/classes/Int16.hpp"
#include "includes/classes/Int32.hpp"
#include "includes/classes/Float.hpp"
#include "includes/classes/Double.hpp"

int main()
{
	class Int8 one(127);
	class Int8 two(2);
	class Int16 three(12);
	class Float four(4);
	class Double five(5);

	std::cout << (one+five)->toString() << std::endl;

	return 1;
}