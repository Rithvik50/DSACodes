//Implementation of linked list
//perform insert_front,delete_front and dispaly

#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node*link;
}node;

node*createnode(int value)
{
    node*temp = (node*)malloc(sizeof(node));
    temp -> data = value;
    temp->link = NULL;
    return temp;
}

node*insertfront(node*head,int value)
{
    node*new = createnode(value);
    if(head==NULL)
        head = new;
    
    else
    {
        new->link = head;
        head = new;
    }
}

node*deletefront(node*head)
{
    node*temp;
    if(head==NULL)
        printf("The list is empty");
    else
    {
        temp = head;
        head = head->link;
        printf("The deleted element is %d",temp->data);
        free(temp);
    }
    return head;
}

void display(node*head)
{   
    node*temp = head;
    if(head==NULL)
        printf("The list is empty");
    else
    {
        printf("The elements are:");
        while(temp!=NULL)
        {
            printf("%d ",head->data);
            head = head->link;
        }
    }
}

int main()
{   
    node*head=NULL;
    int n; int value;
    while(1)
    {
        printf("\nEnter the choice: 1.insert front   2.delete front   3.display list");
        scanf("%d",&n);
        switch (n)
        {
            case 1:
                {
                    printf("Enter the value:");
                    scanf("%d",&value);
                    head = insertfront(head,value);
                }break;

            case 2: head = deletefront(head); break;

            case 3: display(head); break;

            default:
                    {
                        printf("Invalid choice");
                        exit(1);
                    } break;        
        }
    }
}

