
#include <stdlib.h>

struct Node {
    int info;
    struct Node *left, *right;
};

typedef struct Node Node;

int main(){

    Node* a = malloc(sizeof(Node));



    return 0;
}