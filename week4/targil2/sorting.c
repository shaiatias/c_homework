
#include <string.h>
#include "sorting.h"

void generic_swap_pointers(void *a, void *b, int size) {

    char *pa = (char *) a;
    char *pb = (char *) b;
    char c;

    while (size--) {

        c = *pa;

        *pa = *pb;
        *pb = c;

        pa++;
        pb++;
    }
}

void sort(void *list, int sizeOfElement, int totalBytes, cmpFunc compare) {

    char *a = NULL;
    char *b = NULL;
    int n = totalBytes / sizeOfElement;

    for (int i = 0; i < n; ++i) {

        for (int j = 0; j < n; ++j) {

            a = (char *) list + i * sizeOfElement;
            b = (char *) list + j * sizeOfElement;

            int compared = compare(a, b);

            if (compared > 0) {
                generic_swap_pointers(a, b, sizeOfElement);
            }
        }
    }
}

int cmpInt(void *a, void *b) {

    int aa = *(int *) a;
    int bb = *(int *) b;

    return bb - aa;
}

int cmpDbl(void *a, void *b) {

    double aa = *(double *) a;
    double bb = *(double *) b;

    if (aa == bb) {
        return 0;
    } else if (aa > bb) {
        return -1;
    } else {
        return 1;
    }
}

int cmpCharArr(void *a, void *b) {

    char *aa = (char *) a;
    char *bb = (char *) b;

    return strcmp(aa, bb) * -1;
}

int cmpCharPtr(void *a, void *b) {

    char *aa = *(char **) a;
    char *bb = *(char **) b;

    return strcmp(aa, bb) * -1;
}

