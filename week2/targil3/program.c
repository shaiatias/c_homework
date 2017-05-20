
#include <stdio.h>

void getMaxConsecutiveNumbers(int origin[], int originLen);

int getMax(int a, int b);

int getIndexOfMax(int arr[], int i);

int main(){

    int origin[] = {2, 8, -29, 19, 4};
    int originLen = sizeof(origin) / sizeof(origin[0]);

    getMaxConsecutiveNumbers(origin, originLen);
}

void getMaxConsecutiveNumbers(int origin[], int originLen) {

    int temp[originLen];

    temp[0] = origin[0];

    for (int i = 1; i < originLen; i++) {
        temp[i] = getMax(origin[i], origin[i] + temp[i - 1]);
    }

    int indexOfMax = getIndexOfMax(temp, originLen);
    int max = temp[indexOfMax];

    int countItems = 0;
    int sum = max;

    while (sum > 0) {
        sum = sum - origin[indexOfMax - countItems];
        countItems++;
    }

    for (int i = 0; i < countItems; i++) {
        printf("%d ", (origin[i + 1 + indexOfMax - countItems]));
    }
}

int getIndexOfMax(int arr[], int arrLen) {

    int maxIndex = 0;
    int max = arr[0];

    for (int i = 1; i < arrLen; i++) {

        if (arr[i] > max) {
            max = arr[i];
            maxIndex = i;
        }
    }

    return maxIndex;
}

int getMax(int a, int b) {

    if (a > b){
        return a;
    }

    else {
        return b;
    }
}