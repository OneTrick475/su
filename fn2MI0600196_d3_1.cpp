/**
*
* Solution to homework assignment 3
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

void cypher(char key, char str[]){
	int i = 0;

	while(str[i] != 0) {
		char character = char(str[i++] ^ key);

		if (character) {
			std::cout << character;
		}
	}
}

int main(){
	const int MAX_SIZE = 1025;

	char str[MAX_SIZE];

	char key;

	std::cin >> key;

	std::cin >> str;

	cypher(key, str);
}
