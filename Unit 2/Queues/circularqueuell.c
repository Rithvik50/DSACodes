#include<stdio.h>
#include<stdlib.h>


typedef struct node
{
    int data;
    struct node*next;
}node;

node* front =0;
node* rear =0;

void enqueue(int x)
{
    node*new = (node*)malloc(sizeof(struct node));
    new->data = x;
    new->next = NULL;
    if(rear==0)
    {
        front = rear = new;
        rear->next = front;
    }
    else
    {
        rear->next = new;
        rear = new;
        rear->next = front;    
    }
}

void dequeue()
{
    node*temp = front;
    if(front==0 && rear==0)
        printf("The queue is empty");

    else if(front==rear)
    {
        printf("The deleted elementvis %d",front->data);
        front=rear=0;
        free(temp);
    }

    else
    {
        printf("The deleted elementvis %d",front->data);
        front = front->next;
        rear->next = front;
        free(temp);
    }
}

void peek()
{
    if(front==0 && rear==0)
        printf("The queue is empty");

    else
    {
        printf("%d ",front->data);
    }
} 

void display()
{
    node*temp = front;
    if(front==0 && rear==0)
        printf("The queue is empty");
    else
    {
        while(temp->next!=front)
        {
            printf("%d ",temp->data);
            temp = temp->next;
        }
        printf("%d ",temp->data);
    }

   
}