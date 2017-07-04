
#include <stdio.h>

int(*f(int (*a[])()))(){

    int k=0;

    while (!a[k]()) {
        k++;
    }

    return a[k];
}

int a() { return 0; }
int b() { return 0; }
int c() { return 5; }

int main(){

    int (*arr[])() = {a,b,c};
    int result = f(arr)();

    printf("%d", result);
}