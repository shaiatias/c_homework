
#include <stdio.h>

void getMaxConsecutiveNumbers(int origin[], int originLen, int *resultArr[], int *resultLen);

int getMax(int a, int b);

int getIndexOfMax(int arr[], int i);

int main(){

    int origin[] = {2, 8, -29, 19, 4};
    int originLen = sizeof(origin) / sizeof(origin[0]);

    int *result;
    int *resultLen;

    getMaxConsecutiveNumbers(origin, originLen, result, resultLen);

    for (int i = 0; i < resultLen; i++) {
        printf("%d ,", result[i]);
    }
}

void getMaxConsecutiveNumbers(int origin[], int originLen, int* resultArr[], int* resultLen) {

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

    resultArr[countItems];

    for (int i = 0; i < countItems; i++) {
        resultArr[i] = origin[i + 1 + indexOfMax - countItems];
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