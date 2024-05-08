#include<stdio.h>
#include<stdlib.h> 

typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}node; 

node* createNode(int ele){
    node* p = (node*) malloc(sizeof(node));
    p->data = ele;
    p->left = NULL;
    p->right = NULL; 
    return p;
}   

void preOrder(node* root){
    if(root != NULL){
        printf("%d\t",root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(node* root){
    if(root != NULL){
        postOrder(root->left);
        postOrder(root->right);
        printf("%d\t",root->data);
    }
}

void inOrder(node *root){
    if(root){
        inOrder(root->left);
        printf("%d\t",root->data);
        inOrder(root->right);
    }
}

int main(){   
    node *p = createNode(4);
    node *p1 = createNode(1);
    node *p2 = createNode(6);
    node *p3 = createNode(5);  
    node *p4 = createNode(2);
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    preOrder(p);

    /*
             4
            /  \
           1    6
          / \ 
        5    2
    */
   printf("\n");
   postOrder(p);
   printf("\n");
   inOrder(p);
    
    return 0;
}