#include <stdbool.h>
#include <stdio.h>

bool arrayContains(int *origin[], int originLen, int *search[], int searchLen);

int main() {

    int *origin[] = {2, 8, 14, -9, 5, 6, 2, 19, 4};
    int *search[] = {8, 5, 2, 4};

    int originLen = sizeof(origin) / sizeof(origin[0]);
    int searchLen = sizeof(search) / sizeof(search[0]);

    bool result = arrayContains(origin, originLen, search, searchLen);

    printf("result is: %s", (result ? "true" : "false"));
}

bool arrayContains(int *origin[], int originLen, int *search[], int searchLen) {

    int lastIndex = -1;

    for (int i = 0; i < searchLen; ++i) {

        bool found = false;

        for (int j = 0; j < originLen; ++j) {

            if (origin[j] == search[i] && j > lastIndex) {
                lastIndex = j;
                found = true;
                break;
            }
        }

        if (found == false) {
            return false;
        }
    }

    return true;
}