
#include "../myHeaders.h"

int reverseNumber(int num) {

    int lenNum = getLength(num);
    int temp;
    int result = 0;

    for (int i = 0; i < lenNum; ++i) {

        temp = num % 10;

        result = result + temp;

        // skip last digit
        if ( (i + 1) != lenNum) {
            result = result * 10;
        }

        num = num / 10;
    }

    return result;
}