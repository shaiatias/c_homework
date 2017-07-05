
#include <stdio.h>
#include <stdlib.h>

typedef struct TNode {
    char info;
    struct TNode *left, *right;
} TNode;

TNode *generateTree(char **firstChar) {

    if (**(firstChar) == '(' || **(firstChar) == ',' || **(firstChar) == ')') {
        return NULL;
    }

    TNode *root = malloc(sizeof(TNode));

    root->right = NULL;
    root->left = NULL;
    root->info = **firstChar;

    *(firstChar) = &*(*(firstChar) + 1);

    if (**(firstChar) == ',' || **(firstChar) == ')') {
        return root;
    }

    if (**firstChar != ',') {
        *(firstChar) = &*(*(firstChar) + 1);
        root->left = generateTree(firstChar);
    }

    *(firstChar) = &*(*(firstChar) + 1);

    if (**(firstChar) != ')') {
        root->right = generateTree(firstChar);
    }

    *(firstChar) = &*(*(firstChar) + 1);

    return root;
}

int main() {

//    char *text = "a(b,c)";          // OK
//    char *text = "a(,c)";         // OK
    char *text = "a";             // FAILED
//    char *text = "a(b(c,))";        // FAILED
    TNode *root = generateTree(&text);

    printf("%c", root->info);
}
