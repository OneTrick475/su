/**
*
* Solution to homework assignment 1
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2022/2023
*
* @author Ivan Bukev
* @idnumber 2MI0600196
* @task 3
*
*/

#include <iostream>

int main() {
	int num = 0;
	
	std::cin >> num;
	
	if (num < 2 || num > 9) {
		std::cout << "Incorrect input";
		return 1;
	}

	int columns = num * 3;

	int colOffset = (80 - columns) / 2;

	int rows = num * 2 - 1;

	int rowOffset = (25 - rows)/2;

	for (int i = 0; i < rowOffset; ++i) {
		std::cout << "\n";
	}

	for (int i = 1; i <= rows; ++i) {
		for (int i = 0; i < colOffset; ++i) {
			std::cout << ' ';
		}

		int currentNumber = (i <= num) ? i : rows - i + 1;

		for (int i = 1; i <= columns; ++i) {
			if (i <= currentNumber) {
				std::cout << i;
			}
			else if (i > columns - currentNumber) {
				std::cout << columns - i + 1;
			}
			else {
				char fillerCharacter = (currentNumber == num ? '-' : ' ');

				std::cout << fillerCharacter;
			}
		}

		std::cout << "\n";
	}
	for (int i = 0; i < rowOffset; ++i) {
		std::cout << "\n";
	}
}