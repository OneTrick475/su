#include <iostream>

using namespace std;

int main() {
	int n = 0;

	cin >> n;
	
	if (n < 1 || n > 1000000) {
		cout << "Incorrect input";
		return 1;
	}
 
	const int DIVISOR = 10;
 
    bool printZero = false;
 
	while (n / DIVISOR != 0 || n % DIVISOR != 0) {
		int num = (n % DIVISOR) * (n % DIVISOR);
		
		if(num != 0) {
		    printZero = true;
		}
        else if(printZero){
            cout<< 0;
        }

        while(num / DIVISOR != 0 || num % DIVISOR != 0){
            int currentNum = num % DIVISOR;
            
            if(n / DIVISOR == 0 && num / DIVISOR == 0) currentNum++;
            
            cout<< currentNum;
            
            num /= DIVISOR;
        }
        n /= DIVISOR;
	}
}
