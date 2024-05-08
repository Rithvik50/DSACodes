#include<stdio.h>
#include<stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack* ptr)
{
    if(ptr->top==-1)
        return 1;
    else
        return 0;
}

int isFull(struct stack* ptr)
{
    if(ptr->top==ptr->size-1)
        return 1;
    else
        return 0;
}

void push(struct stack* ptr,int val)
{
    if(isFull(ptr))
        printf("Stack Overflow! cannot push %d to the stack\n",val);
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }

}

int pop(struct stack* ptr)
{
    if(isEmpty(ptr))
    {
        printf("Stack Underflow! cannot pop from the stack\n");
        return -1;
    }

    else
    {
        int val=ptr->arr[ptr->top];
        ptr->top=ptr->top-1;
        return val;
    }

}

int peek(struct stack *sp, int i)
{
    int arrayindex = sp->top-i+1;
    if(arrayindex<0)
        printf("Not a valid position");
    else
        return sp->arr[arrayindex];

}

int stacktop(struct stack* sp)
{
    return sp->arr[sp->top];
}

int stackbottom(struct stack* sp)
{
    return sp->arr[0];
}

int main()
{
    // struct stack s;
    // s.size = 80;
    // s.top=-1;
    // s.arr = (int *)malloc(s.size * sizeof(int));

    // struct stack *s;
    // s->size = 10;
    // s->top=-1;
    // s->arr = (int *)malloc(s->size * sizeof(int));



    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 10;
    sp->top=-1;
    sp->arr = (int *)malloc(sp->size * sizeof(int));
    push(sp,24);
    push(sp,35);
    push(sp,46);
    push(sp,57);
    push(sp,68);
    push(sp,79);

    printf("Popped %d from stack\n",pop(sp));
    printf("Popped %d from stack\n",pop(sp));
    printf("Popped %d from stack\n\n",pop(sp));
    printf("Popped %d from stack\n\n",pop(sp));
    printf("Popped %d from stack\n\n",pop(sp));
    printf("Popped %d from stack\n\n",pop(sp));
    printf("Popped %d from stack\n\n",pop(sp));

    for(int j=1;j<=sp->top + 1;j++)
    {
        printf("THe value at index %d is %d\n",j,peek(sp,j));
    }

    printf("\nThe top most value of the stack is %d\n",stacktop(sp));
    printf("The bottom most value of the stack is %d\n",stackbottom(sp));
 
    // int val;
    // int ch;
    // while(1)
    // {
    //     printf("\nEnter the choice: 1.push an element   2.pop   3.display list  4.stack top  5.stack bottom");
    //     scanf("%d",&ch);
    //     switch (ch)
    //     {
    //         case 1:
    //             {
    //                 printf("Enter the value:");
    //                 scanf("%d",&val);
    //                 push(s,val);
    //             }break;

    //         case 2: val = pop(s); 
    //                 printf("The deleted element is %d",val);
    //                 break;

    //         //case 3: display(s); break;

    //         case 4: val = stacktop(s);
    //                 printf("%d\n",val); 
    //                 break;

    //         case 5: val = stackbottom(s);
    //                 printf("%d\n",val);
    //                 break;

    //         default:
    //                 {
    //                     printf("Invalid choice");
    //                     exit(1);
    //                 } break;        
    //     }
    // }

}

