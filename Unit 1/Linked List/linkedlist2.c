//Insert at end,deletete at end,insert at specified position, delete at specified position

#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node*link;
}node;

node* createnode(int value)
{
    node* temp = (node* )malloc(sizeof(node));
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

node* insertend(node* head,int value)
{
    node* new = createnode(value);
    node* temp = head;
    if(head==NULL)
    {
        new->link = head;
        head = new;
    }

    else
    {
        while(temp->link!=NULL)
        {
            temp = temp->link;
        }
        temp->link = new;
        new->link = NULL;
    }
    return head;        
}

//34 78 56 
//head = 34
//prev = 78
//temp = 56 (after traversing)
// print 56
// 78 - link = null
//free(56)

node* deleteend(node* head)
{
    node* temp = head;
    node* prev = NULL;
    if(head==NULL)
        printf("The list is empty");
    else
    {
        while(temp->link!=NULL)
        {   
            prev = temp;
            temp = temp->link;
        }
        printf("The deleted element is %d",temp->data);
        prev->link  = NULL;
        free(temp);
    }
    return head;
}

node* insertmid(node* head,int value,int pos)
{
    node* new = createnode(value);
    node* temp = head;

    if(head==NULL)
        head = new;
    else
    {
        for(int i=0;i<pos-1;i++)
        {
            temp = temp->link;
        }
        new->link = temp->link;
        temp->link = new;      
    }
    return head;
}

node* deletemid(node* head,int pos)
{
    node* temp = head;
    if(head==NULL)
        printf("The list is empty");
    else
    {
        for(int i=0;i<pos-1;i++)
        {
            temp = temp->link;
        }
        node* temp1 = temp->link;
        temp->link = temp1->link;

        free(temp1);
    }
    return head;    
}

int search(node* head, int value)
{
    node* temp = head;
    int pos=0;
    while(temp!=NULL)
    {
        if(temp->data==value)
            return pos;
        temp = temp->link;
        pos++;
    }
    return -1;
}

node* reverse(node* head)
{   
    node* new_head = NULL;
    node *old = head;
    
    while(old!=NULL)
    {
        node*new = createnode(old->data);
        new->link = new_head;
        new_head = new;
        old = old->link;        
    }
    return new_head;
}

node*concat(node*head, node*second)
{
    if(head==NULL && second==NULL)
        return NULL;
    else if(head==NULL)
        return second;
     else if(second==NULL)
        return head;
    else
    {
        node* temp = second;
        while(temp!=NULL)
        {
            insertend(head,temp->data);
            temp = temp->link;
        }
    }
    return head;

}

node* sort(node* head)
{
    node* temp = head;
    node* temp2 = NULL;

    if(head==NULL)
        printf("The list is empty");

    else
    {
        while(temp->link!=NULL)
        {
            temp2 = temp->link;

            while(temp2!=NULL)
            {
                if(temp->data>temp2->data)
                {
                    int t = temp2->data;
                    temp2->data = temp->data;
                    temp->data = t;
                }
                temp2 = temp2->link;
            }
            temp = temp->link;
        }
    }
    return head;
}

void display(node* head)
{  
    node* temp = head;
    if(head==NULL)
        printf("The list is empty");
    else
    {
        printf("The elements are:");
        while(temp!=NULL)
        {
            printf("%d ",temp->data);
            temp = temp->link;
        }
    }
}

int main()
{
    node* head=NULL;
    node* reverse_head = NULL;
    node* second = NULL;
    node* third = NULL;
    int ch,pos,value;
    while(1)
    {
        printf("\nEnter the choice 1.insert end  2.delete end  3.insert at a position  4.delete at a position  5.search an element 6.reverse 7.sort 8.display");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: 
                {  
                    printf("Enter the value:");
                    scanf("%d",&value);
                    head = insertend(head,value);
                } break;

            case 2: head = deleteend(head); break;

            case 3: 
                {
                    printf("Enter the position:");
                    scanf("%d",&pos);
                    printf("Enter the value:");
                    scanf("%d",&value);
                    head = insertmid(head,value,pos);
                }break;

            case 4:
                {
                    printf("Enter the position:");
                    scanf("%d",&pos);
                    head = deletemid(head,pos);
                }break;

            case 5: 
                   {
                        printf("Enter the element to be searched:");
                        scanf("%d",&value);
                        int a = search(head,value);
                        printf("The elemnt is found at %d\n",a);                        
                    } break;

            case 6: 
                   {
                    reverse_head = reverse(head); 
                    display(reverse_head); 
                    } break;

            case 7:
                    {
                        head = sort(head);
                    }break;

            case 8: {display(head);} break;

            default: 
                    {
                        printf("Invalid choice");
                        exit(1);
                    } break;
        }
    }
}

// void reverse(node **head)
// {
//     node *prev = NULL;
//     node *current = *head;
//     node *next = NULL;
//     while(current!=NULL)
//     {
//         next = current->link;
//         current->link = prev;
//         prev = current;
//         current = next;
//     }
// }