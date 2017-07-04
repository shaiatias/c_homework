
#include <stdio.h>

void writeIntersection(FILE *f1, FILE *f2);

int main() {

    int a[] = {1,2,5,7,9};
    int b[] = {1,3,5,9};

    FILE *f1 = fopen("c:\\temp\\file1.bin", "wb");
    fwrite(a, sizeof(int), 5, f1);
    fclose(f1);

    FILE *f2 = fopen("c:\\temp\\file2.bin", "wb");
    fwrite(b, sizeof(int), 4, f2);
    fclose(f2);

    /////

    f1 = fopen("c:\\temp\\file1.bin", "rb+");
    f2 = fopen("c:\\temp\\file2.bin", "rb+");

    writeIntersection(f1, f2);
}

void writeIntersection(FILE *f1, FILE *f2) {

    FILE *fresult = fopen("c:\\temp\\intersection.txt", "w");

    int f1int, f2int;

    if (!fread(&f1int, sizeof(int), 1, f1)) {
        fclose(fresult);
        return;
    }

    if (!fread(&f2int, sizeof(int), 1, f2)) {
        fclose(fresult);
        return;
    }

    while (1) {

        if (f1int == f2int) {

            fwrite(&f1int, sizeof(int), 1, fresult);
//            fprintf(fresult, "%d, ", f1int);

            if (!fread(&f1int, sizeof(int), 1, f1)) {
                break;
            }

            if (!fread(&f2int, sizeof(int), 1, f2)) {
                break;
            }

        } else if (f1int > f2int) {

            if (!fread(&f2int, sizeof(int), 1, f2)) {
                break;
            }
        } else {

            if (!fread(&f1int, sizeof(int), 1, f1)) {
                break;
            }
        }
    }

    fclose(fresult);
}

