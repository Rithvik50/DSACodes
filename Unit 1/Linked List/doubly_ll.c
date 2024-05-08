#include<stdio.h>
#include<stdlib.h>

struct node
{
    struct node* prev;
    int data;
    struct node* next;
};

struct node*createnode(int value)
{
    struct node*temp = (struct node*)malloc(sizeof(struct node));
    temp -> prev = NULL;
    temp->data = value;
    temp->next = NULL;
    return temp;
}

struct node* insertfront(struct node *head,int val)
{
    struct node*new=createnode(val);
    if(head==NULL)
        head = new;
    
    else
    {
        new->next=head;
        head->prev = new;
        head=new;
        //return new;
    }
    return head;
}

struct node* insertend(struct node* head,int val)
{
    struct node*new = createnode(val);
    struct node* temp = head;

    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    temp->next = new;
    new->prev = temp;
    return head;
}

struct node* deletefront(struct node*head)
{
    struct node* temp;
    if(head==NULL)
        printf("The list is empty");
    else
    {
        temp = head;
        head = head->next;
        printf("The deleted element is %d",temp->data);
        free(temp);
        temp = NULL;
        head->prev = NULL;
    }
    return head;
}

struct node* deleteend(struct node* head)
{
    struct node* temp = head;
    struct node* temp2;
    if(head==NULL)
        printf("The list is empty");
    else
    {
        while(temp->next!=NULL)
        {   
            temp = temp->next;
        }
        printf("The deleted element is %d",temp->data);
        temp2 = temp->prev;
        temp2->next = NULL;
        free(temp);
    }
    return head; 
}

struct node* insertmid(struct node* head, int pos, int value)
{
    struct node* new = createnode(value);
    struct node* temp = head;
    struct node* temp2 = NULL;


    if(pos==1)
    {
        head = insertfront(head,value);
        return head;
    }
    
    while(pos>1)
    {
        temp = temp->next;
        pos--;
    } 

    if(head==NULL)
        head = new;
    
    else
    {
        temp2 = temp->next;
        temp->next = new;
        temp2->prev = new;
        new->next = temp2;
        new->prev = temp;
    }
    
    return head;
}

struct node* deletemid(struct node* head, int pos)
{
    struct node* temp = head;
    struct node* temp2 = NULL;

    if(pos==1)
    {
        head = deletefront(head);
        return head;
    }

    while(pos>1)
    {
        temp = temp->next;
        pos--;
    }

    if(head==NULL)
        printf("Empty list");
    
    else
    {
        temp2 = temp->prev;
        temp2->next = temp->next;
        temp->next->prev = temp2;
        free(temp);
        temp = NULL;
    }
    return head;
}

int search(struct node*head,int value)
{
    struct node* temp = head;
    int pos=0;
    while(temp!=NULL)
    {
        if(temp->data==value)
            return pos;
        temp = temp->next;
        pos++;
    }
    return -1;
}

struct node*reverse(struct node* head)
{
    struct node* temp1 = NULL;
    struct node *temp = head;
    
    while(temp!=NULL)
    {
        temp1 = temp->prev;
        temp->prev = temp->next;
        temp->next = temp1;
        temp = temp->prev;    
    }
    if(temp1!=NULL)
    {
        head = temp1->prev;
    }
    return head;
}

struct node* sort(struct node* head)
{
    
}

struct node* sort(struct node*head)
{
    
}

void display(struct node* head)
{
    struct node* temp = head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
}

int main()
{
    struct node* head = NULL;
    int ch,value,pos;
    while(1)
    {
        printf("\n1. insert front  2.insert end  3.delete front  4.delete end  5.insert at a position  6.delete at a position  7.search  8.reverse  9.display");
        scanf("%d",&ch);
        switch (ch)
        {
            case 1:
                {
                    printf("Enter the value:");
                    scanf("%d",&value);
                    head = insertfront(head,value);
                }break;

            case 2:
                  {
                    printf("Enter the value:");
                    scanf("%d",&value);
                    head = insertend(head,value);
                  }break;

            case 3:
                  {
                    head = deletefront(head);
                  }break;

            case 4:
                  {
                    head = deleteend(head);
                  } break;

            case 5:
                  {
                    printf("Enter the position:");
                    scanf("%d",&pos);
                    printf("Enter the value:");
                    scanf("%d",&value);
                    head = insertmid(head,value,pos);
                  } break;

            case 6:
                  {
                    printf("Enter the position:");
                    scanf("%d",&pos);
                    head = deletemid(head,pos);
                  } break;

            case 7:
                  {
                    printf("Enter the element to be searched:");
                    scanf("%d",&value);
                    int a = search(head,value);
                    printf("The elemnt is found at %d\n",a);     
                  } break;
            
            case 8:
                  {
                    head = reverse(head);
                  }break;

            case 9:
                {
                    display(head);
                } break;
            
            default:
                break;
        }
    }
}