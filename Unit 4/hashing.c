#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<stdint.h>

#define MAX_NAME 256
#define TABLE_SIZE 10 

typedef struct{
    char name[MAX_NAME];
    int age;
}person;

person * hash_table[TABLE_SIZE];

unsigned int hash(char *name)
{
    int length = strnlen(name, MAX_NAME);
    unsigned int hash_value = 0;
    for(int i=0; i<length; i++)
    {
       hash_value += name[i];
       hash_value = (hash_value * name[i]) % TABLE_SIZE;
    }

    return hash_value;
}

bool init_hash_table(){
    for(int i=0; i<TABLE_SIZE; i++)
    {
        hash_table[i] = NULL;
    }
}

void print_table()
{
    
    printf("Start\n");
    for(int i=0;i<TABLE_SIZE; i++)
    {
        if(hash_table[i]==NULL)
            printf("\t%i\t---\n",i);
        else
          printf("\t%i\t%s\n",i, hash_table[i]->name);  
    }
    printf("End\n");
}

bool hash_table_insert(person* p)
{
    if(p==NULL)
        return false;
    
    int index = hash(p->name);

    for(int i=0;i<TABLE_SIZE; i++)
    {
        int try = (i+index)%TABLE_SIZE;
        if(hash_table[try]==NULL)
        {
            hash_table[try] = p;
            return true;
        }
    }
    return false;

    // if(hash_table[index]!=NULL)
    //     return false;
    
    // hash_table[index] = p;
    // return true;    
}

person *hash_table_lookup(char *name)
{
    int index = hash(name);
    if(hash_table[index]!=NULL && strncmp(hash_table[index]->name, name, TABLE_SIZE)==0)
    {
        return hash_table[index];
    }

    else
        return NULL;
}

person *hash_table_delete(char *name)
{
    int index = hash(name);
    if(hash_table[index]!=NULL && strncmp(hash_table[index]->name, name, TABLE_SIZE)==0)
    {
        person* tmp = hash_table[index];
        hash_table[index] = NULL;
        return tmp;
    }

    else
        return NULL;
}

int main()
{
   init_hash_table();
   //print_table(); 

   person jacob = {.name="Jacob", .age=25};
   person kate = {.name="Kate", .age=27};
   person mpho = {.name="Mpho", .age=14};
   person sarah = {.name="Sarah", .age=54};
   person edna = {.name="Edna", .age=15};
   person maren = {.name="Maren", .age=25};
   person eliza = {.name="Eliza", .age=34};
   person robert = {.name="Robert", .age=1};
   person jane = {.name="Jane", .age=75};

   hash_table_insert(&jacob);
   hash_table_insert(&kate);
   hash_table_insert(&mpho);
   hash_table_insert(&sarah);
   hash_table_insert(&edna);
   hash_table_insert(&maren);
   hash_table_insert(&eliza);
   hash_table_insert(&robert);
   hash_table_insert(&jane);
   print_table();

    hash_table_delete("Kate");
   person *tmp = hash_table_lookup("Kate");

   if(tmp==NULL)
        printf("Not found!\n");
    
    else
        printf("Found %s \n", tmp->name);

    print_table();






}