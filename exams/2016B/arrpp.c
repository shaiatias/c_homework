
#include <stdio.h>
#include <stdlib.h>

int getRepetitionsInWord(char *word);
char * getCharRepetitionsInWord(char *word);

char * getMaxStr(char ***arrPP, char *result){

    int wordsCount = 0;

    for (int i = 0; *(arrPP+i) != NULL; i++) {

        for (int j = 0; *(*(arrPP + i) + j) != NULL; j++) {

            char *word = *(*(arrPP + i) + j);
            int wordSize = sizeof(word) / sizeof(char);

            wordsCount = wordsCount + wordSize;
        }
    }

    /////

    char *res = malloc(sizeof(char) * wordsCount);
    int maxRepetitions = 0;
    int maxRepetitionsCount = 0;

    for (int i = 0; *(arrPP+i) != NULL; i++) {

        for (int j = 0; *(*(arrPP + i) + j) != NULL; j++) {

            char *word = *(*(arrPP + i) + j);

            int maxRepetitionsInWord = getRepetitionsInWord(word);
            char* maxRepetitionsCharInWord = getCharRepetitionsInWord(word);

            if(maxRepetitionsInWord > maxRepetitions) {
                maxRepetitions = maxRepetitionsInWord;
                maxRepetitionsCount = 0;
            }

            if (maxRepetitionsInWord < maxRepetitions){
            } else {

                for (int ii = 0; *(maxRepetitionsCharInWord+ii) != '\0'; ii++) {
                    *(res + maxRepetitionsCount) = *(maxRepetitionsCharInWord+ii);
                    maxRepetitionsCount++;
                }
            }
        }
    }

    res = realloc(res, sizeof(char) * maxRepetitionsCount);
    result = res;

    return res;
}

char * getCharRepetitionsInWord(char *word) {

    int *charsMapping[256];
    for (int i = 0; i < 256; i++) *(charsMapping+i) = 0;

    for (int j = 0; *(word+j) != '\0' ; j++) {
        char c = *(word+j);
        *(charsMapping + c) = *(charsMapping + c) + 1;
    }

    int max = 0;

    for (int i = 0; i < 256; i++) {
        int count = *(*(charsMapping+i));

        if (count > max) {
            max = count;
        }
    }

    int charsInMaxRes = 0;

    for (int i = 0; i < 256; i++) {
        int count = *(*(charsMapping+i));

        if (count == max) {
            charsInMaxRes++;
        }
    }

    char *res = malloc(sizeof(char) * charsInMaxRes);

    int jj = 0;

    for (int i = 0; i < 256; i++) {
        int count = *(*(charsMapping+i));

        if (count == max) {
            *(res + jj) = (char) **(charsMapping + i);
            jj++;
        }
    }

    *(res + jj) = '\0';

    return res;
}

int getRepetitionsInWord(char *word) {

    int *charsMapping[256];
    for (int i = 0; i < 256; i++) *(charsMapping+i) = 0;

    for (int j = 0; *(word+j) != '\0' ; j++) {
        char c = *(word+j);
        *(charsMapping + c) = *(charsMapping + c) + 1;
    }

    int max = 0;

    for (int i = 0; i < 256; i++) {
        int count = *(*(charsMapping+i));

        if (count > max) {
            max = count;
        }
    }

    return max;
}


int main() {

    char *arrP1[] = {"father", "mother", NULL};
    char *arrP2[] = {"sister", "brother", "grandfather", NULL};
    char *arrP3[] = {"grandmother", NULL};
    char *arrP4[] = {"uncle", "aunt", NULL};
    char **arrPP[] = {arrP1, arrP2, arrP3, arrP4, NULL};

    char *res;

    char *result = getMaxStr(arrPP, res);

    printf("%s | %s", result, res);
}