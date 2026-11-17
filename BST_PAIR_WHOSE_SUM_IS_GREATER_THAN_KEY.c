#include <stdio.h>
#include <stdlib.h>

typedef struct tree 
{
    struct tree *left;
    int data ;
    struct tree *right;
}tt;

void create(tt**,int);
void pre_order(tt*);
void pre_array(tt*,int[],int*);
void pair(tt*,int , int);
void count(tt*, int*);

int main()
{
    tt *root = NULL ;
    int ch ,c =0 , v , key   ;

    do
    {
        printf("\n 1 : create a bst \n 2 : pre_order display \n 3 : count \n 4 : pair \n : ");
        scanf("%d",&ch);

        switch (ch)
        {
            case 1 :
                printf("enter the value you want to insert in bst : ");
                scanf("%d",&v);
                create(&root,v);
                break;
            case 2 :
                pre_order(root);
                break ;
            case 3 :    
                c = 0 ;
                count(root,&c);
                printf("the number of nodes in the bst are : %d",c);
                break ;
            case 4 :
                c = 0 ;
                count(root,&c);
                printf("enter the key : ");
                scanf("%d",&key);
                pair(root,key,c);
                break ;


        }
    }while(ch<=4);

    return 0 ;
}

void create(tt **rt , int v)
{
    tt *p = NULL ;

    if(*rt == NULL)
    {
        p = (tt*)malloc(sizeof(tt));
        p->right = NULL ;
        p->left = NULL ;
        p->data = v ;

        (*rt) = p ;
    }
    else if((*rt)->data > v)
    {
        create(&((*rt)->left),v);
    }
    else if((*rt)->data < v)
    {
        create(&((*rt)->right),v);
    }
    else
    {
        printf("duplicate key ");
    }
}

void pre_array(tt *rt , int a[], int *ind)
{
    if(rt==NULL)
    {
        return ;
    }
    else
    {
        a[(*ind)++] = rt->data;
        pre_array(rt->left,a,ind);
        pre_array(rt->right,a,ind);
    }
}

void pair(tt *rt , int key, int c)
{
    int i , j , a[c], ind = 0 ;

    pre_array(rt,a,&ind);

    for(i=0;i<c-1;i++)
    {
        for(j=i+1;j<c;j++)
        {
            if(a[i]+a[j]>=key)
            {
                printf("(%d,%d)\n",a[i],a[j]);
            }
        }
    }
}

void count(tt*rt, int*con)
{
    if(rt==NULL)
    {
        return ;
    }
    else
    {
        (*con)++;
        count(rt->left,con);
        count(rt->right, con);
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