#include <stdio.h>
#include <stdlib.h>

typedef struct Tree_type
{
    struct Tree_type *left ;
    int data ;
    struct Tree_type *right ;
}tt ;

void create(tt**,int );
void preorder(tt *);
void postorder(tt *);
void inorder(tt *);
 
int main()
{
    tt *root = NULL ;
    int ch , v ;


    do
    {
        printf("\n enter the choice \n 1 : insert \n 2 : display preorder \n 3 : display inorder \n 4 : display preorder ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1 :
                printf("enter the value you want to insert : ");
                scanf("%d",&v);
                create(&root,v);
                break ;
            case 2 : 
                preorder(root);
                break ;
            case 3 : 
                inorder(root);
                break ;
            case 4 :
                postorder(root);
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
        (p)->left = NULL;
        (p)->right = NULL ;
        (p)->data = v ; 
        (*rt) = p ;
        return ;

    }
    else if((*rt)->data > v)
    {
        create(&((*rt)->left),v);
    }
    else if((*rt)->data < v)
    {
        create(&((*rt)->right), v);
    }
    else
    {
        printf("duplicate key ");
        return ;
    }
}

void preorder(tt *rt)
{
    if(rt == NULL)
    {
        return ;
    }
    else
    {
        printf("%d \t", rt->data);
        preorder(rt->left);
        preorder(rt->right);
    }
}

void postorder(tt *rt)
{
    if(rt == NULL)
    {
        return ;
    }
    else
    {
        postorder(rt->left);
        postorder(rt->right);
        printf("%d \t",rt->data);
    }
}

void inorder(tt *rt)
{
    if(rt ==NULL)
    {
        return ;
    }
    else
    {
        inorder(rt->left);
        printf("%d \t",rt->data);
        inorder(rt->right);
    }
}



