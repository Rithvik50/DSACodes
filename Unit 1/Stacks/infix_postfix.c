#include<stdio.h>
#include<string.h>

char opr[25];
char out[25];
int topopr = -1;
int topout = -1;
char ch;


void pushopr(char ele)
{
  if(topopr==24)
    printf("\n The stack is full");
  else
  {
    topopr++;
    opr[topopr] = ele;
  }
}

char popopr()
{
  if(topopr!=-1)
  {
    ch = opr[topopr];
    topopr--;
  }
  return ch;
}

char peepopr()
{
  if(topopr!=-1)
    ch = opr[topopr];
  return ch;
}

void displayopr()
{
  printf("\n Operator stack: ");
  for(int i=0;i<=topopr;i++)
  {
    printf(" | %c ",opr[i]);
  }
}

void pushout(char ele)
{
  if(topout==24)
    printf("\n The stack is full");
  else
  {
    topout++;
    out[topout] = ele;
  }
}

void displayout()
{
  printf("\n Output stack: ");
  for(int i=0;i<=topout;i++)
  {
    printf(" | %c ",out[i]);
  }
}

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
        return 1;
  }
  return -1;
}

void main()
{
  char infix[25], ele, p;
  int i=0;
  printf("Enter the infix expression: ");
  gets(infix);
  while(infix[i]!='\0')
  {
    ele = infix[i];
    if(ele == '(')
      pushopr(ele);

    else if(ele==')')
    {
      while(peepopr()!='(')
      {
        p = popopr();
        pushout(p);
      }
      popopr();
    }

    else if(ele== '^' || ele== '*' || ele== '/' || ele== '+' || ele== '-')
    {
      if(topopr>=0)
      {
        while(precedence(peepopr())>precedence(ele))
        {
          p = popopr();
          pushout(p);
        }
      }
      pushopr(ele);
    }
    
    else
      pushout(ele);

    displayopr();
    displayout();
    i++;
  }

  if(topopr!=-1)
  {
    while(topopr!=-1)
    {
      p = popopr();
      pushout(p);
    }
  }
  printf("\n Postfix expresion is %s ",out);
}
