#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node* next;
}node;

int empty(node* top)
{
    if(top==NULL)
        return 1;
    else
        return 0;
}

int full(node* top)
{
    node* p = (node*)malloc(sizeof(node));
    if(p==NULL)
        return 1;
    else
        return 0;
}

node* push(node *top, int val)
{
    if(full(top))
        printf("stack overflow");

    else
    {
        node* new = (node*)malloc(sizeof(node));
        new->data = val;
        new->next = top;
        top = new;
        return top;
    }
}

node* pop(node*top)
{
    if(empty(top))
        printf("stack underflow");
    else
    {
        node* n = top;
        printf("the deleted elements is %d",n->data);
        top = top->next;
        free(n);
    }   
    return top;
}

int stacktop(node*top)
{
    if(empty(top))
        return -1;
    else
        return top->data;
}

int stackbottom(node*top)
{
    if(empty(top))
        return -1;
    node* temp = top;
    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    return temp->data;
}

void display(node*top)
{
    node*temp = top;
    if(top==NULL)
        printf("The list is empty");
    else
    {
        printf("The elements are:\n");
        while(temp!=NULL)
        {
            printf("%d\n",temp->data);
            temp = temp->next;
        }
    }
}

int main()
{
    node* top = NULL;
    int val;
    int ch;
    while(1)
    {
        printf("\nEnter the choice: 1.push an element   2.pop   3.display list  4.stack top  5.stack bottom");
        scanf("%d",&ch);
        switch (ch)
        {
            case 1:
                {
                    printf("Enter the value:");
                    scanf("%d",&val);
                    top = push(top,val);
                }break;

            case 2: top = pop(top); break;

            case 3: display(top); break;

            case 4: val = stacktop(top);
                    printf("%d\n",val); 
                    break;

            case 5: val = stackbottom(top);
                    printf("%d\n",val);
                    break;

            default:
                    {
                        printf("Invalid choice");
                        exit(1);
                    } break;        
        }
    }
}
