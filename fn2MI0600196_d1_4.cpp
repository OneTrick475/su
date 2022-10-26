/**
*
* Solution to homework assignment 1
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2022/2023
*
* @author Ivan Bukev
* @idnumber 2MI0600196
* @task 4
*
*/

#include <iostream>

bool isPrime(int num) {
	if (num == 1) {
		return false;
	}

	for (int i = 2; i < num; ++i) {
		if (num % i == 0) {
			return false;
		}
	}

	return true;
}

bool numsAreUnique(int num) {
	const int divisor = 10;

	int multipleOfTen = 1000000;

	while (num / multipleOfTen == 0) {
		multipleOfTen /= 10;
	}

	for (int i = multipleOfTen; i >= 10; i /= 10) {
		int firstNumber = num / i % 10;

		for (int j = i / 10; j >= 1; j /= 10) {
			int secondNumber = num / j % 10;

			if (firstNumber == secondNumber) {
				return false;
			}
		}
	}

	return true;
}

int main() {
	int num = 0;
	
	std::cin >> num;
	
	if (num < 1 || num > 1000000) {
		std::cout << "Incorrect input";
		return 1;
	}

	
	int i = 0;

	while (true) {
		if (isPrime(num - i) && numsAreUnique(num - i)) {
			std::cout << num - i;
			return 0;
		}
		else if (isPrime(num + i) && numsAreUnique(num + i)) {
			std::cout << num + i;
			return 0;
		}
		
		++i;
	}
}

