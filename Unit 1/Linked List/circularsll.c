#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node* next;
}node;

node* createnode(int value)
{
    node*temp = (node*)malloc(sizeof(node));
    temp -> data = value;
    temp->next = temp;
    return temp;
}

node* insertfront(node* tail,int val)
{   
    node* new = createnode(val);

    if(tail==NULL)
        tail = new;
    
    else
    {
        new->next = tail->next;
        tail->next = new;
    }
    return tail;

}

node* insertend(node* tail,int val)
{   
    node* new = createnode(val);

    if(tail==NULL)
        tail = new;
    
    else
    {
        new->next = tail->next;
        tail->next = new;
        tail = tail->next;
    }
    return tail;

}

node* deletefront(node*tail)
{
    if(tail==NULL)
        return tail;

    if(tail->next==tail)
    {
        free(tail);
        tail=NULL;
        return tail;
    }
    
    node* temp = tail->next;
    printf("The deleted element is %d",temp->data);
    tail->next = temp->next;
    free(temp);
    temp=NULL;
    return tail;

}

node* deleteend(node* tail)
{
    node* temp = tail->next;

    if(tail==NULL)
        printf("The list is empty");

    if(tail->next==tail)
    {
        free(tail);
        tail=NULL;
        return tail;
    }
    else
    {
        while(temp->next!=tail)
        {
            temp = temp->next;
        }
        temp->next = tail->next;
        printf("The deleted element is %d",tail->data);
        free(tail);
        tail=temp;
        return tail;
    }
    return tail;
}

node* insertmid(node* tail,int val, int pos)
{
    node* temp = tail->next;
    node* new = createnode(val);

    while(pos>1)
    {
        temp = temp->next;
        pos--;
    }
    new->next = temp->next;
    temp->next = new;

    if(temp==tail)
    {
        tail = tail->next;
    }

    return tail;
}

node* deletemid(node* tail, int pos)
{
    node* temp = tail->next;
    if(tail==NULL)
        printf("The list is empty");
    
    if(tail->next==tail);
    {
        free(tail);
        tail = NULL;
        return tail;
    }

    while(pos>2)
    {
        temp = temp->next;
        pos--;
    }
    node* temp2 = temp->next;
    temp->next = temp2->next;

    if(temp2==tail)
        tail = temp;
    
    free(temp2);
    temp2=NULL;
    return tail;    
}

int search(node* tail,int ele)
{
    node* temp;
    int index=0;
    if(tail==NULL)
        return -2;

    temp = tail->next;

    do
    {
        if(temp->data==ele)
            return index;
        temp = temp->next;
        index++;
    } while (temp!=tail->next);

    return -1;  
}


void display(node* tail)
{
    node* temp = tail->next;
    if(tail==NULL)
        printf("The list is empty");
    else
    {
        printf("The elements are:");
        do
        {
            printf("%d ",temp->data);
            temp = temp->next;
        } while(temp!=tail->next);
    }
}

int main()
{
    node* tail = NULL;
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
                    tail = insertfront(tail,value);
                }break;

            case 2:
                  {
                    printf("Enter the value:");
                    scanf("%d",&value);
                    tail = insertend(tail,value);
                  }break;

            case 3:
                  {
                    tail = deletefront(tail);
                  }break;

            case 4:
                  {
                    tail = deleteend(tail);
                  } break;

            case 5:
                  {
                    printf("Enter the position:");
                    scanf("%d",&pos);
                    printf("Enter the value:");
                    scanf("%d",&value);
                    tail = insertmid(tail,value,pos);
                  } break;

            case 6:
                  {
                    printf("Enter the position:");
                    scanf("%d",&pos);
                    tail = deletemid(tail,pos);
                  } break;

            case 7:
                  {
                    printf("Enter the element to be searched:");
                    scanf("%d",&value);
                    int a = search(tail,value);
                    printf("The elemnt is found at %d\n",a);     
                  } break;
            
            // case 8:
            //       {
            //         head = reverse(head);
            //       }break;

            case 9:
                {
                    display(tail);
                } break;
            
            default:
                break;
        }
    }
}



