/**
*
* Solution to homework assignment 2
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

int biggestDivisor(int n, int m){
	int divisor = n < m ? n : m;

	while (divisor > 0) {
		if (n % divisor == 0 && m % divisor == 0) {
			break;
		}
		--divisor;
	}
	return divisor;
}

bool isMagic(int nums[], int size) {
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			if (biggestDivisor(nums[i], nums[j]) == 1) {
				return true;
			}
		}
	}
	return false;
}

int main() {
	const int SIZE_LOWER = 2;
	const int SIZE_UPPER = 1024;

	int nums[1024] = {};
	int size = 0;

	std::cin >> size;
	
	if (size < SIZE_LOWER || size > SIZE_UPPER) {
		std::cout << -1;
		return -1;
	}

	for (int i = 0; i < size; ++i) {
		const int NUM_LOWER = 1;
		const int NUM_UPPER = 1000000000;

		std::cin >> nums[i];

		if (nums[i] < NUM_LOWER || nums[i] > NUM_UPPER) {
			return -1;
		}
	}

	std::cout << isMagic(nums, size);
}