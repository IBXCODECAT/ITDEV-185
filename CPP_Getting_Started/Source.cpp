#include <iostream>
#include <string>

int main() {
	double num1 = 10.0;
	double num2 = 20.0;
	double num3 = 30.0;

	std::string name = "me!";

	//Print variables
	std::cout << "num1 = " << num1 << std::endl;
	std::cout << "num2 = " << num2 << std::endl;
	std::cout << "num3 = " << num3 << std::endl;
	std::cout << std::endl;
	std::cout << "Name = \"" << name << "\"" << std::endl;

	//Get user Input
	std::cout << "Enter a new number for num1: " << std::endl;
	std::cin >> num1;
	std::cout << "Enter a new number for num2: " << std::endl;
	std::cin >> num2;
	std::cout << "Enter a new number for num3: " << std::endl;
	std::cin >> num3;

	//Print updated variables
	std::cout << "num1 = \"" << num1 << "\" num2 = \"" << num2 << "\" num3 = \"" << num3 << "\"" << std::endl;

}