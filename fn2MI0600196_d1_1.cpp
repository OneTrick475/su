/**
*
* Solution to homework assignment 1
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

int main() {
	int n = 0;

	std::cin >> n;

	if (n < 1 || n > 1000000) {
		std::cout << "Incorrect input";
		return 1;
	}

	const int DIVISOR = 10;

	long long multiplier = 1;

	long long int m = 0;

	while (n / DIVISOR != 0 || n % DIVISOR != 0) {
		long long num = n % DIVISOR;

		m += num * num * multiplier;

		if (num * num >= 10) {
			multiplier *= 100;
		}
		else {
			multiplier *= 10;
		}

		n /= DIVISOR;
	}

	multiplier /= DIVISOR;

	long long result = 0;

	while (multiplier > 0) {
		result += m % DIVISOR * multiplier;
		
		m /= DIVISOR;

		multiplier /= DIVISOR;
	}

	std::cout << result + 1;

}
