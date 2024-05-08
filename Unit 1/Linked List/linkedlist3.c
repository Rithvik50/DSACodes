#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100

struct list
{
    int arr[MAX_SIZE];
    int size;
};

void init(struct list*lst)
{
    lst->size = 0;
}

int isFull(struct list* lst)
{
    return lst->size==MAX_SIZE-1;
}

int isEmpty(struct list* lst)
{
    return lst->size==0;
}

void insertTail(struct list* lst, int value)
{
    if(!isFull(lst))
    {
        lst->arr[lst->size]=value;
        lst->size++;
    }
    else
        printf("List is full\n");
}

void insertHead(struct list* lst, int value)
{
    if(!isFull(lst))
    {
        for(int i=lst->size;i>0;i--)
        {
            lst->arr[i] = lst->arr[i-1];
        }
        lst->arr[0]=value;
        lst->size++;
    }
    else
        printf("List is full\n");
}

int delete_pos(struct list* lst, int pos)
{
    if(isEmpty(lst))
        printf("The list is empty");

    else if(pos > lst->size)
        printf("Value out of bound");
  
    else
    {
        for(int i=0;i<pos;i++)
        {
            if(i==pos-1)
            {
                for(i = pos-1;i<MAX_SIZE;i++)
                {
                    lst->arr[i] = lst->arr[i+1];
                }
            }
        }
        lst->size = lst->size-1;
        return lst->size;
    }

}

int delete_value(struct list *lst, int value)
{
    int flag = 0;
    if(isEmpty(lst))
        printf("Empty list!");

    int posn = 0;
    for(int i=0;i<MAX_SIZE;i++)
    {
        if(value == lst->arr[i])
        {
           posn = i;
           for(int j=posn;j<MAX_SIZE;j++)
                lst->arr[i] = lst->arr[i+1];
           flag = 1;
        }
    }
    if(flag == 0)
        printf("Value not found");
    
    else
        printf("Value deleted!");

    lst->size = lst->size - 1;
    return lst->size;
}


void display(struct list*lst)
{
    if(!isEmpty(lst))
    {
        for(int i=0;i<lst->size;i++)
        {
            printf("%d ",lst->arr[i]);
        }
    }
}



int main()
{
    struct list lst;
    init(&lst);
    int choice,value;
    while(1)
    {
        printf("\n1.Insert tail\n");
        printf("2.Insert head\n");
        printf("3.Delete\n");
        printf("4.Display\n");
        printf("5.Exit(0)\n");

        printf("Enter the choice:");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1: printf("Enter the value:");
                    scanf("%d",&value);
                    insertTail(&lst,value);
                    break;

            case 2: printf("Enter the value:");
                    scanf("%d",&value);
                    insertHead(&lst,value);
                    break;

            case 3: printf("Enter the value to delete:");
                    scanf("%d",&value);
                    delete_value(&lst,value);
                    break;

            case 4: display(&lst);
                    break;
            
            case 5: exit(0); break;

            default: printf("Invalid choice"); break;

        }
    }
    return 0;
}
