/**
*
* Solution to homework assignment 3
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

int getHour(char* time) {
	return 10 * (time[0] - '0') + time[1] - '0';
}

int getMinute(char* time) {
	return 10 * (time[2] - '0') + time[3] - '0';
}

int getPlanesForPeriod(int startHour, int startMin, int endHour, int endMin, char* arrivals, char* departures, int size) {
	int count = 0;

	for(int i = 0; i < size; ++i) {
		int arrHour = getHour(&arrivals[i*4]);
		int arrMin = getMinute(&arrivals[i * 4]);

		int depHour = getHour(&departures[i * 4]);
		int depMin = getMinute(&departures[i * 4]);

		if(startHour > endHour || (startHour == endHour && startMin > endMin)) {
			return 0;
		}

		if((arrHour < startHour || (arrHour == startHour && arrMin <= startMin)) &&
			(depHour > endHour || (depHour == endHour && depMin >= endMin))) {
			++count;
		}
	}
	return count;
}

void printPeriod(int startHour, int startMinute, int endHour, int endMinute) {
	if(startHour < 10) {
		std::cout << 0 << startHour;
	}
	else {
		std::cout << startHour;
	}
	if (startMinute < 10) {
		std::cout << 0 << startMinute;
	}
	else {
		std::cout << startMinute;
	}

	std::cout << '-';

	if (endHour < 10) {
		std::cout << 0 << endHour;
	}
	else {
		std::cout << endHour;
	}
	if (endMinute < 10) {
		std::cout << 0 << endMinute;
	}
	else {
		std::cout << endMinute;
	}
	std::cout << '\n';
}

bool isAdded(int startHour, int startMinute, int endHour, int endMinute, int* periods, int size) {
	for(int i = 0; i < size; ++i) {
		if(startHour == periods[i * 4] && startMinute == periods[i * 4 + 1] &&
			endHour == periods[i * 4 + 2] && endMinute == periods[i * 4 + 3]) {

			return true;
		}
	}
	return false;
}

void printBusyPeriods(char* arrivals,char* departures, int size) {
	int max = 0;

	int* busyPeriods = new int[size * size * 4];

	int numOfBusyPeriods = 0;

	for(int i = 0; i < size; ++i) {
		for(int j = 0; j < size; ++j) {
			int startHour = getHour((arrivals + i * 4));
			int startMin = getMinute((arrivals + i * 4));

			int endHour = getHour((departures + j * 4));
			int endMin = getMinute((departures + j * 4));

			int planes = getPlanesForPeriod(startHour, startMin, endHour, endMin, arrivals, departures, size);

			if(planes == 0) {
				continue;
			}

			if(planes == max) {
				if(isAdded(startHour, startMin, endHour, endMin, busyPeriods, numOfBusyPeriods)) {
					continue;
				}
				busyPeriods[4 * numOfBusyPeriods] = startHour;
				busyPeriods[4 * numOfBusyPeriods+1] = startMin;
				busyPeriods[4 * numOfBusyPeriods+2] = endHour;
				busyPeriods[4 * numOfBusyPeriods+3] = endMin;

				++numOfBusyPeriods;
			}
			else if(planes > max) {
				busyPeriods[0] = startHour;
				busyPeriods[1] = startMin;
				busyPeriods[2] = endHour;
				busyPeriods[3] = endMin;

				numOfBusyPeriods = 1;
				max = planes;
			}
		}
	}

	std::cout << max << '\n';

	for (int i = 0; i < numOfBusyPeriods; ++i) {
		printPeriod(busyPeriods[i * 4], busyPeriods[i * 4 + 1], busyPeriods[i * 4 + 2], busyPeriods[i * 4 + 3]);
	}

	delete[] busyPeriods;
}

int main() {
	int num;

	std::cin >> num;

	if(num < 0) {
		std::cout << "Incorrect input";
		return 0;
	}

	char* arrivals = new char[num*4+1];
	char* departures = new char[num*4+1];

	for(int i = 0; i < num; ++i) {
		std::cin >> (arrivals + (i * 4));
	}

	for (int i = 0; i < num; ++i) {
		std::cin >> (departures + (i * 4));
	}

	printBusyPeriods(arrivals, departures, num);

	delete[] arrivals;
	delete[] departures;
}