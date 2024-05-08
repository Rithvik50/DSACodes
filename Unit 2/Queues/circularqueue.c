#include<stdio.h>
#include<stdlib.h>
#define N 5

int front = -1;
int rear = -1;
int queue[N];

void enqueue(int x)
{
  if(front==-1 && rear==-1)
  {
    front = rear = 0;
    queue[rear] = x;
  }

  else if(((rear+1)%N)==front)
  {
    printf("queue is full");
  }

  else
  {
    rear = (rear+1)%N;
    queue[rear] = x;
  }
}

void dequeue()
{
  if(front==-1 && rear==-1)
    printf("The queue is empty");
  
  else if(front==rear)
  {
    printf("The deleted element is %d",queue[front]);
    front=rear = -1;
  }

  else
  {
    printf("The deleted element is %d",queue[front]);
    front = (front+1)%N;
  }
}

void display()
{   
    int i = front;
    if(front==-1 && rear==-1)
        printf("The queue is empty");

    else
    {
      while(i!=rear)
      {
        printf("%d ",queue[i]);
        i = (i+1)%N;
      }
      printf("%d ",queue[rear]);
    }
}

void peek()
{
    if(front==-1 && rear==-1)
        printf("The queue is empty");

    else
    {
        printf("\n%d\n",queue[front]);
    }
}
