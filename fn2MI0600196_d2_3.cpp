/**
*
* Solution to homework assignment 2
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

const int UPPER_LIMIT = 20;
const int LOWER_LIMIT = 1;

void getNth(int n) {
	int curr[UPPER_LIMIT * UPPER_LIMIT] = { 1 };
	int len = 1;

	for (int i = 0; i < n - 1; ++i) {
		int temp[UPPER_LIMIT * UPPER_LIMIT] = {};
		int index = 0;
		int currNum = curr[0];
		int count = 1;
		for (int j = 1; j <= len; ++j) {
			if (currNum == curr[j]) {
				++count;
			}
			else {
				temp[index++] = count;
				temp[index++] = currNum;
				currNum = curr[j];
				count = 1;
			}
		}
		len = index;
		for (int i = 0; i < len; ++i) {
			curr[i] = temp[i];
		}
	}

	for (int i = 0; i < len; ++i) {
		std::cout << curr[i];
	}
}

int main() {
	int n = 0;

	std::cin >> n;

	if (n < LOWER_LIMIT || n > UPPER_LIMIT) {
		std::cout << -1;
		return -1;
	}
	
	getNth(n);
	
}
