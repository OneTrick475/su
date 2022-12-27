#include <iostream>

void printArr(double arr[], int len){
    if(len == 0){
        std::cout << "no valid numbers";
    }
    for(int i = 0; i < len; ++i){
        std::cout << arr[i] << ' ';
    }
}

void shiftRight(double arr[], int start, int end){
    for(int i = end; i > start; --i){
        arr[i] = arr[i - 1];
    }
}

void insert(double num, double arr[], int len){
    for(int i = 0; i < len; ++i){
        if(num <= arr[i]){
            shiftRight(arr, i, len);
            arr[i] = num;
            return;
        }
    }
    arr[len] = num;
}

void printDoubles(int n){
    double* doubles = new double[n];
    int index = 0;

    while(n-- > 0){
        char curChar;
        std::cin >> curChar;

        double curNum = 0;

        bool dotPassed = false;

        double multiplier = 1;

        bool isValid = true;

        bool isNegative = false;
        if(curChar == '-'){
            isNegative = true;
            std::cin >> curChar;
        }

        while(curChar != '\n'){
            if((curChar == ',' || curChar == '.') && !dotPassed){
                dotPassed = true;
                curChar = std::cin.get();
                continue;
            }
            if(curChar < '0' || curChar > '9'){
                isValid = false;
            }

            if(dotPassed){
                multiplier /= 10;
                curNum += (curChar - '0') * multiplier;
            }
            else{
                curNum *= 10;
                curNum += curChar - '0';
            }
            curChar = std::cin.get();
        }
        curNum = isNegative ? -curNum : curNum;
        if(isValid){
            insert(curNum, doubles, index++);
        }
    }

    printArr(doubles, index);

    delete[] doubles;
}

int main(){
    int n;
    std::cin >> n;

    if(n < 3 || n > 50){
        std::cout << "no valid numbers";
        return 0;
    }

    printDoubles(n);
}