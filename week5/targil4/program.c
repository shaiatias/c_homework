
#include "Nodes.h"
#include <stdio.h>
#include <stdlib.h>

Symbol* getSL(HNode *root);

int countNodesInTree(HNode *root);
void cbCounter(HNode *root, void*, Symbol* s);

void chainNodes(HNode *root, Symbol** symbols);
void cbAdder(HNode *root, void*, Symbol* s);

void traverseTree(HNode* root, void (*cb)(HNode*, void*, Symbol* s), void* additional, int depth);

void main(){

    HNode *root = malloc(sizeof(HNode));
    HNode *l = malloc(sizeof(HNode));
    HNode *ll = malloc(sizeof(HNode));
    HNode *lr = malloc(sizeof(HNode));
    HNode *r = malloc(sizeof(HNode));

    root->left=l;
    l->left=ll;
    l->right=lr;

    root->right=r;

    ll->left=NULL;
    ll->right=NULL;
    lr->left=NULL;
    lr->right=NULL;
    r->left=NULL;
    r->right=NULL;

    ll->chr = 'g';
    lr->chr = 'o';
    r->chr = 'e';

    Symbol* result = getSL(root);

    int i = 1;
}


Symbol *getSL(HNode *root) {

    int count = countNodesInTree(root);

    Symbol *list = (Symbol*) malloc(sizeof(Symbol) * count);

    for (int i = 0; i < count; ++i) {
        list[i].chr = '\0';
    }

    chainNodes(root, &list);

    return list;
}



int countNodesInTree(HNode *root) {
    int count = 0;
    traverseTree(root, cbCounter, &count, 0);
    return count;
}

void cbCounter(HNode *root, void* counter, Symbol* s) {
    int *count = (int *) counter;
    *(count) = *(count) + 1;
}

void cbAdder(HNode *root, void* chain, Symbol* s) {

    Symbol** symbols = (Symbol**) chain;
    static int i = 0;

    symbols[i] = s;
    i++;
}

void chainNodes(HNode *root, Symbol** symbols) {
    traverseTree(root, cbAdder, symbols, 0);
}

void traverseTree(HNode *root, void (*cb)(HNode *, void *, Symbol *), void *additional, int depth) {

    if (root -> left) {
        traverseTree(root -> left, cb, additional, depth+1);
    }

    if (root -> right) {
        traverseTree(root->right, cb, additional, depth+1);
    }

    if (root->right == NULL && root->left == NULL){

        Symbol *s = malloc(sizeof(Symbol));
        s->chr = root->chr;
        s->counter = depth;

        cb(root, additional, s);
    }
}
