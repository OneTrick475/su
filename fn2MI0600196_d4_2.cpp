#include <iostream>

int MAX_LEN = 256;

int getLen(char str[]){
    int len = 0;
    
    while(str[len] != 0){
        len++;
    }
    return len;
}

bool isAnagram(char firstStr[], char secondStr[], int start, int end){
    int firstCounts[MAX_LEN] = {0};
    int secondCounts[MAX_LEN] = {0};

    for(int i = 0; i <= end - start; ++i){
        secondCounts[secondStr[i]]++;
    }

    for(int i = start; i <= end; ++i){
        firstCounts[firstStr[i]]++;
    }

    for(int i = 0; i < MAX_LEN; ++i){
        if(firstCounts[i] != secondCounts[i]){
            return false;
        }
    }
    return true;
}

void printAnagrams(char firstStr[], char secondStr[]){
    int firstLen = getLen(firstStr);
    int secondLen = getLen(secondStr);

    if(firstLen < secondLen){
        std::cout << "no anagrams";
        return;
    }

    bool isFirst = true;

    for(int i = secondLen - 1; i < firstLen; ++i){
        if(isAnagram(firstStr, secondStr, i - secondLen + 1, i)){
            if(!isFirst){
                std::cout << ", ";
            }
            std::cout << i - secondLen + 1;
            isFirst = false;
        }
    }
    if(isFirst){
        std::cout << "no anagrams";
    }
}

int main() {
    char firstStr[MAX_LEN + 1] = {0};
    char secondStr[MAX_LEN + 1] = {0};

    if(!std::cin.getline(firstStr, MAX_LEN)){
        std::cout << "no anagrams";
        return 0;
    }
    if(!std::cin.getline(secondStr, MAX_LEN)){
        std::cout << "no anagrams";
        return 0;
    }

    printAnagrams(firstStr, secondStr);
}
