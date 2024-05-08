#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define MAX 100

int stack[MAX];
char infix[MAX];
char postfix[MAX];

int top = -1;


int precedence(char sym)
{
  switch(sym)
  {
    case '^': 
        return 3;

    case '/': 
    case '*': 
        return 2;
    
    case '+': 
    case '-': 
        return 2;
    
    default: return 0;
  }
}

void print()
{
  int i=0;
  printf("The postfix equation is: ");
  while(postfix[i])
  {
    printf("%c",postfix[i++]);
  }
  //print("\n");
}

int space(char c)
{
  if(c==' '|| c=='\t')
    return 1;
  else 
    return 0;
}

void push(int c)
{
  if(top == MAX-1)
  {
    printf("stack overflow\n");
    return;
  }
  top++;
  stack[top] = c;
}

char pop()
{
  char c;
  if(top==-1)
  {
    printf("Stack underflow\n");
    exit(1);
  }
  c = stack[top];
  top = top-1;
  return c;
}

int isEmpty()
{
  if(top==-1)
    return 1;
  else 
    return 0;
}

int post_eval()
{
  int a,b;
  for(int i=0;i<strlen(postfix);i++)
  {
    if(postfix[i]>='0' && postfix[i]<='9')
    {
      push(postfix[i]-'0');
    }
    else{
      a = pop();
      b = pop();
      switch(postfix[i])
      {
        case '+':
            push(b+a); break;
        case '-':
            push(b-a); break;
        case '*':
            push(b*a); break;
        case '/':
            push(b/a); break;
        case '^':
            push(pow(b,a)); break;
          
      }
    }
  }
}

void intopost()
{
    int i,j=0;
    char symbol,next;

    for(int i=0;i<strlen(infix);i++)
    {
      symbol = infix[i]; 
      if(!space(symbol))
      {
        switch(symbol)
        {
          case '(':
                  push(symbol);
                  break;
          case ')':
                  while((next=pop())!='(')
                  {
                    postfix[j++] = next;   
                  }
                  break;
          case '+':
          case '-':
          case '*':
          case '/':
          case '^':
                while(!isEmpty() && precedence(stack[top])>= precedence(symbol))
                    postfix[j++] = pop();
                push(symbol); 
                break;
          default: postfix[j++]=symbol;break;
        } 
      }
    }
    while(!isEmpty())
      postfix[j++] = pop();
    postfix[j] = '\0';
}

void reverse (char *exp)
{

  int size = strlen (exp);
  int j = size, i = 0;
  char temp[size];

  temp[j--] = '\0';
  while (exp[i] != '\0')
    {
      temp[j] = exp[i];
      j--;
      i++;
    }
  strcpy (exp, temp);
}

int main()
{
    printf("Enter the infix expression: ");
    gets(infix);
    intopost();
    int result = post_eval();
    print();
    printf("\nThe result obtained is: %d\n",result);
    return 0;
}