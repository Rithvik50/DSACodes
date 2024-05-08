// #include<stdio.h>
// #include<stdlib.h>

// int main()
// {
//     int *k;
//     k = malloc(sizeof(int));

//     if(k!=NULL)
//     {
//         printf("Memory is being allocated");
//     }

//     else
//     {
//         printf("Memory not allocated");
//     }
// }

// #include<stdio.h>
// #include<stdlib.h>
// #include<malloc.h> //used for _msize

// int main()
// {
//     int *k = (int *)malloc(4*sizeof(int));
//     printf("%d\n",_msize(k));
//     int *m = (int *)calloc(5,sizeof(int));
//     printf("%d\n",_msize(m));
//     free(m);
//     printf("%d\n",_msize(m));
//     m = NULL;
//     k = (int*)realloc(k,30);
//     printf("%d\n",_msize(k));
//     free(k);
//     printf("%d\n",_msize(k));
//     k = NULL;

// }

//Write a program to store PES student details and display using structures
// name,branch,semester,marks in isa1, marks in isa2

// #include<stdio.h>

// struct student
// {
//     char name[100];
//     char branch[100];
//     int sem;
//     int m1;
//     int m2;
    
// };

// int main()
// {
//     struct student s1;
//     printf("Enter the name:");
//     scanf("%s",&s1.name);
//     fflush(stdin);
//     printf("Enter the branch:");
//     gets(s1.branch);
//     fflush(stdin);
//     printf("Enter the semester:");
//     scanf("%d",&s1.sem);
//     printf("Enter the marks of ISA 1:");
//     scanf("%d",&s1.m1);
//     printf("Enter the marks of ISA 2:");
//     scanf("%d",&s1.m2);
//     printf("\nName:%s\n",s1.name);
//     printf("Branch:%s\n",s1.branch);
//     printf("Semester:%d\n",s1.sem);
//     printf("Marks of ISA 1:%d\n",s1.m1);
//     printf("Marks of ISA 2:%d\n",s1.m2);


// }


//Write a recursive function for fibbonacci sequence

#include<stdio.h>

int fib(int a,int b,int n)
{
    if(n>0)
    {
        printf("%d ",b);
        return fib(b,a+b,n-1);

    }
}

int main()
{
    int n;
    printf("Enter the number of elements");
    scanf("%d",&n);
    fib(0,1,n);    
}

