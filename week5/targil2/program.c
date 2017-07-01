
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

void *** gMax(int n, int m, int  (*cmp)(void *, void *), void *base, ...);

int cmpInt(void *a, void *b);

void printResults(int ***arr);

int cmpInt(void *a, void *b) {

    int aa = *(int*) a;
    int bb = *(int*) b;

    return (aa - bb);
}

void main() {
    int a[] = {5, 2, 3, 5};
    int b[] = {2, 8, 8, 8};
    int c[] = {7, 6, 12, 5};

    void ***result = gMax(4, sizeof(int), cmpInt, a, b, c, NULL);

    printResults((int ***) result);
}

void printResults(int ***arr) {

    for (int i = 0; *(arr+i) != NULL; i++) {

        for (int j = 0; *(*(arr+i)+j) != NULL; j++) {

            printf("%d\n", **(*(arr+i)+j));
        }
    }
}

void *** gMax(int n, int m, int (*cmp)(void *, void *), void *base, ...) {

    int arrsCount = 0;

    va_list count_list;
    va_start(count_list, base);

    for (char *item = base; item != NULL; item = va_arg(count_list, char*)) {
        arrsCount++;
    }

    va_end(count_list);

    //////

    char ***result = malloc(sizeof(char*) * (arrsCount + 1));

    //////

    va_list list;
    va_start(list, base);
    int i = 0;

    for (char *item = base; item != NULL; item = va_arg(list, char*), i++) {

        void *max = NULL;
        int countMax = 0;

        for (int j = 0; j < n; j++) {

            if (max == NULL) {
                max = item;
                countMax = 1;
            }

            else if (cmp(item+(m*j), max) == 0) {
                countMax++;
            }

            else if (cmp(item+(m*j), max) > 0) {
                countMax = 1;
                max = item+(m*j);
            }
        }

        //////

        char **subResult = malloc(sizeof(char*) * (countMax+1));

        int latestMaxIndex = 0;
        max = NULL;

        for (int j = 0; j < n; j++) {

            if (max == NULL) {
                max = item;

                *(subResult) = item+(m*j);
                latestMaxIndex = 1;
            }

            else if (cmp(item+(m*j), max) == 0) {
                *(subResult + latestMaxIndex) = item+(m*j);
                latestMaxIndex++;
            }

            else if (cmp(item+(m*j), max) > 0) {
                max = item+(m*j);

                *(subResult) = item+(m*j);
                latestMaxIndex = 1;
            }
        }

        *( subResult + countMax + 1 ) = NULL;

        *(result + i) = subResult;

        //////
    }

    va_end(list);

    *( result + (arrsCount + 1) ) = NULL;

    return (void ***) result;
}