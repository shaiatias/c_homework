
#include <stdio.h>

void printWord(char *word);

void printAllStrings(char ***allStrings) {

    char **next_list = *allStrings;
    int i = 0;

    do {

        char *next_word = *next_list;
        int j = 0;

        do {
            printWord(next_word);
            printf(" ");

            j++;
            next_word = *(next_list + j);

        } while (next_word != NULL);

        printf("\n");

        i++;
        next_list = *(allStrings + i);

    } while (next_list != NULL);
}

void printWord(char *word) {

    int i = 0;

    while (*(word + i) != '\0'){

        printf("%c", *(word + i));

        i++;
    }
}
