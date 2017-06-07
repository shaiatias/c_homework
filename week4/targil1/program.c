
#include <stdio.h>
#include <string.h>
#include "printing.h"
#include "maxlength.h"
#include "sorting.h"

int main() {

    char *arrP1[] = {"father", "mother", NULL};
    char *arrP2[] = {"sister", "brother", "grandfather", NULL};
    char *arrP3[] = {"grandmother", NULL};
    char *arrP4[] = {"uncle", "aunt", NULL};
    char **arrPP[] = {arrP1, arrP2, arrP3, arrP4, NULL};

    printAllStrings(arrPP);

    printf("\n");

    sort(arrPP);

    printf("\n");

    printAllStrings(arrPP);

    printf("\n");

    printf("%s\n", maxLengthString(arrPP));

    return 0;
}
