
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

void **gSubArray(int sizeOfArray, int sizeOfSub, int sizeOfItem, int (*cmp)(void *, void *), int *sub, int *base, ...);

void *getRepetitionsInArr(int (*cmp)(void *, void *), int sizeOfArray, int sizeOfItem, void *arr, int sizeOfSub, int *subArr);

int compareInt(void *a, void *b) {

    int aa = *(int *) a;
    int bb = *(int *) b;

    return aa - bb;
}

void main() {
    int a[] = {6, 2, 1, 1, 1, 2, 3, 5, 9, 0};
    int b[] = {2, 3, 5, 1, 9, 1, 2, 3, 7, 8};
    int c[] = {4, 6, 12, 3, 5, 1, 0, 1, 5, 4};
    int d[] = {2, 3, 5};

    int **result = (int **) gSubArray(sizeof(a) / sizeof(a[0]), sizeof(d) / sizeof(d[0]), sizeof(a[0]), compareInt, d, a, b, c, NULL);

    for (int *i = *result; i != NULL; i++) {
        printf("%d\t", *i);
    }

    getchar();
}

void **gSubArray(int sizeOfArray, int sizeOfSub, int sizeOfItem, int (*cmp)(void *, void *), int *sub, int *base, ...) {

    void **result = malloc(sizeof(void *) * 1);
    int resultCount = 1;
    *result = NULL;

    va_list list;
    va_start(list, base);

    for (void *item = base; item != NULL; item = va_arg(list, void*)) {

        void *res = getRepetitionsInArr(cmp, sizeOfArray, sizeOfItem, item, sizeOfSub, sub);

        int i = 0;

        for (void *x = (res + i); x != NULL; i++, x = (res + i)) {
        }

        result = realloc(result, (resultCount + i) * sizeof(void *));

        i = 0;

        for (void *x = (res + i); x != NULL; i++) {
            *(result + resultCount) = x;
            resultCount = resultCount + i;
        }

        *(result + resultCount) = NULL;
    }

    va_end(list);

    return result;
}

void *getRepetitionsInArr(int (*cmp)(void *, void *), int sizeOfArray, int sizeOfItem, void *arr, int sizeOfSub, int *subArr) {

    void **result = malloc(sizeof(void *) * sizeOfArray);
    int resultFound = 0;

    void *nextInSub = subArr;
    int found = 0;

    int i = 0;

    for (void *item = arr; i < sizeOfArray; i++, item = item + sizeOfItem) {

        if (cmp(nextInSub, item) == 0) {
            found++;
            nextInSub = nextInSub + sizeOfItem;

            if (found == (sizeOfSub - 1)) {
                *(result + (resultFound * sizeOfItem)) = item - sizeOfSub;
                resultFound++;

                nextInSub = subArr;
                found = 0;
            }

        } else {
            nextInSub = subArr;
            found = 0;
        }
    }

    result[resultFound] = NULL;

    return result;
}