/**
*
* Solution to homework assignment 3
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2022/2023
*
* @author Ivan Bukev
* @idnumber 2MI0600196
* @task 2
*
*/

#include <iostream>

const int MAX_ARR_SIZE = 15;
const int MAX_NUM = 9999;
const int MAX_DIGITS = 4;

int power(int num, int power) {
	int result = 1;
	for(int i = 0; i < power; ++i) {
		result *= num;
	}
	return result;
}

bool isBigger(int first, int second) {
	int firstLen = MAX_DIGITS;
	int secondLen = MAX_DIGITS;

	while (first / power(10, firstLen - 1) == 0) {
		--firstLen;
	}
	while (second / power(10, secondLen - 1) == 0) {
		--secondLen;
	}

	int firstNSecond = first * power(10, secondLen) + second;
	int secondNFirst = second * power(10, firstLen) + first;

	if(firstNSecond == secondNFirst) {
		return firstLen > secondLen;
	}

	return firstNSecond > secondNFirst;
}

int getIndexOfBiggestByLeftDigit(int nums[], int size, int start) {
	int max = start;

	for(int i = start + 1;i < size; ++i) {
		if (isBigger(nums[i], nums[max])) {
			max = i;
		}
	}
	return max;
}

void rearangeToMaxNumber(int nums[], int size) {
	for(int i = 0; i < size; ++i) {
		int maxIndex = getIndexOfBiggestByLeftDigit(nums, size, i);

		int temp = nums[i];
		nums[i] = nums[maxIndex];
		nums[maxIndex] = temp;
	}
}

void printArr(int arr[], int size) {
	for (int i = 0; i < size; ++i) {
		std::cout << arr[i]<< ' ';
	}
}

int main() {
	int nums[MAX_ARR_SIZE];

	int size;

	std::cin >> size;

	if(size < 1 || size > MAX_ARR_SIZE) {
		std::cout << "-1";
		return 0;
	}

	for(int i=0; i<size;++i) {
		std::cin >> nums[i];
		if (nums[i] < 1 || nums[i] > MAX_NUM) {
			std::cout << "-1";
			return 0;
		}
	}
	
	rearangeToMaxNumber(nums, size);

	printArr(nums, size);
}
