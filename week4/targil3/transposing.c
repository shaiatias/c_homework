
#include <stdio.h>
#include <malloc.h>

int getMaxFirstValue(int **intArrs) ;

int countArray(int **arrs) ;

void transpose(int **int_arrs) {

    int max_first_value;
    max_first_value = getMaxFirstValue(int_arrs);
    int arr_count = countArray(int_arrs);

    for (int cols = 1; cols < max_first_value; ++cols) {

        for (int rows = 0; rows < arr_count; ++rows) {

            int max_val = *(*(int_arrs + rows));

            if (max_val - 1 < cols) {
                printf("\t");
            } else {
                int value = *(*(int_arrs + rows) + cols);
                printf("%d\t", value);
            }
        }

        printf("\n");
    }
}

int ** do_transpose(int **intArrs) {

    int maxFirstValue = getMaxFirstValue(intArrs);
    int arr_count = countArray(intArrs);

    int mem_size = arr_count * maxFirstValue * sizeof(int);

    int **arrs = malloc(mem_size);

    for (int i = 0; i < arr_count; ++i) {

        for (int j = 0; j < maxFirstValue; ++j) {
            arrs[i*maxFirstValue +j] =  *(*(intArrs + j) + i);
        }
    }

    return arrs;
}

int getMaxFirstValue(int **intArrs) {

    int max_temp = 0;

    int count_arrs = countArray(intArrs);

    for (int i = 0; i < count_arrs; ++i) {

        int next = intArrs[i][0];

        if (next > max_temp) {
            max_temp = next;
        }
    }

    return max_temp;
}

int countArray(int **arrs) {

    int i = 0;

    while (*(arrs + i) != NULL) {
        i++;
    }

    return i;

}