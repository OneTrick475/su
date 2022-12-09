/**
*
* Solution to homework assignment 3
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

void appBinaryNum(bool* binaryNums, int num, int index) {
	for(int i = 7; i >= 0; --i) {
		binaryNums[index + i] = num % 2 != 0;
		num /= 2;
	}
}

bool isOver(bool* binaryNums, int size) {
	int endIndex = size - (size % 3);

	for(int i = endIndex - 6; i < size; ++i) {
		if(binaryNums[i] != 0) {
			return false;
		}
	}
	return true;
}

int getSum(int* nums, int size) {
	int sum = 0;
	for (int i = 0; i < size; ++i) {
		sum += nums[i];
	}
	return sum;
}

void printImage(int width) {
	int size = 80;

	bool* binaryNums = new bool[size] { 0 };

	int i = 0;
	while(true) {
		if(i*8 == size) {
			bool* tempBinary = new bool[size * 2] { 0 };
			for (int i = 0; i < size; ++i) {
				tempBinary[i] = binaryNums[i];
			}
			delete[] binaryNums;
			binaryNums = tempBinary;
			size *= 2;
		}

		int num;

		std::cin >> num;

		if(num < 0 || num > 255) {
			std::cout << "Invalid input";
			return;
		}

		appBinaryNum(binaryNums, num, i*8);

		if(isOver(binaryNums, (i+1)*8)) {
			break;
		}

		++i;
	}

	int newNumsSize = size / 3;
	int* newNums = new int[newNumsSize]{ 0 };

	for(int i = 0; i < newNumsSize; ++i) {
		newNums[i] = 4 * binaryNums[i*3] + 2 * binaryNums[i*3 + 1] + binaryNums[i*3 + 2];
	}

	if(getSum(newNums, newNumsSize) % width != 0) {
		std::cout << "Invalid input";
		return;
	}

	int count = 0;

	for(int i = 0; i < newNumsSize; ++i) {
		char curChar = i % 2 == 0 ? '.' : '#';

		for(int j = 0; j < newNums[i]; ++j) {
			std::cout << curChar;
			count += 1;
			if(count == width) {
				std::cout << '\n';
				count = 0;
			}
		}
	}
}

int main() {
	int width;
	std::cin >> width;

	printImage(width);
}