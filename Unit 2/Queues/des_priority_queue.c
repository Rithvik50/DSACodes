#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int front = -1;
int rear = -1;
int pqueue[MAX];


void check(int data)
{
    int i,j;
 
    for (i = 0; i <= rear; i++)
    {
        if (data >= pqueue[i])
        {
            for (j = rear + 1; j > i; j--)
            {
                pqueue[j] = pqueue[j - 1];
            }
            pqueue[i] = data;
            return;
        }
    }
    pqueue[i] = data;
}

void insert_by_priority(int x)
{
    if(rear>=MAX-1)
        printf("overflow");

    else if(front==-1 && rear==-1)
    {
        front=rear=0;
        pqueue[rear] = x;
    }

    else
    {
        check(x);    
    }
    rear++;
}

void delete_by_priority(int data)
{
    int i;
 
    if ((front==-1) && (rear==-1))
    {
        printf("\nQueue is empty no elements to delete");
        return;
    }
 
    for (i = 0; i <= rear; i++)
    {
        if (data == pqueue[i])
        {
            for (; i < rear; i++)
            {
                pqueue[i] = pqueue[i + 1];
            }
 
        pqueue[i] = -99;
        rear--;
 
        if (rear == -1) 
            front = -1;
        return;
        }
    }
}

void display_pqueue()
{
    if ((front == -1) && (rear == -1))
    {
        printf("\nQueue is empty");
        return;
    }
 
    for (; front <= rear; front++)
    {
        printf(" %d ", pqueue[front]);
    }
}

void main()
{
    int n, ch;
 
    printf("\n1 - Insert an element into queue");
    printf("\n2 - Delete an element from queue");
    printf("\n3 - Display queue elements");
    printf("\n4 - Exit");
 
   
 
    while (1)
    {
        printf("\nEnter your choice : ");    
        scanf("%d", &ch);
 
        switch (ch)
        {
        case 1: 
            printf("\nEnter value to be inserted : ");
            scanf("%d",&n);
            insert_by_priority(n);
            break;
        case 2:
            printf("\nEnter value to delete : ");
            scanf("%d",&n);
            delete_by_priority(n);
            break;
        case 3: 
            display_pqueue();
            break;
        case 4: 
            exit(0);
        default: 
            printf("\nChoice is incorrect, Enter a correct choice");
        }
    }
}







