//
// Created by Eric MANIEZ on 2/18/16.
//

#include <iostream>
#include "includes/classes/Int8.hpp"
#include "includes/classes/Double.hpp"

int main()
{
	class Int8 one(1);
	class Double two(-2.56);

	std::cout << (one+two)->toString() << std::endl;

	return 1;
}