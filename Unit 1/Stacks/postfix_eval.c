#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#define MAX 100


int top = -1;
int stack[MAX];

int match_char(char a, char b)
{
  if(a == '[' && b== ']')
    return 1;

  if(a == '{' && b== '}')
    return 1;

  if(a == '(' && b== ')')
    return 1;

  return 0;
}

int isEmpty()
{
  if(top == -1)
    return 1;
  else
    return 0;
}

int isFull()
{
  if(top==MAX-1)
    return 1;
  else  
    return 0;
}

void push(int c)
{
  if(isFull())
  {
    printf("Stack overflow");
    exit(1);
  }
  top++;
  stack[top] = c;
}

int pop()
{
  int c;
  if(isEmpty())
  {
    printf("stack underflow");
    exit(1);
  }
  c = stack[top];
  top--;
  return c;
}

void display()
{   
    printf("\n Stack: ");
    for(int i=0;i<=top;i++)
    {
        printf(" | %d ",stack[i]);
    }

}

int main()
{   
    char postfix[MAX] = {'\0'};
    char ele;
    int num1,num2,ans;
    printf("Enter the postfix expression: ");
    gets(postfix);

    int i=0;
    while(i<=strlen(postfix)-1)
    {
        ele = postfix[i];
        if(isdigit(ele))
        {
            push(ele-'0');
        }

        else
        {
            num1 = pop();
            num2 = pop();
            switch(ele)
            {
               case '^':
                    ans = pow(num2,num1);
                    break;
                case '/':
                    ans = num2/num1;
                    break;

                case '*':
                    ans = num2*num1;
                    break;

                case '+':
                    ans = num2+num1;
                    break;

                case '-':
                    ans = num2-num1;
                    break;
            }
            push(ans);
        }
        display();
        i++;
    }
    printf("\nThe ans is %d",pop());
}