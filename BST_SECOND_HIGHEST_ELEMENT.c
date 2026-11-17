#include <stdio.h>
#include <stdlib.h>

typedef struct tree
{
    struct tree *left;
    int data ;
    struct tree *right ;
}tt;

void insert(tt**,int );
void pre_order(tt*);
void count(tt*,int*);
void second_highest(tt*);

int main()
{
    int ch , val ,c;
    tt *root = NULL ;


    do
    {
        printf("\n 1 : insert \n 2 : pre order \n 3 : count \n 4 : second_highest\n ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1 :
                printf("enter the value you want to insert : ");
                scanf("%d",&val);
                insert(&root,val);
                break;
            case 2 :
                pre_order(root);
                break;
            case 3 :
                c = 0 ;
                count(root,&c);
                printf("the number of nodes are %d ",c);
                break;
            case 4 :
                second_highest(root);
                break;
        }
    }while(ch<=4);

    return 0 ;
}


void insert(tt **rt, int v)
{
    tt *p = NULL;
    if(*rt == NULL)
    {
        p = (tt*)malloc(sizeof(tt));
        p->data =v;
        p->left = NULL;
        p->right = NULL;

        (*rt) = p ;
    }
    else if((*rt)->data > v)
    {
        insert(&((*rt)->left),v);
    }
    else if((*rt)->data<v)
    {
        insert(&((*rt)->right),v);
    }
    else
    {
        printf("duplicated key");
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
        
        pre_order(rt->left);
        printf("%d",rt->data);
        pre_order(rt->right);
    }

}

void count(tt*rt,int*c)
{
    if(rt==NULL)
    {
        return ;
    }
    else
    {
        *c = *c +1;
        count(rt->left,c);
        count(rt->right,c);
    }
}


// void second_highest(tt *rt)
// {
//     if(rt == NULL || (rt->left == NULL && rt->right == NULL))
//     {
//         printf("Second highest does not exist");
//         return;
//     }

//     if(rt->right == NULL)
//     {
//         if(rt->left != NULL)
//         {
//             tt *temp = rt->left;

//             while(temp->right != NULL)
//             {
//                 temp = temp->right;
//             }

//             printf("Second highest element is: %d", temp->data);
//         }
//         else
//         {
//             printf("Second highest element is: %d", rt->data);
//         }

//         return;
//     }

//     if(rt->right->right == NULL && rt->right->left == NULL)
//     {
//         printf("Second highest element is: %d", rt->data);
//         return;
//     }

//     second_highest(rt->right);
// }


void second_highest(tt*rt)
{
    if(rt==NULL || (rt->right ==NULL && rt->left == NULL))
    {
        printf("no second highest node");
        return ;
    }

    if(rt->right==NULL)
    {
        if(rt->left!=NULL)
        {
            tt *temp = rt->left;

            while(temp->right!=NULL)
            {
                temp = temp->right;
            }

            printf("The second highest node is : %d ",temp->data);
        }
        
        return ;
    }

    if(rt->right->right == NULL && rt->right->left == NULL)
    {
        printf("the second highest node is %d ",rt->data);
    }

    second_highest(rt->right);
}