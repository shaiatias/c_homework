
#include <stdio.h>

void printBinary(int num, int size){

    int mask = (1 << (size*2 - 1));

    while (mask > 0) {

        int sum = mask & num;

        if (sum == 0)
            printf("0");

        else
            printf("1");

        mask = mask >> 1;
    }
}

int rotateNum(int num, unsigned int rotate){

    unsigned int temp = num;

    for (int i = 0; i < rotate; ++i) {

        int isOn = temp & 128;

        temp = temp << 1;

        temp = temp + (isOn == 0 ? 0 : 1);
    }

    return temp;
}

void chunckString(char str[9], unsigned int s1ize) {

    int size = sizeof(str) / sizeof(str[0]);

    for (int i = 0; i < size; ++i) {

        unsigned int digit = (unsigned int) str[i];

        short t = digit & 15;

        printBinary(t, sizeof(short));
    }
}

int main(){

    printf("2.1 print binary: 0, 10, 8, -128\n");

    printBinary(0, sizeof(int));
    printf("\n");

    printBinary(10, sizeof(int));
    printf("\n");

    printBinary(8, sizeof(int));
    printf("\n");

    printBinary(-128, sizeof(int));

    printf("\n\n");

    printf("2.2 rotate 100 by 3 gives\n");

    int result = rotateNum(100, 3);
    printBinary(100, sizeof(int));
    printf(" => ");
    printBinary(result, sizeof(int));

    printf("\n\n");

    printf("2.3 chunk the string 12345678 gives\n");
    chunckString("12345678", 9);
}
