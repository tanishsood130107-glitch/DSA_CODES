#include <stdio.h>
#include <stdlib.h>

typedef struct tree 
{
    struct tree *left ;
    int data ;
    struct tree *right ;
}tt;

void create(tt** , int);
void count_smaller_key(tt*, int*, int);
void count_larger_key(tt*, int*, int);
void pre_order(tt*);

int main()
{
    tt *root = NULL ;
    int v , ch , key , c = 0 ;
    
    do
    {
        printf("\n 1 : create \n 2 : pre_order \n 3 : count number smaller than the key \n 4  : count number layer than the key\n : ");
        scanf("%d",&ch);

        switch (ch)
        {
            case 1 : 
                printf("enter the value you want to insert int the bst : ");
                scanf("%d",&v);
                create(&root, v);
                break ;
            case 2 :
                pre_order(root);
                break ;
            case 3 :
                c = 0 ;
                printf("enter the key :  ");
                scanf("%d",&key);
                count_smaller_key(root , &c , key );
                printf("the number of nodes having value less than the key is : %d",c);
                break ;
            case 4 : 
                c = 0 ;
                printf("enter the key : ");
                scanf("%d",&key);
                count_larger_key(root,&c,key);
                printf("enter the number of node greater than the key : %d",c);
                break ;
        }

    }while(ch<=4);

    return 0 ; 
}

void pre_order(tt* rt )
{
    if(rt == NULL)
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

void create(tt**rt , int v )
{
    tt *p ;

    if(*rt == NULL)
    {
        p = (tt*)malloc(sizeof(tt));

        p->left = NULL ;
        p->right = NULL ;
        p->data = v ;
        (*rt) = p ;
    }
    else if ((*rt)->data > v)
    {
        create(&((*rt)->left),v);
    }
    else if((*rt)->data < v)
    {
        create(&((*rt)->right),v);
    }
    else
    {
        printf("there is duplicate key ");
    }
}

void count_smaller_key(tt*rt , int *con, int key )
{
    if(rt == NULL)
    {
        return ;
    }
    else
    {
        if(rt->data==key)
        {
            count_smaller_key(rt->left , con , key);
        }
        else if (rt->data < key)
        {
            (*con)++;
            count_smaller_key(rt->left, con, key);
            count_smaller_key(rt->right, con , key);
        }
        else if(rt->data>key)
        {
            count_smaller_key(rt->left , con , key);
        }

    }
}

void count_larger_key(tt *rt , int *con , int key)
{
    if(rt == NULL)
    {
        return ;
    }
    else
    {
        if(rt->data == key)
        {
            count_larger_key(rt->right, con , key);  
        }
        else if(rt->data >key)
        {
            (*con)++;
            count_larger_key(rt->left,con , key);
            count_larger_key(rt->right,con,key);
        }
        else if (rt->data < key)
        {
            count_larger_key(rt->right,con, key);
        }
    }
}