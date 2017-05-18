
#include <stdio.h>

void dividePolys(int poly1Arr[], int poly1Len, int poly2Arr[], int poly2Len);

int main(){

    int poly1[] = { 2, 4, 6 };
    int poly1Len = sizeof(poly1) / sizeof(poly1[0]);

    int poly2[] = { 1, 4, 6 };
    int poly2Len = sizeof(poly2) / sizeof(poly2[0]);

    dividePolys(poly1, poly1Len, poly2, poly2Len);
}

void dividePolys(int poly1Arr[], int poly1Len, int poly2Arr[], int poly2Len) {


}