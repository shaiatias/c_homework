
#include <stdlib.h>
#include <stdio.h>
#include "Nodes.h"

TNode *buildTree(LLNode *llist);

void insertNodeToTree(TNode *root, LNode *node);

void main(){

    LLNode *llist = malloc(sizeof(LLNode));

    llist->info = malloc(sizeof(LNode));
    llist->info->next = malloc(sizeof(LNode));
    llist->info->next->next = malloc(sizeof(LNode));
    llist->info->next->next->next = NULL;

    llist->info->info = 9;
    llist->info->next->info = 4;
    llist->info->next->next->info = 2;

    llist->next = malloc(sizeof(LLNode));
    llist->next->info = malloc(sizeof(LNode));
    llist->next->info->next = malloc(sizeof(LNode));
    llist->next->info->next->next = malloc(sizeof(LNode));
    llist->next->info->next->next->next = malloc(sizeof(LNode));
    llist->next->info->next->next->next->next = NULL;

    llist->next->info->info = 9;
    llist->next->info->next->info = 4;
    llist->next->info->next->next->info = 6;
    llist->next->info->next->next->next->info = 5;

    llist->next->next = NULL;

    buildTree(llist);
}



TNode *buildTree(LLNode *llist) {

    TNode *root = malloc(sizeof(TNode));

    root->info = llist->info->info;
    root->left = NULL;
    root->right = NULL;

    LLNode * i = llist;
    LNode * j;

    while (i != NULL) {

        j = i->info;

        while (j != NULL) {
            insertNodeToTree(root, j);
            j = j -> next;
        }

        i = i -> next;
    }

    return root;
}

void insertNodeToTree(TNode *root, LNode *node) {

    if (node->info == root->info){
        return;
    }
    else if (node->info > root->info){

        if (root->right == NULL) {

            TNode *child = malloc(sizeof(TNode));

            child->info = node->info;
            child->left = NULL;
            child->right = NULL;

            root->right = child;
        } else {
            insertNodeToTree(root->right, node);
        }
    }

    else {

        if (root->left == NULL) {

            TNode *child = malloc(sizeof(TNode));

            child->info = node->info;
            child->left = NULL;
            child->right = NULL;

            root->left = child;
        } else {
            insertNodeToTree(root->left, node);
        }

    }
}
