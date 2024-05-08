#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
#define NUM_CHAR 256

typedef struct trienode{
    struct trienode* children[NUM_CHAR];
    bool terminal;

}trienode;

trienode* createnode()
{
    trienode* new = (trienode*)malloc(sizeof *new);

    for(int i=0;i<NUM_CHAR;i++)
    {
       new->children[i] =NULL; 
    }
    new->terminal = false;
    return new;
}

bool trieinsert(trienode **root, char *signedtext)
{
    if(*root == NULL)
    {
        *root=createnode();
    }

    unsigned char* text = (unsigned char*)signedtext;
    trienode *temp = *root;

    int length = strlen(signedtext);
    for(int i=0;i<length;i++)
    {
        if(temp->children[text[i]]==NULL)
        {
            temp->children[text[i]] = createnode();
        }
        temp = temp->children[text[i]];
    }

    if(temp->terminal)
    {
        return false;
    }

    else
    {
        temp->terminal = true;
        return true;
    }
}

void printtrie_rec(trienode *node, unsigned char *prefix, int len)
{
    unsigned char newprefix[len+2];
    memcpy(newprefix, prefix, len);
    newprefix[len+1] =0;

    if(node->terminal)
    {
        printf("word: %s\n",prefix);
    }

    for(int i=0;i<NUM_CHAR;i++)
    {
        if(node->children[i]!=NULL)
        {
            newprefix[len] = i;
            printtrie_rec(node->children[i], newprefix, len+1);
        }
    }

}

void printtrie(trienode* root)
{
    if(root==NULL)
    {
        printf("The trie is empty\n");
        return;
    }

    printtrie_rec(root,NULL,0);
    
}

bool searchtrie(trienode *root, char* signedtext)
{
    unsigned char *text = (unsigned char *)signedtext;
    int len = strlen(signedtext);
    trienode *temp = root;

    for(int i=0; i<len;i++)
    {
        if(temp->children[text[i]] ==NULL)
        {
            return false;
        } 
        
        temp = temp->children[text[i]];
    }
    return temp->terminal;
}

bool node_has_children(trienode* node)
{
    if(node==NULL)
        return false;
    
    for(int i=0; i<NUM_CHAR; i++)
    {
        if(node->children[i]!=NULL)
        {
            return true;
        }
    }

    return false;
}


trienode* deletestr_rec(trienode* node, unsigned char* text, bool *deleted)
{
    if(node==NULL)
        return node;

    if(*text == '\0')
    {
        if(node->terminal)
        {
            node->terminal = false;
            *deleted = true;

            if(node_has_children(node) == false)
            {
                free(node);
                node=NULL;
            }
        }
        return node;
    }

    node->children[text[0]] = deletestr_rec(node->children[text[0]], text+1, deleted);
    
    if(*deleted && node_has_children(node)==false && node->terminal == false)
    {
        free(node);
        node = NULL;
    }
    
    return node;
}

bool deletstr(trienode** root, char* signedtext)
{
    unsigned char *text = (unsigned char *)signedtext;
    bool result = false;

    if(*root == NULL)
        return false;

    *root = deletestr_rec(*root, text, &result);
    return result;
}

int main()
{
    trienode* root = NULL;
    trieinsert(&root, "KIT");
    trieinsert(&root, "CATTLE");
    trieinsert(&root, "KIN");
    trieinsert(&root, "CAT");
    trieinsert(&root, "HAPPY");
    printtrie(root);

    printf("search for CATTLE: %d\n", searchtrie(root, "CATTLE"));
    printf("search for CAT: %d\n", searchtrie(root, "CAT"));
    printf("search for KITTEN: %d\n", searchtrie(root, "KITTEN"));

    deletstr(&root, "KIN");
    deletstr(&root, "CAT");

    printtrie(root);

}