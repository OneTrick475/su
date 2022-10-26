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


//#include <iostream>
//
//using namespace std;
//
//int main() {
//	int n = 0;
//
//	cin >> n;
//
//	if (n < 1 || n > 1000000) {
//		cout << "Incorrect input";
//		return 1;
//	}
//
//	int multiplier = 1;
// 
//	const int DIVISOR = 10;
//
//	int m = 0;
//
//	while (n / DIVISOR != 0 || n % DIVISOR != 0) {
//		int num = n % DIVISOR;
//
//		m += num * num * multiplier;
//
//		if (num * num >= 10)
//			multiplier *= 100;
//		else
//			multiplier *= 10;
//
//		n /= DIVISOR;
//	}
//
//	m += multiplier / 10;
//
//	while (m / 10 != 0 || m % 10 != 0) {
//		cout << m % 10;
//
//		m /= 10;
//	}
//
//}