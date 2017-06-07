
#include <string.h>

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

int cmpCharArr(void *a, void *b) {

    char *aa = (char *) a;
    char *bb = (char *) b;

    return strcmp(aa, bb) * -1;
}

void sort(char ***list) {

    char **next_list = *list;
    int i = 0;

    do {

        char *next_word = *next_list;
        int j = 0;

        do {

            /////


            char **next_list_nested = *list;
            int i2 = 0;

            do {

                char *next_word_nested = *next_list_nested;
                int j2 = 0;

                do {

                    /////

                    int compared = cmpCharArr(next_word, next_word_nested);

                    if (compared > 0) {
                        generic_swap_pointers(&next_word, &next_word_nested, sizeof(char *));
                    }

                    /////

                    j2++;
                    next_word_nested = *(next_list_nested + j2);

                } while (next_word_nested != NULL);

                i2++;
                next_list_nested = *(list + i2);

            } while (next_list_nested != NULL);


            /////

            j++;
            next_word = *(next_list + j);

        } while (next_word != NULL);

        i++;
        next_list = *(list + i);

    } while (next_list != NULL);

}
