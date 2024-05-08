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

int isBST(node* root)
{   
    static node* prev = NULL;
    if(root!=NULL)
    {
        if(!isBST(root->left))
            return 0;
        
        if(prev!=NULL && root->data<=prev->data)
            return 0;
        
        prev = root;
        return isBST(root->right);    
    }

    else
      return 1;
}

void insert(node* root, int key)
{
  node* prev = NULL;
  while(root!=NULL)
  {
    prev = root;
    if(key==root->data)
    { 
      printf("Cannot insert %d, already in BST",key);
      return;
    }
    else if(key<root->data)
      root = root->left;
    else  
      root = root->right;
  }
  node* new = createnode(key);
  if(key<prev->data)
    prev->left = new;
  else
    prev->right = new;

}

int main()
{
  node* p = createnode(5);  
  node* p1 = createnode(3);  
  node* p2 = createnode(6);  
  node* p3 = createnode(1);  
  node* p4 = createnode(4);  


  p->left = p1;
  p->right = p2;
  p1->left = p3;
  p1->right = p4;

//   preorder(p);
//   printf("\n");
//   postorder(p);
//   printf("\n");
  // inorder(p);
  // printf("\n");
  // if(isBST(p))
  // {
  //   printf("The tree is Binary search tree");
  // }
  // else
  //   printf("It s not a Binary search tree");

  // return 0; 

  insert(p,16);
  printf("%d",p->right->right->data);
}