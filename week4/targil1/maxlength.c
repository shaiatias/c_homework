#include <stdio.h>

char *maxLengthString(char ***allStrings) {

    char *result = NULL;
    int max_temp = 0;

    char **next_list = *allStrings;
    int i = 0;

    do {

        char *next_word = *next_list;
        int j = 0;

        do {

            int char_count = countCharInWord(next_word);

            if (char_count > max_temp) {
                max_temp = char_count;
                result = next_word;
            }

            j++;
            next_word = *(next_list + j);

        } while (next_word != NULL);

        i++;
        next_list = *(allStrings + i);

    } while (next_list != NULL);


    return result;
}

int countCharInWord(char *word) {

    int i = 0;

    while (*(word + i) != '\0') {
        i++;
    }

    return i;
}
