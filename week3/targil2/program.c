
#include <stdio.h>

void printBinary(int num, int size){

    unsigned int mask = (unsigned int) (1 << size);

    while (mask > 0) {

        int sum = mask & num;

        if (sum == 0)
            printf("0");

        else
            printf("1");

        mask = mask >> 1;
    }

//    printf("\n");
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

        printBinary(t, 3);
        printf(" ");
    }
}

int main(){

//    printBinary(0, 8);
//    printBinary(10);
//    printBinary(8);
//    printBinary(-128);

//    int result = rotateNum(100, 3);
//    printBinary(100);
//    printBinary(result);

    chunckString("12345678", 9);
}
