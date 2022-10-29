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

//used binary search to find floor of the square root in O(log n) time
//this is used to optimize the isPrime func
int getSquareRoot(int num) {
	if (num == 0 || num == 1) {
		return num;
	}

	int left = 1;
	int right = num / 2;
	int ans = 0;

	while (left <= right) {
		int mid = (left + right) / 2;

		int square = mid * mid;

		if (square == num) {
			return mid;
		}

		if (square > num) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
			ans = mid;
		}
	}
	return ans;
}

bool isPrime(int num) {
	if (num == 2) {
		return true;
	}

	if (num == 1 || num % 2 == 0) {
		return false;
	}

	for (int i = 3; i < getSquareRoot(num) + 1; i+=2) {
		if (num % i == 0) {
			return false;
		}
	}

	return true;
}

bool numsAreUnique(int num) {
	int multipleOfTen = 1000000000;

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
	
	if (num < 1 || num > 1000000000) {
		std::cout << "Incorrect input";
		return 1;
	}

	int i = 0;

	while (true) {
		if (numsAreUnique(num - i) && isPrime(num - i)) {
			std::cout << num - i;
			return 0;
		}
		if (numsAreUnique(num + i) && isPrime(num + i)) {
			std::cout << num + i;
			return 0;
		}
		
		++i;
	}
}
//652345
