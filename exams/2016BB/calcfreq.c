
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>


int **gCalcFreq(int n[], int m, int  (*cmp)(void *, void *), void *base, ...);

int *getFreqForItem(int elementsCount, int sizeOfElement, int (*cmp)(void *, void *), void *item);

int compareInt(void *a, void *b) {

    int aa = *(int *) a;
    int bb = *(int *) b;

    return aa - bb;
}

int main() {

    int a[] = {5, 2, 3, 5};
    int b[] = {2, 8, 5};
    int c[] = {7, 5, 5, 5};

    int count[3] = {
            sizeof(a) / sizeof(int),
            sizeof(b) / sizeof(int),
            sizeof(c) / sizeof(int)
    };

    int **result = (int **) gCalcFreq(count, sizeof(int), compareInt, a, b, c, NULL);

    getchar();
}

int **gCalcFreq(int *n, int m, int (*cmp)(void *, void *), void *base, ...) {

    int countArrs = 0;

    va_list countList;
    va_start(countList, base);

    for (void *item = base; item != NULL; item = va_arg(countList, void*)) {
        countArrs++;
    }

    va_end(countList);

    //

    int **result = malloc(sizeof(int) * (countArrs + 1));

    va_list list;
    va_start(list, base);

    int i = 0;

    for (void *item = base; item != NULL; item = va_arg(list, void*), i++) {
        *(result + i) = getFreqForItem(n[i], m, cmp, item);
    }

    *(result + i) = NULL;

    return result;
}

int *getFreqForItem(int elementsCount, int sizeOfElement, int (*cmp)(void *, void *), void *item) {

    int *result = malloc((elementsCount + 1) * sizeOfElement);
    int foundElements = 0;

    for (int i = 0; i < elementsCount; i++) {
        void *x = (item + (i * sizeOfElement));

        int countX = 0;

        for (int j = 0; j < elementsCount; j++) {
            void *y = (item + (j * sizeOfElement));

            if (cmp(x,y) == 0) {
                countX++;
            }
        }

        result[foundElements] = countX;
        foundElements++;
    }

    result[foundElements] = NULL;

    result = realloc(result, sizeOfElement * foundElements);

    return result;
}