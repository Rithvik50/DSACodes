#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node* left;
    struct node* right;
}node;

node* create(int ele)
{
    node*new = (node*)malloc(sizeof(node));
    new->data = ele;
    new->right = NULL;
    new->left = NULL;

    return new;
}

int main()
{

}