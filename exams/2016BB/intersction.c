
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>
#include <memory.h>

int writeMerged(FILE **f);

int main() {

    int a[] = {1,2,5,7,9};
    int b[] = {2,3,5,9};
    int c[] = {4,5,9,10};

    FILE *f1 = fopen("c:\\temp\\file1.bin", "wb");
    fwrite(a, sizeof(int), 5, f1);
    fclose(f1);

    FILE *f2 = fopen("c:\\temp\\file2.bin", "wb");
    fwrite(b, sizeof(int), 4, f2);
    fclose(f2);

    FILE *f3 = fopen("c:\\temp\\file3.bin", "wb");
    fwrite(c, sizeof(int), 4, f3);
    fclose(f3);

    /////

    f1 = fopen("c:\\temp\\file1.bin", "rb+");

    if (errno != 0){
        printf("Error: %d (%s)\n", errno, strerror(errno));
        return errno;
    }

    f2 = fopen("c:\\temp\\file2.bin", "rb+");

    if (errno != 0){
        printf("Error: %d (%s)\n", errno, strerror(errno));
        return errno;
    }

    f3 = fopen("c:\\temp\\file3.bin", "rb+");

    if (errno != 0){
        printf("Error: %d (%s)\n", errno, strerror(errno));
        return errno;
    }

    FILE *f[] = { f1, f2, f3, NULL };

    int result = writeMerged(f);

    fclose(f1);
    fclose(f2);
    fclose(f3);

    return result;
}

int writeMerged(FILE **f) {
    FILE *fresult = fopen("c:\\temp\\intersection.txt", "w");

    if (errno != 0){
        printf("Error: %d (%s)\n", errno, strerror(errno));
        return errno;
    }

    int size = 0;

    for (int i = 0; *(f+i) != NULL; i++) {
        size++;
    }

    int *values = malloc(sizeof(int) * size);

    for (int i = 0; *(f+i) != NULL; i++) {
        FILE *temp = *(f+i);
        fread((values + i), sizeof(int), 1, temp);
    }

    while (1) {

        bool shouldExit = true;

        for (int j = 0; j < size; ++j) {

            if (*(f+j) != NULL) {
                shouldExit = false;
            }
        }

        if (shouldExit) {
            break;
        }

        int tempMin = *(values);
        int tempMinIndex = 0;

        for (int i = 1; i < size; i++) {

            if (*(values + i) < tempMin) {
                tempMin = *(values + i);
                tempMinIndex = i;
            }
        }

        printf("%d, ", tempMin);

        if (!fread(&*(values + tempMinIndex), sizeof(int), 1, *(f+tempMinIndex))) {
            fclose(*(f+tempMinIndex));
            *(f+tempMinIndex) = NULL;
        }
    }

    fclose(fresult);

    return 0;
}