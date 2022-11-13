/**
*
* Solution to homework assignment 2
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2022/2023
*
* @author Ivan Bukev
* @idnumber 2MI0600196
* @task 1
*
*/


#include <iostream> 

const int UPPER_LIMIT = 1024;
const int LOWER_LIMIT = 1;

void printReversedNum(int arr[1025], int end, bool isNegative = false) {
	while (end > 1) {
		if (arr[end - 1] != 0) {
			break;
		}
		--end;
	}
	
	if (isNegative) {
		arr[end - 1] *= -1;
	}

	for (int i = end - 1; i >= 0; --i) {
		std::cout << arr[i];
	}
}

void add(int n, char num1[], int k, char num2[], int result[]) {
	int remainder = 0;

	for (int i = n - 1; i >= 0; --i) {
		result[n - i - 1] = num1[i] - '0';
	}

	for (int i = k - 1; i >= 0; --i) {
		int currNum = result[k - i - 1];

		currNum += num2[i] - '0';

		if (remainder) {
			currNum += remainder--;
		}

		if (currNum > 9) {
			currNum -= 10;
			++remainder;
		}

		result[k - i - 1] = currNum;
	}

	while (remainder) {
		int currNum = result[k] + remainder--;

		if (currNum == 10) {
			currNum = 0;
			++remainder;
		}

		result[k++] = currNum;
	}

	printReversedNum(result, n+1);
}

void subtract(int n, char num1[], int k, char num2[], int result[], bool isNegative = false) {
	int remainder = 0;

	if (n == k == 1) {
		std::cout << num1[0] - num2[0];
		return;
	}

	for (int i = n - 1; i >= 0; --i) {
		result[n - i - 1] = num1[i] - '0';
	}

	for (int i = k - 1; i >= 0; --i) {
		int currNum = result[k - i - 1];

		currNum -= num2[i] - '0';

		if (remainder) {
			currNum -= remainder--;
		}

		if (currNum < 0) {
			currNum = 10 + currNum;
			++remainder;
		}

		result[k - i - 1] = currNum;
	}
	while (remainder) {
		int currNum = result[k] - remainder--;

		if (currNum == -1) {
			currNum = 9;
			++remainder;
		}

		result[k++] = currNum;
	}

	if (isNegative) {
		printReversedNum(result, n, true);
	}
	else {
		printReversedNum(result, n);
	}
 }


void sumOrDiff(int n, char num1[], int k, char num2[], char operation) {
	int result[UPPER_LIMIT + 1] = {};

	int max = n > k ? n : k;

	if (operation == '+') {
		if (n == max) {
			add(n, num1, k, num2, result);
		}
		else {
			add(k, num2, n, num1, result);
		}
	}
	else if(operation == '-') {
		bool isNegative = n < k;

		if (n == k) {
			for (int i = 1; i < max; i++) {
				if (num2[i] > num1[i]) {
					isNegative = true;
					break;
				}
			}
		}
		if (isNegative) {
			subtract(k, num2, n, num1, result, true);
		}
		else {
			subtract(n, num1, k, num2, result);
		}
	}
}

int main() {
	int n = 0, k = 0;
	char num1[UPPER_LIMIT] = {'0'};
	char num2[UPPER_LIMIT] = {'0'};

	std::cin >> n;

	std::cin >> num1;

	std::cin >> k;

	std::cin >> num2;

	if (n < LOWER_LIMIT || n > UPPER_LIMIT || k < LOWER_LIMIT || k > UPPER_LIMIT) {
		return -1;
	}

	sumOrDiff(n, num1, k, num2, '+');
	std::cout << '\n' ;
	sumOrDiff(n, num1, k, num2, '-');
}