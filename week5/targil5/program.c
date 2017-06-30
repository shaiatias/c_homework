
#include <stdio.h>

void main(){

    FILE* f = fopen("c:\\temp\\nums.bin", "wb");

    short lst[5] = {1,2,3,4,9};
    fwrite(lst,sizeof(lst),1,f);

    fclose(f);

    //////

    printf("\nBEFORE:\n");

    f = fopen("c:\\temp\\nums.bin", "rb");

    int temp;

    fseek(f, 0, SEEK_SET);

    while ( ( temp = fgetc( f ) ) != EOF ) {
        printf("%c ", temp + 48);
    }

    fclose(f);

    //////

    f = fopen("c:\\temp\\nums.bin", "rb");

    fseek(f, 0, SEEK_END);

    long charSize = ftell(f);
    long i = 0;

    fclose(f);

    while (charSize > i) {

        f = fopen("c:\\temp\\nums.bin", "rb");

        fseek(f, i, SEEK_SET);
        int closerValue = fgetc( f );

        fseek(f, charSize, SEEK_SET);
        int farValue = fgetc( f );

        fclose(f);

        f = fopen("c:\\temp\\nums.bin", "wb");

        fseek(f, charSize, SEEK_SET);
        fputc(closerValue, f);

        fseek(f, i, SEEK_SET);
        fputc(farValue, f);

        fclose(f);

        charSize--;
        i++;
    }

    //////////////

    printf("\nAFTER:\n");

    f = fopen("c:\\temp\\nums.bin", "rb");

    while ( ( temp = fgetc( f ) ) != EOF ) {
        printf("%c ", temp + 48);
    }

    fclose(f);
}