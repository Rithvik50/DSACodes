#include<stdio.h>
#include<stdlib.h>

typedef struct NODE
{
    int key;
    struct NODE* left;
    struct NODE* right;
    int height;
}node;

int getheight(node* n)
{
    if(n==NULL)
        return 0;
    
    return n->height;
}

node* createnode(int val)
{
    node* new = (node*)malloc(sizeof(node));
    new->key = val;
    new->left = NULL;
    new->right = NULL;
    new->height = 1;

    return new;
}

int getBalanceFactor(node* n)
{
    if(n==NULL)
        return 0;
    return getheight(n->left) - getheight(n->right);
}

node* leftrotate(node* y)
{
    node* x =  y->left;
    
}