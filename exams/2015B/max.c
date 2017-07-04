#include <stdio.h>

int max(int x, int y) {
    return (x>=y)*x + (y>x)*y;
}

#define MAX(x,y) ((x>=y)*x + (y>x)*y)

int main () {
    printf("%d\n",MAX(2,8));
    printf("%d\n",MAX(9,max(2,8)));
    printf("%d\n",MAX(9,MAX(2,8)));
}