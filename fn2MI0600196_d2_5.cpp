/**
*
* Solution to homework assignment 2
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2022/2023
*
* @author Ivan Bukev
* @idnumber 2MI0600196
* @task 5
*
*/

#include <iostream>

bool isPrime(int num) {
	if (num == 2) {
		return true;
	}

	if (num == 0 || num == 1 || num % 2 == 0) {
		return false;
	}

	for (int i = 3; i < sqrt(num) + 1; i += 2) {
		if (num % i == 0) {
			return false;
		}
	}

	return true;
}

int concat(int numArr[],int start,int end) {
	if(numArr[end] == 0){
		return 0;
	}

	int num = 0;
	int multiplier = 1;

	while (start <= end) {
		num += (numArr[start++]) * multiplier;
		multiplier *= 10;
	}

	return num;
}

int numOfOperationsToPrime(int num) {
	const int LOWER_LIMIT = 1;
	const int UPPER_LIMIT = 1000000000;

	if (num < LOWER_LIMIT || num > UPPER_LIMIT) {
		return -2;
	}

	int numArr[10] = {};
	int size = 0;

	while (num / 10 != 0 || num % 10 != 0) {
		numArr[size++] = num % 10;
		num /= 10;
	}

	for (int i = size - 1; i >= 0; --i) {
		for (int j = 0; j <= i; j += 2) {
			int currNum = concat(numArr, j, i);
			if (isPrime(currNum)) {
				return (size - 1 - i) + (j / 2);
			}
		}
	}
	return -1;
}

int main() {
	int num = 0;

	std::cin >> num;
	std::cout << numOfOperationsToPrime(num);
}