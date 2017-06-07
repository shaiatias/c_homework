
#include <malloc.h>

void transpose(int **intArrs) {

    int maxFirstValue = getMaxFirstValue(intArrs);
    int arr_count = countArray(intArrs);

    int mem_size = arr_count * maxFirstValue * sizeof(int);

    int **arrs = malloc(mem_size);

    for (int i = 0; i < arr_count; ++i) {

        for (int j = 0; j < maxFirstValue; ++j) {
            arrs[i*maxFirstValue +j] =  *(*(intArrs + j) + i);
        }
    }
}

int countArray(int **arrs) {

    int i = 0;

    while (*(arrs + i) != NULL) {
        i++;
    }

    return i;

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