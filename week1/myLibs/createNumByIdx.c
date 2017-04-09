
#include "../myHeaders.h"

int createNumByIdx(int num, int indices){

    int numLen = getLength(num);
    int indLen = getLength(indices);

    int numArr[numLen];
    int indArr[indLen];
    int resArr[indLen];

    int result = 0;

    for (int i = numLen - 1; i >= 0; --i) {
        numArr[i] = num % 10;
        num = num / 10;
    }

    for (int i = indLen - 1; i >= 0; --i) {
        indArr[i] = indices % 10;
        indices = indices / 10;
    }

    for (int i = 0; i < indLen; ++i) {
        resArr[i] = numArr[indArr[i]];
    }

    for (int i = 0; i < indLen; ++i) {

        result = result + resArr[i];

        if ((i + 1) != indLen) {
            result = result * 10;
        }
    }

    return result;
}
