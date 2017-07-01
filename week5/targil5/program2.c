
#include <stdlib.h>
#include <stdbool.h>

void fill(int **arrs);

int main() {
    int A[] = {5, -5, 14, 5, 2};
    int B[4] = {4, 6, 11};
    int C[6] = {6, 1, -3, 4};
    int D[6] = {6, 2, 7, 1, 8, 2};
    int E[3] = {3, 15};
    int F[6] = {6, 4, -2};
    int *All[] = {A + 1, A + 4, B + 1, B + 2, C + 1, C + 3, D + 1, D + 5, E + 1, E + 1, F + 1, F + 2, NULL};
    fill(All);
}

void fill(int **arrs) {

    for (int i = 0; *(arrs + i) != NULL; i++, i++) {

        int firstInt = *(*(arrs + i));
        int sizeOfCurrentSubArr = *(*(arrs + i) - 1);
        int latInt = *(*(arrs + i + 1));

        bool overflow = false;

        for (int j = 0; j < sizeOfCurrentSubArr; j++) {

            if (overflow) {
                *(*(arrs + i) + j - 1) = latInt;
            } else {

                if (&*(*(arrs + i) + j - 1) == &*(*(arrs + i + 1))) {
                    overflow = true;
                }
            }
        }

    }
}