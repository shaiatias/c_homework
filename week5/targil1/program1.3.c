
#include <stdio.h>
#include <stdlib.h>

int *getHammingDistance(char ***strs);

int getSingleHammingDistance(char *a, char *b);


void printData(int *arr);

int main(){

    char *A[] = { "father", "mother", NULL };
    char *B[] = { "sister", "brother", "grandfather", NULL };
    char *C[] = { "grandmother", NULL };
    char *D[] = { "uncle", "aunt", NULL };

    char **arrPP[] = { A, B, C, D, NULL };

    int* result = getHammingDistance(arrPP);

    printData(result);
}

void printData(int *arr) {

    for (int i = 0; *(arr + i) > 0; i++) {
        printf("%d\n", *(arr + i));
    }
}

int *getHammingDistance(char ***strs) {

    int elementCount = 0;

    for (int i = 0; *(strs+i) != NULL; i++) {
        for (int j = 0; *(*(strs+i)+j) != NULL; j++) {
            elementCount++;
//            printf("%s", *(*(strs+i)+j));
        }
    }

    int *data = malloc( (elementCount*(elementCount-1) * sizeof(int)) );
    int dataFillCount = 0;

    for (int i = 0; *(strs+i) != NULL; i++) {

        for (int j = 0; *(*(strs+i)+j) != NULL; j++) {

            for (int ii = 0; *(strs+ii) != NULL; ii++) {

                for (int jj = 0; *(*(strs+ii)+jj) != NULL; jj++) {

//                    printf("%s\t", *(*(strs+i)+j));
//                    printf("%s\t", *(*(strs+ii)+jj));

                    int diff = getSingleHammingDistance(*(*(strs+i)+j), *(*(strs+ii)+jj));

//                    printf("%d\n", diff);

                    if (diff > 0) {
                        data[dataFillCount] = diff;
                        dataFillCount++;
                    }
                }
            }
        }
    }

    *(data + dataFillCount) = -1;

    data = realloc(data, dataFillCount * sizeof(int));

    return data;
}

int getSingleHammingDistance(char *a, char *b) {

    int c = 0;
    while (*a && *b) {

        if (*a != *b) {
            c++;
        }

        a++;
        b++;
    }

    return (*a || *b) ? -1 : c;
}