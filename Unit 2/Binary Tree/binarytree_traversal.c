#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node* left;
    struct node* right;
}node;

node* createnode(int val)
{
    node* new = (node*)malloc(sizeof(node));
    new->data = val;
    new->left = NULL;
    new->right = NULL;

    return new;
}

void preorder(node* root)
{
   if(root!=NULL)
   {
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
   } 
}

void postorder(node* root)
{
   if(root!=NULL)
   {
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
   } 
}

void inorder(node* root)
{
   if(root!=NULL)
   {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);   
   } 
}



int main()
{
  node* p = createnode(4);  
  node* p1 = createnode(1);  
  node* p2 = createnode(6);  
  node* p3 = createnode(5);  
  node* p4 = createnode(2);  


  p->left = p1;
  p->right = p2;
  p1->left = p3;
  p1->right = p4;

  preorder(p);
  
}