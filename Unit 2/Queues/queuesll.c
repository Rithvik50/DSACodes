#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node* next;
}node;

node* front = 0;
node* rear = 0;

void enqueue(int val)
{
    node* new = (node*)malloc(sizeof(node));
    new->data = val;
    new->next = NULL;

    if(front==NULL && rear==NULL)
    {
       front = rear = new;
    }
    else
    {
        rear->next = new;
        rear = new;
    }

}

void dequeue()
{
    node* temp;
    temp = front;
    if(front==NULL && rear==NULL)
        printf("Queue is empty");
    else
    {
        printf("The dequeued element is %d\n",front->data);
        front = front->next;
        freee(temp);
    }
}

void display()
{
    node* temp;
    if(front==NULL && rear==NULL)
        printf("Queue is empty");

    else
    {
        temp = front;
        while(temp!=NULL)
        {
            printf("%d ",temp->data);
            temp = temp->next;
        }
    }
}

void peek()
{
    if(front==NULL && rear==NULL)
        printf("Queue is empty");


    else
    {
        printf("%d\n",front->data);
    }   
}