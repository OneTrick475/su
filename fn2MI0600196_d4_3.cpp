#include <iostream>

const int MAX_LEN = 255;

void checkBrackets(char str[]){
    char brackets[MAX_LEN];
    int bracketsIndex = 0;

    int strIndex = 0;

    while(str[strIndex] != 0){
        if(str[strIndex] == '('){
            brackets[bracketsIndex++] = '(';
        }
        if(str[strIndex] == ')'){
            if(bracketsIndex == 0){
                std::cout << "incorrect";
                return;
            }
            bracketsIndex -= 1;
        }
        ++strIndex;
    }
    if(bracketsIndex == 0){
        std::cout << "correct";
    }
    else{
        std::cout << "incorrect";
    }
}

int main() {
    char str[MAX_LEN + 1] = {0};

    if(!std::cin.getline(str, MAX_LEN + 1)){
        std::cout << "wrong input";
        return 0;
    }

    checkBrackets(str);
}