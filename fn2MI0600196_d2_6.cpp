/**
*
* Solution to homework assignment 2
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2022/2023
*
* @author Ivan Bukev
* @idnumber 2MI0600196
* @task 6
*
*/

#include <iostream>

bool isHalfPalindrome(unsigned int num) {
	int arr[10] = {};

	int count = 0;
	while (num != 0) {
		++arr[num % 10];
		num /= 10;
		++count;
	}

	bool isHalfPalindrome = true;
	int countOdd = 0;

	for (int i = 0; i < 10; i++) {
		if (arr[i] % 2 != 0) {
			++countOdd;
		}
	}

	return (count % 2 == 0 && countOdd == 0) || (count % 2 != 0 && countOdd == 1 && arr[0] < count - 1);
}

int numOfPalindromes(unsigned int start, unsigned int end) {
	const unsigned int UPPER_LIMIT = 2147483648;
	const int LOWER_LIMIT = 1;

	if (start < LOWER_LIMIT || start > UPPER_LIMIT || end < LOWER_LIMIT || end>UPPER_LIMIT) {
		return -1;
	}

	start = start <= 100 ? 101 : start;
	
	int count = 0;
	for (int i = start; i <= end; ++i) {
		if (isHalfPalindrome(i)) {
			++count;
		}
	}
	return count;
}

int main() {
	unsigned int start = 0;
	unsigned int end = 0;
	std::cin >> start;
	std::cin >> end;

	std::cout << numOfPalindromes(start, end);
}