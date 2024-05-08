#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    struct node* prev;
    int data;
    struct node* next;
}node;

node* createnode(int val)
{
    node* new = (node*)malloc(sizeof(node));
    new->prev = new;
    new->data = val;
    new->next = new;
    return new;
}

node* insertfront(node* tail,int val)
{
    node* new = createnode(val);
    //       d__ p__n
    // new = 56 78 78 
    //temp = 78 78 78 
    //tail = 78 78 56

    if(tail==NULL)
        tail = new;
    else
    {
        node* temp = tail->next;
        new->prev = tail;
        new->next = temp;
        tail->prev = tail->next;
        tail->next = new;
    }
    return tail;
}

node*insertend(node* tail,int val)
{
    node* new = createnode(val);
    if(tail==NULL)
        tail = new;
    else
    {
        node*temp = tail->next;
        new->prev = tail;
        new->next = temp;
        tail->prev = new;
        tail->next = new;     
        tail = new;
    }
    return tail;
}

//56

node* deletefront(node* tail)
{
    node* temp = tail->next;
    printf("%d\n",temp->data);
    if(tail==NULL)
        printf("The list is empty");
        //return tail;

    if(temp==tail)
    {
        free(tail);
        tail=NULL;
        return tail;
    }
    
    printf("The deleted element is %d",temp->data);
    tail->next = temp->next;
    temp->next->prev = tail;
    free(temp);
    temp=NULL;
    return tail;

}

//78 56 34 76 54
//78
node* deleteend(node* tail)

{
    node* temp = tail->prev;

    printf("%d\n",temp->data);
    if(tail==NULL)
        printf("The list is empty");


    if(temp==tail)
    {
        free(tail);
        tail=NULL;
        return tail;
    }  

    printf("The deleted element is %d\n",tail->data);
    temp-> next = tail->next;
    printf("%d\n",temp->next->data);
    tail->next->prev = temp;
    printf("%d\n",tail->next->prev->data);
    free(tail);
    tail = temp;
    return tail;
}

node* insertmid(node* tail,int val,int pos)
{
    node* temp = tail->next;
    node* new = createnode(val);

    if(tail==NULL)
        tail=new;

    while(pos>1)
    {
        temp = temp->next;
        pos--;
    }
    new->prev = temp;
    new->next = temp->next;
    temp->next->prev = new;
    temp->next = new;

    if(temp==tail)
    {
        tail = tail->next;
    }

    return tail;
}

node* deletemid(node* tail,int pos)
{
    node* temp = tail->next;
    if(tail==NULL)
        printf("The list is empty");
    
    while(pos>1)
    {
        temp = temp->next;
        pos--;
    }
    node* temp2 = temp->prev;
    temp2->next = temp->next;
    temp->next->prev = temp2;
    free(temp);

    if(temp==tail)
        tail = temp2;
    
    return tail;    
}

void display(node* tail)
{   
    
    if(tail==NULL)
        printf("The list is empty");
    //45 78 56 34
    else
    {
        node* temp = tail->next; 
        do
        {
            printf("%d %d %d\n",temp->data,temp->prev->data,temp->next->data);
            //printf("\n%d ",temp->data);
            //printf("\n%d ",temp->prev->data);
            //printf("\n%d ",temp->next->data);
            temp = temp->next;
        } while (temp!=tail->next);   
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

            // case 7:
            //       {
            //         printf("Enter the element to be searched:");
            //         scanf("%d",&value);
            //         int a = search(tail,value);
            //         printf("The elemnt is found at %d\n",a);     
            //       } break;
            
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