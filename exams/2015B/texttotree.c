
#include <stdio.h>
#include <stdlib.h>

typedef struct TNode {
    char info;
    struct TNode *left, *right;
} TNode;

TNode *generateTree(char **firstChar) {

    TNode *root = malloc(sizeof(TNode));
    root->right = NULL;
    root->left = NULL;

    if (**firstChar != ',' && **firstChar != ')' && **firstChar != '(') {
        root->info = **firstChar;
    } else {
        return NULL;
    }

    if (*(*(firstChar) + 1) == '(') {

        *(firstChar) = &*(*(firstChar) + 2);

        if (**firstChar == ',') {
//            *(firstChar) = &*(*(firstChar) + 1);
        }

        else {
            root->left = generateTree(firstChar);
//            *(firstChar) = &*(*(firstChar) + 1);
        }
    }

    if (**firstChar == ')'){
        return root;
    }

    else {
        *(firstChar) = &*(*(firstChar) + 1);
        root->right = generateTree(firstChar);
    }

    return root;
}

int main() {

//    char *text = "a(b,c)";    // OK
//    char *text = "a(,c)";     // OK
    char *text = "a";           // FAILED
//    char *text = "a(b(c,))";
    TNode *root = generateTree(&text);

    printf("%c", root->info);
}
