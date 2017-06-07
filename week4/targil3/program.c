
#include <stdio.h>
#include "transposing.h"

int main() {

    int A[] = {5, -5, 14, 5, 2};
    int B[] = {3, 6, 11};
    int C[] = {4, 1, -3, 4};
    int D[] = {6, 2, 7, 1, 8, 2};
    int E[] = {2, 15};
    int F[] = {3, 4, -2};
    int *All[] = {A, B, C, D, E, F, NULL};

    transpose(All);
}
