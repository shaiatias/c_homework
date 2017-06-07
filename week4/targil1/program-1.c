
#include <stdio.h>


typedef int cmpFunc(void *, void *);


void generic_swap(void **a, void **b);

int simple_print(int count);

void do_callback(int count, int (*fun)(int));

void swap_pointers_in_list(void **pp, int i, int j);

int main1() {

    int aa = 1;
    int bb = 2;

    int *a = &aa;
    int *b = &bb;

    printf("%d, %d\n", *a, *b);

    generic_swap(&a, &b);

    printf("%d, %d\n", *a, *b);
}

int main2(){
    do_callback(5, simple_print);
}

int main(){

}

void generic_swap(void **a, void **b) {

    void *c;
    c = *a;

    *a = *b;
    *b = c;
}

void generic_swap_pointers(void *a, void *b, int size) {

    char *pa = (char *) a;
    char *pb = (char *) b;
    char c;

    while (size--) {

        c = *pa;

        *pa = *pb;
        *pb = c;

        pa++;
        pb++;
    }
}

int simple_print(int count) {
    printf("print: %d\n", count);
    return count;
}

void do_callback(int count, int (*fun)(int)) {

    for (int i = 0; i < count; ++i) {
        fun(i);
    }
}



void sort(void *list, int sizeOfElement, int totalBytes, cmpFunc compare){

    char *a = NULL;
    char *b = NULL;
    int n = totalBytes / sizeOfElement;

    for (int i = 0; i < n; ++i) {

        for (int j = 0; j < n; ++j) {

            a = (char *) list + i * sizeOfElement;
            b = (char *) list + j * sizeOfElement;

            int compared = compare(i, j);

            if (compared == -1) {
                generic_swap(a, b, sizeOfElement);
            }
        }
    }
}