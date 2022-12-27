#include <iostream>

void resize(int* &arr, int size){
    int* temp = new int[size*2];

    for(int i = 0; i < size; ++i){
        temp[i] = arr[i];
    }

    delete[] arr;
    arr = temp;
}

bool isPassed(int passed[], int len, int firstAmount, int secondAmount){
    for(int i = 0; i < len; i += 2){
        if(passed[i] == firstAmount && passed[i+1] == secondAmount){
            return true;
        }
    }
    return false;
}

int getMin(int arr[], int len){
    if(len == 0){
        return -1;
    }
    int min = arr[0];
    
    for(int i = 1; i < len; ++i){
        min = arr[i] < len ? arr[i] : min;
    }
    return min;
}

int getSteps(int first, int second, int target){
    if(first > second){
        int temp = second;
        second = first;
        first = temp;
    }
    if(target > second){
        return -1;
    }

    int currSize = 90;
    int* current = new int[currSize] { 0, 0, 0};
    int currIndex = 3;
    int currIndexLeft = 0;

    int passedSize = 60;
    int* passed = new int[passedSize] { 0, 0};
    int passedIndex = 2;

    while(currIndexLeft < currIndex){
        int firstAmount = current[currIndexLeft];
        int secondAmount = current[currIndexLeft + 1];
        int steps = current[currIndexLeft + 2];
        currIndexLeft += 3;
        if(firstAmount == target || secondAmount == target){
            return steps;
        }

        int states[18] = {};
        int i = 0;

        states[i++] = first;
        states[i++] = secondAmount;
        states[i++] = steps + 1;

        states[i++] = firstAmount;
        states[i++] = second;
        states[i++] = steps + 1;

        states[i++] = 0;
        states[i++] = secondAmount;
        states[i++] = steps + 1;

        states[i++] = firstAmount;
        states[i++] = 0;
        states[i++] = steps + 1;

        states[i++] = first > firstAmount + secondAmount ? firstAmount + secondAmount : first;
        states[i++] = secondAmount < first - firstAmount ? 0 : second - (first - firstAmount);
        states[i++] = steps + 1;

        states[i++] = firstAmount + secondAmount < second ? 0 : firstAmount - (second - secondAmount);
        states[i++] = firstAmount + secondAmount > second ? second : firstAmount + secondAmount;
        states[i++] = steps + 1;

        for(int i = 0; i < 18; i += 3){
            int firstAmount = states[i]; 
            int secondAmount = states[i+1];
            int steps = states[i+2];
            if(isPassed(passed, passedIndex, firstAmount, secondAmount)){
                continue;
            }

            if(currIndex == currSize){
                resize(current, currSize);
            }
            if(passedIndex == passedSize){
                resize(passed, passedSize);
            }

            current[currIndex++] = firstAmount;
            current[currIndex++] = secondAmount;
            current[currIndex++] = steps;

            passed[passedIndex++] = firstAmount;
            passed[passedIndex++] = secondAmount;
        }
    }
    return -1;
}

int main() {
    int first, second, target;

    std::cin >> first >> second >> target;

    if(first < 1 || second < 1 || first > 20 || second > 20){
        std::cout << -1;
        return 0;
    }

    std::cout << getSteps(first, second, target);

}