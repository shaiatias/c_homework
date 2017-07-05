
#include <stdio.h>

//double (*(f(double (*)(int)))) (int);

double (*(f(double (*bb)(int), int x)))(int) {

    printf("%d\n", x);

    return bb;
}

double done(int x) {
    return (x / 3.0);
}

int main() {
    printf("%f", f(done, 1)(1));
}