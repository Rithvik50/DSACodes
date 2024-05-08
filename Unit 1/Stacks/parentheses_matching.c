#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define MAX 100


int top = -1;
char stack[MAX];

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

void push(char c)
{
  if(isFull())
  {
    printf("Stack overflow");
    exit(1);
  }
  top++;
  stack[top] = c;
}

char pop()
{
  char c;
  if(isEmpty())
  {
    printf("stack underflow");
    exit(1);
  }
  c = stack[top];
  top--;
  return c;
}

int check_balanced(char *s)
{
  for(int i=0; i<strlen(s); i++)
  {
    if(s[i] == '[' || s[i] == '{' || s[i] == '(')
      push(s[i]);
    
    if(s[i] == ']' || s[i] == '}' || s[i] == ')')
    {
      if(isEmpty())
      {
        printf("Right brackets are more than left\n");
        return 0;
      }
      else
      {
        char temp = pop();
        if(!match_char(temp,s[i]))
        {
          printf("Mismatched brackets\n");
          return 0;
        }
      }
    }  
  }
  if(isEmpty())
  {
    printf("Brackets are balanced\n");
    return 1;
  }
  else
  {
    printf("Brackets are not balanced\n");
    return 0;
  }

}

int main()
{
  char exp[MAX];
  int balanced;
  printf("Enter the expression: ");
  gets(exp);
  balanced = check_balanced(exp);
  if(balanced==1)
    printf("The expression is valid");
  else
    printf("The expression is not valid");
  return 0;
}