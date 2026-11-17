#include <stdio.h>
#include <stdlib.h>

typedef struct tree
{
    struct tree *left;
    int data ;
    struct tree *right;
}tt;

void insert(tt**,int);
void pre_order(tt*);
void search(tt*,int,int*);

int main()
{
    tt *root = NULL ;
    int ch , value , key, find;

    do
    {
        printf("\n 1 : insert \n 2 : pre_order \n 3 : search ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1 : 
                printf("enter the data you want to insert : ");
                scanf("%d",&value);
                insert(&root,value);
                break ;
            case 2 :
                pre_order(root);
                break;
            case 3 :
                find = 0 ;
                printf("enter the value you want to search : ");
                scanf("%d",&key);

                search(root,key,&find);

                if(find == 1 )
                {
                    printf("yes the key is present is the bst");
                }
                else
                {
                    printf("the key is not present in the bst");

                }
                break ;

        }

    } while (ch<=3);

    return 0 ;
    
}

void insert(tt **rt,int val)
{
    tt *p = NULL;

    if(*rt == NULL)
    {
        p = (tt*)malloc(sizeof(tt));
        p->data = val;
        p->left = NULL ;
        p->right = NULL;

        *rt = p;
        return ;
    }
    else if((*rt)->data > val)
    {
        insert(&((*rt)->left),val);
    }
    else if((*rt)->data < val)
    {
        insert(&((*rt)->right),val);
    }
    else
    {
        printf("duplicate node ");
        
    }
}

void pre_order(tt *rt)
{
    if(rt == NULL)
    {
        return;
    }
    else
    {
        printf("%d \t",rt->data);
        pre_order(rt->left);
        pre_order(rt->right);
    }
}

void search(tt*rt,int key,int *f)
{
    int find = 0 ;
    tt *temp = NULL ;

    if(rt == NULL)
    {
        return ;
    }
    else
    {
        if(rt->data == key)
        {
            *f = 1 ;
           
        }
        search(rt->left,key,f);
        search(rt->right,key,f);
    }
}

// optimisted search


// void search(tt *rt, int key, int *f)
// {
//     if(rt == NULL)
//     {
//         return;
//     }
//     else if(rt->data == key)
//     {
//         *f = 1;
//         return;
//     }
//     else if(key < rt->data)
//     {
//         search(rt->left, key, f);
//     }
//     else
//     {
//         search(rt->right, key, f);
//     }
// }
