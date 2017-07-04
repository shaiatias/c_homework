
#include <stdbool.h>
#include <stdio.h>

bool isPreOrder(int *list, int start, int end);

bool isPreOrder(int *list, int start, int end) {

    if (start == end) {
        return true;
    }

    if (start > end) {
        return false;
    }

    int current = *(list + start);

    int i;

    for (i = start + 1; i < end; ++i) {

        int temp = *(list + i);

        if (temp > current) {

            if (!isPreOrder(list, start + 1, i - 1)) {
                return false;
            }

            break;
        }
    }

    if (!isPreOrder(list, i, end)) {
        return false;
    }

    return true;
}

int main(){

    //int a[7] = {10, 7, 3, 9, 8, 20, 25};
    int a[5] = {45,25,15,35,75};
    printf("%d", isPreOrder(a, 0, 4));
}