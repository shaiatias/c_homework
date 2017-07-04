
#include <elf.h>
#include <malloc.h>
#include <stdio.h>

void **gLeaders(int n, int m, int  (*cmp)(void *, void *), void *base);

void **gLeaders(int n, int m, int (*cmp)(void *, void *), void *base) {

    char *base2 = (char *) base;

    char *max = &(*(base2 + m*(n-1)));
    long countMax = 1;

    for (int i = n - 2; i >= 0; i--) {

        char *temp = &(*(base2 + m*i));

        if (cmp(max, temp) < 0) {
            max = temp;
            countMax++;
        }
    }

    char *result = calloc(countMax, m + 1);

    *result = *(base2 + m*(n-1));
    int assignedResults = 1;

    *max = *(base2 + m*(n-1));

    for (int i = n - 2; i >= 0; i--) {

        char *temp = &(*(base2 + m*i));

        if (cmp(max, temp) < 0) {
            *(result + assignedResults) = *temp;
            assignedResults++;
        }
    }

    return (void **) result;
}

int compareInt(void *a, void *b) {

    int aa = *((int *) a);
    int bb = *((int *) b);

    return aa - bb;
}

int main() {

    int a[] = {6, 8, 3, 5};

    int **result = (int **) gLeaders(sizeof(a) / sizeof(int), sizeof(int), compareInt, &a);

    for (int i = 0; **(result + i) != NULL; i++) {
        printf("%d", **(result + i));
    }
}

