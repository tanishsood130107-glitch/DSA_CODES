#include <stdio.h>
#include <stdlib.h>

typedef struct tree
{
    struct tree *left;
    int data ;
    struct tree *right ;
}tt;

void count(tt*,int*);
void create(tt**, int );


int main()
{
    tt *root = NULL ;
    int c = 0 , ch, v  ;

    do
    {
        printf("\n 1 : insert node \n 2 : count_number of nodes \n : ");
        scanf("%d",&ch);

        switch (ch)
        {
            case 1 : 
                printf("enter the value you want to insert in the bst : ");
                scanf("%d",&v);
                create(&root,v);
                break ;
            case 2 : 
                count(root,&c);
                printf("the number of nodes in the bst are : %d ", c);
                break ;

        }
    }while(ch<=2);

    return 0 ;
}


void create(tt **rt, int v)
{
    tt *p = NULL ;

    if(*rt==NULL)
    {
        p = (tt*)malloc(sizeof(tt));
        p->left = NULL ;
        p->right = NULL;
        p->data = v ;
        *rt = p ;

        return ;
    }
    else if((*rt)->data > v)
    {
        create(&((*rt)->left),v);
    }
    else
    {
        create(&((*rt)->right),v);
    }
}

void count(tt *rt , int *con )
{
    if(rt == NULL)
    {
        return ;
    }
    else
    {
        (*con)++;  
        count(rt->left,con);
        count(rt->right,con);

    }
}