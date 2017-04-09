#include <stdio.h>
#include "../myHeaders.h"

int main() {

    int num, ind;

    printf("enter a number: ");

    if (scanf("%d", &num) != 1){
        fprintf(stderr, "input is not numeric");
        return 1;
    }

    if (num < 1) {
        fprintf(stderr, "input is not positive");
        return 2;
    }

    printf("enter an indices: ");

    if (scanf("%d", &ind) != 1){
        fprintf(stderr, "input is not numeric");
        return 3;
    }

    if (ind < 1) {
        fprintf(stderr, "input is not positive");
        return 4;
    }

    int numLen = getLength(num);
    int maxInd = getMax(ind);

    if (maxInd > numLen) {
        fprintf(stderr, "indices out of bound");
        return 5;
    }

    int result = createNumByIdx(num,ind);
    int result2 = createNumByIdx(reverseNumber(num),ind);

    printf("1.1: %d, 1.2: %d", result, result2);

    return 0;
}

