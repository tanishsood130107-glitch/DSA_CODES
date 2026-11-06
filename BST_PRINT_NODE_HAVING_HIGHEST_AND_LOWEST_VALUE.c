#include <stdio.h>
#include <stdlib.h>

typedef struct tree
{
    struct tree *left ;
    int data ;
    struct tree *right ;
}tt ;

void create(tt**, int );
void pre_order(tt* );
void highest(tt*, int *high);
void lowest(tt*, int *low);

int main()
{
    tt *root = NULL ;
    int ch , v , h = 0 , l = 0 ;

    do
    {
        printf("\n 1 : create \n 2 : pre_order \n 3 : highest \n 4 : lowest \n ");
        scanf("%d",&ch);


        switch (ch)
        {
            case 1 : 
                printf("enter the value you want to insert in the bst : ");
                scanf("%d",&v);
                create(&root, v);
                break ;
            case 2 :
                pre_order(root); 
                break ;
            case 3 :
                highest(root, &h);
                break ;
            case 4 :
                lowest(root,&l);
                break ; 
                
        }
    }while(ch<=4);

    return 0 ; 
    
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


void create(tt **rt , int v)
{
    tt *p = NULL ;

    if(*rt == NULL)
    {
        p = (tt*)malloc(sizeof(tt));
        p->left = NULL ;
        p->right = NULL ;
        p->data = v ;

        *rt = p ;
        return ;
    }
    else if( (*rt)->data > v)
    {
        create(&((*rt)->left), v);
    }
    else if ((*rt)->data < v)
    {
        create(&((*rt)->right),v);
    }
    else
    {
        printf("repeated key : ");
    }
}




void highest(tt *rt, int *high)
{
    if(rt == NULL)
    {
        printf("the highest value of the bst is : %d ", *high);
        return ;
    }
    else
    {
        *high = rt->data;
        highest(rt->right, high);
    }
}


void lowest(tt *rt , int *low)
{
    if(rt == NULL)
    {
        printf("the lowest value of the bst is : %d ",*low);
        return ;
    }
    else
    {
        *low = rt->data;
        lowest(rt->left , low);
    }
}