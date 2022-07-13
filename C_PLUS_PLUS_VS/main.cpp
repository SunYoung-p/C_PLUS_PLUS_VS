#include <iostream>
#include "TestHeader.h"

int main()
{
	std::cout << "Hello World ! " << std::endl;
	std::cout << "This is new environment ! " << std::endl;
	std::cout << "5 suqrt is " << SqurtFunc(5) << std::endl
		<< "19 squrt is " << SqurtFunc(19) << std::endl;

	getchar();

	return 0;
}