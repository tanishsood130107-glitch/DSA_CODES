#include <stdio.h>
#include <stdlib.h>

typedef struct tree
{
    struct tree *left;
    int data ;
    struct tree *right ;
}tt ;

void create(tt**, int v);
void pre_order(tt*);


void count(tt*,int*);

int main()
{
    tt *root =  NULL;
    int ch , v , c = 0 ;

    do
    {
        printf("\n 1 : create \n 2 : pre_order \n 3 : count nodes right side \n 4 : count nodes left side \n : ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1 :
                printf("enter the data you want to insert in the bst : ");
                scanf("%d",&v);
                create(&root,v);
                break ;
            case 2 : 
                pre_order(root);
                break ;
            case 3 : 
                c = 0 ;
                if(root->right !=NULL)
                {
                    count(root->right,&c);
                }
                printf("the number of nodes which are on the right hand side are : %d",c);
                break ;
            case 4 : 
                c = 0 ;
                if(root->left !=NULL)
                {
                    count(root->left , &c);
                }
                printf("the number of nodes which are on the right hand side are : %d",c);
                break ;

        }

    }while(ch<=4);

    return 0 ;
}



void count(tt* rt , int *con)
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

void pre_order(tt*rt)
{
    if(rt==NULL)
    {
        return ;
    }
    else
    {
        printf("%d\t",rt->data);
        pre_order(rt->left);
        pre_order(rt->right);
    }
}

void create(tt**rt, int v)
{
    tt *p = NULL;

    if(*rt ==NULL)
    {
        p = (tt*)malloc(sizeof(tt));
        p->left = NULL ;
        p->right = NULL ;
        p->data = v ;
        (*rt) = p ;
    }
    else if((*rt)->data > v)
    {
        create(&((*rt)->left),v); 
    }
    else if (((*rt)->data<v))
    {
        create(&((*rt)->right),v);
    }
    else
    {
        printf("duplicate key ");
    }
}