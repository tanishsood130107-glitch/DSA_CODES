#include <stdio.h>
#include <stdlib.h>


typedef struct tree
{
    struct tree *left ;
    int data ;
    struct tree *right ; 
}tt;

void create(tt**,int);
void pre_order(tt*);
void count(tt*, int*);
void leaf_count(tt*, int*);
void node_with_both_par(tt* , int*);
void left_node_only(tt*, int*);
void right_node_only(tt*,int*);



int main()
{
    tt *root = NULL ;
    int c = 0 , v , ch ;

    do
    {
        printf("\n 1 : create \n 2 : TOTAL NODES \n 3 : LEAF NODES \n 4 : NON LEAF NODES \n 5 : preorder display \n 6 : right child only \n 7 : left child only \n ");
        scanf("%d",&ch);

        switch (ch)
        {
            case 1 : 
                printf("enter the value you want to insert in the bst : ");
                scanf("%d",&v);
                create(&root,v);
                break ;
            case 2 :
                c = 0 ;
                count(root,&c);
                printf("the total number of  nodes are : %d",c);
                break ;
            case 3 : 
                c = 0 ;
                leaf_count(root,&c);
                printf("the total number of leaf nodes are : %d", c);
                break ; 
            case 4 : 
                c = 0 ; 
                node_with_both_par (root,&c);
                printf("the total number of nodes with both parents are : %d",c);
                break ;
            case 5 :
                pre_order(root);
                break ;
            case 6 :
                c = 0;
                right_node_only(root,&c);
                printf("the number of node having right child only are : %d ", c);
                break ;
            case 7 : 
                c = 0 ;
                left_node_only(root,&c);
                printf("the number of nodes having left child only are : %d ", c);
                break ;

        }


    }while(ch<=7);

    return 0 ;
}


void create(tt **rt , int v )
{
    tt *p = NULL ;

    if(*rt ==NULL)
    {
        p = (tt*)malloc(sizeof(tt));

        p->left = NULL;
        p->right = NULL;
        p->data = v;
        *rt = p ;
    }
    else if((*rt)->data > v)
    {
        create(&((*rt)->left),v);
    }
    else if ((*rt)->data<v)
    {
        create(&((*rt)->right), v);
    }
    else
    {
        printf("duplicate key enter another key :");
    }

}

void count(tt *rt , int *con)
{
    if(rt==NULL)
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

void leaf_count(tt *rt , int *con)
{
    if(rt==NULL)
    {
        return ;
    }
    else
    {
        if((rt->left == NULL)&&(rt->right==NULL))
        {
            (*con)++;
        }
        leaf_count(rt->left,con);
        leaf_count(rt->right,con);
    }
}

void node_with_both_par(tt* rt , int* con)
{
    if(rt==NULL)
    {
        return ;
    }
    else
    {
        if((rt->left!=NULL)&& (rt->right!=NULL))
        {
            (*con)++;    
        }
        node_with_both_par(rt->left,con);
        node_with_both_par(rt->right,con);
    }
}

void pre_order(tt *rt)
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


void left_node_only(tt *rt , int *con)
{
    if(rt==NULL)
    {
        return ;
    }
    else
    {
        if(rt->left!=NULL && rt->right == NULL)
        {
            (*con)++;
        }
        left_node_only(rt->left,con);
        left_node_only(rt->right,con);
    }
}

void right_node_only(tt *rt , int *con)
{
    if(rt ==NULL)
    {
        return ;
    }
    else
    {
        if(rt->left ==NULL && rt->right!=NULL)
        {
            (*con)++;
        }
        right_node_only(rt->left,con);
        right_node_only(rt->right,con);
    }
}