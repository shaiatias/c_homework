
#include <stdio.h>
#include <string.h>
#include "sorting.h"

int main() {

    int intArr[] = {1, 9, 5};
    sort(intArr, sizeof(intArr[0]), sizeof(intArr), cmpInt);

    double doubleArr[] = {1.1, 1.0, 5.0};
    sort(doubleArr, sizeof(doubleArr[0]), sizeof(doubleArr), cmpDbl);

    char c[][5] = {"abc", "xy", "ac"};
    sort(c, sizeof(c[0]), sizeof(c), cmpCharArr);

    char *d[] = {"abc", "xy", "ac"};
    sort(d, sizeof(d[0]), sizeof(d), cmpCharPtr);
}