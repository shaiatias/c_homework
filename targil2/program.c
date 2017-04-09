#include <stdio.h>
#include "../myHeaders.h"

int main() {

    char c;
    char prev;

    int wordsCount = 0;
    int charsCount = 0;
    int linesCount = 0;

    bool finish = false;

    while(c = getchar()){

        if (c == EOF) {
            break;
        }

        if (isNewLine(c)){
            linesCount++;
        }

        else {
            charsCount++;
        }

        if (isBegginingOfWord(prev, c)) {
            wordsCount++;
        }

        prev = c;
    }

    printf("words: %d, lines: %d, chars: %d", wordsCount, linesCount, charsCount);

    return 0;
}