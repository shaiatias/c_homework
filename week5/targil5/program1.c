
#include <stdio.h>

void doReverse(FILE *f);

void doReverse(FILE *f) {

    fseek(f, 0, SEEK_END);

    int intCount = ftell(f) / sizeof(int) - 1;
    int i = 0;

    fseek(f, 0, SEEK_SET);

    while (intCount > i) {

        swap(f, i, intCount);

        intCount--;
        i++;
    }
}

void swap(FILE *f, int i, int j);

void swap(FILE *f, int i, int j) {

    int closerValue;
    int farValue;

    // get values

    fseek(f, i * sizeof(int), SEEK_SET);
    fread(&closerValue, sizeof(int), 1, f);

    fseek(f, j * sizeof(int), SEEK_SET);
    fread(&farValue, sizeof(int), 1, f);

    // swap values

    fseek(f, j * sizeof(int), SEEK_SET);
    fwrite(&closerValue, sizeof(int), 1, f);

    fseek(f, i * sizeof(int), SEEK_SET);
    fwrite(&farValue, sizeof(int), 1, f);
}

void main() {
    FILE *f = fopen("c:\\temp\\nums.bin", "rb+");
    doReverse(f);
    fclose(f);
}