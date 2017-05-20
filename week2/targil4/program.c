
#include <stdio.h>
#include <stdarg.h>

int maxSubArraySum(int size, ...);

int main() {
    int n = 5;
    maxSubArraySum(n, 2, 8, -29, 19, 4);
}

int maxSubArraySum(int size, ...) {

    int max_so_far = 0;
    int max_ending_here = 0;
    int start = 0;
    int end = 0;
    int s = 0;
    va_list param;

    va_start(param, size);

    for (int i = 0; i < size; i++) {

        max_ending_here += va_arg(param, int);

        if (max_so_far < max_ending_here) {
            max_so_far = max_ending_here;

            start = s;
            end = i;
        }

        if (max_ending_here < 0) {

            max_ending_here = 0;
            s = i + 1;
        }
    }

    va_end(param);

    va_start(param, size);

    int k;

    for (int i = 0; i < size; i++) {

        k = va_arg(param, int);

        if (i >= start && i <= end)
            printf("%d ", k);
    }

    va_end(param);
}



