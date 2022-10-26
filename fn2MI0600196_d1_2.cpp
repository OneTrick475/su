/**
*
* Solution to homework assignment 1
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

int main() {

	enum romans {
		I = 1,
		IV = 4,
		V = 5,
		IX = 9,
		X = 10,
		XL = 40,
		L = 50,
		XC = 90,
		C = 100,
		CD = 400,
		D = 500,
		CM = 900,
		M = 1000
	};
	
	int num = 0;

	std::cin >> num;

	if (num < 1 || num > 2000) {
		std::cout << "Incorrect input";
		return 1;
	}


	while (num > 0) {
		if (num >= M) {
			std::cout << "M";
			num -= M;
		}
		else if (num >= CM) {
			std::cout << "CM";
			num -= CM;
		}
		else if (num >= D) {
			std::cout << "D";
			num -= D;
		}
		else if (num >= CD) {
			std::cout << "CD";
			num -= CD;
		}
		else if (num >= C) {
			std::cout << "C";
			num -= C;
		}
		else if (num >= XC) {
			std::cout << "XC";
			num -= XC;
		}
		else if (num >= L) {
			std::cout << "L";
			num -= L;
		}
		else if (num >= XL) {
			std::cout << "XL";
			num -= XL;
		}
		else if (num >= X) {
			std::cout << "X";
			num -= X;
		}
		else if (num >= IX) {
			std::cout << "IX";
			num -= IX;
		}
		else if (num >= V) {
			std::cout << "V";
			num -= V;
		}
		else if (num >= IV) {
			std::cout << "IV";
			num -= IV;
		}
		else if (num >= I) {
			std::cout << "I";
			num -= I;
		}
	}
}
