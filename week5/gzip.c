

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <errno.h>
#include <memory.h>

int readGzip(FILE *f);

int readGzip(FILE *f) {

    // is valid
    char ID1, ID2;
    fread(&ID1, sizeof(char), 1, f);
    fread(&ID2, sizeof(char), 1, f);

    if (ID1 != 31 || ID2 != -117) {
        printf("file is not gzip\n");
        return 1;
    }

    // read flags
    fseek(f, 1, SEEK_CUR);

    char flags;
    fread(&flags, sizeof(char), 1, f);

    // last update time

    int updateTime;
    fread(&updateTime, sizeof(int), 1, f);

    if (updateTime == 0) {
        printf("time is not found\n");
    } else {
        printf("time: %d\n", updateTime);
    }

    // skip XFL, OS
    fseek(f, 2, SEEK_CUR);

    char maskEXTRA = 4;
    bool isEXTRA = flags & maskEXTRA;

    if (isEXTRA) {
        short extraLEN;
        fread(&extraLEN, sizeof(short), 1, f);
        fseek(f, extraLEN, SEEK_CUR);
    }

    // original file name

    char maskNAME = 8;
    bool isNAME = flags & maskNAME;

    if (isNAME) {

        long beforeName = ftell(f);

        char nextChar;
        unsigned int count = 0;

        while (1){
            fread(&nextChar, sizeof(char), 1, f);
            count++;

            if (nextChar == '\0') {
                break;
            }
        }

        fseek(f, beforeName, SEEK_SET);

        char *name = malloc(sizeof(char) * count);
        fread(name, sizeof(char), count, f);

        printf("the original filename is: %s\n", name);
    }

    return 0;
}

int main(){

    FILE *f = fopen("c:\\temp\\a.gz", "rb+");

    if (errno != 0){
        printf("Error: %d (%s)\n", errno, strerror(errno));
        return errno;
    }

    int error = readGzip(f);

    fclose(f);

    return error;
}