/**
*
* Solution to homework assignment 2
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

bool equal(double x, double y){
	double const diff = 0.0001;
	return (x > y - diff && x < y + diff);
}

bool hitsBorder(double x, double y) {
	return (equal(x * x + y * y, 1)) ||
		equal((4 - x) * (4 - x) + (4 - y) * (4 - y), 4) || 
		equal((4 + x) * (4 + x) + (4 - y) * (4 - y), 4) ||
		equal(x * x + y * y, 100) ||
		((equal(y, -4) || equal(y, -6)) && x >= -5 && x <= 5) ||
		((equal(x, -5) || equal(y, 5)) && y <= -4 && y >= -6) ||
		((equal(y, -10) || equal(y, 10)) && x >= -10 && x <= 10) ||
		((equal(x, -10) || equal(y, 10)) && y <= 10 && y >= -10);
}

bool hitsNose(double x, double y) {
	return (x * x + y * y < 1);
}

bool hitsMouth(double x, double y) {
	return (x > -5 && x < 5 && y < -4 && y > -6);
}

bool hitsEye(double x, double y) {
	return (((4 - x) * (4 - x) + (4 - y) * (4 - y) < 4) || ((4 + x) * (4 + x) + (4 - y) * (4 - y) < 4));
}

bool hitsFace(double x, double y) {
	return (x * x + y * y < 100);
}

bool hitsBackground(double x, double y) {
	return (x > -10 && x < 10 && y < 10 && y > -10);
}

void targetHit(double x, double y) {
	if (hitsBorder(x, y)) {
		std::cout << "Border";
	}
	else if (hitsNose(x, y)) {
		std::cout << "Nose";
	}
	else if (hitsMouth(x, y)) {
		std::cout << "Mouth";
	}
	else if (hitsEye(x, y)){
		std::cout << "Eye";
	}
	else if (hitsFace(x, y)) {
		std::cout << "Face";
	}
	else if (hitsBackground(x, y)) {
		std::cout << "Background";
	}
	else {
		std::cout << "Miss";
	}
	
}

int main() {
	double x = 0;
	double y = 0;

	std::cin >> x;
	std::cin >> y;

	targetHit(x, y);
}