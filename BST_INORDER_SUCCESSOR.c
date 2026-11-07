#include <stdio.h>
#include <stdlib.h>

typedef struct tree
{
    struct tree *left ;
    int data ;
    struct tree *right ;
}tt;

void create(tt**, int v );
void in_order(tt*);
void count(tt*, int *);
void inorder_array(tt*,int[], int* );
void inorder_successor(tt*,int, int);
void all_inorder_successor(tt*,int,int);

int main()
{
    tt* root = NULL ;
    int v , ch , c = 0 , i =0 , key;

    do
    {
        printf("\n 1 : create \n 2 : in_order \n 3 : Total_node count \n 4 : inorder successory of a given key \n 5 : all inoder successor of a given key \n ");
        scanf("%d",&ch);


        switch (ch)
        {
            case 1 :
                printf("enter the value you want to insert in the bst : ");
                scanf("%d",&v);
                create(&root,v);
                break ;
            case 2 :
                in_order(root);
                break ;
            case 3 : 
                c = 0 ;
                count(root,&c);
                printf("the total number of nodes in the bst is : %d ", c);
                break ;
            case 4 :
                c = 0 ;
                count(root,&c);
                printf("enter the key of which inorder successor you want : ");
                scanf("%d",&key);
                inorder_successor(root, key , c);
                break ;
            case 5 :
                c = 0 ;
                count(root,&c);
                printf("enter the key of which inorder successors you want : ");
                scanf("%d",&key);
                all_inorder_successor(root,key,c);
                break ;
        }
    }while(ch<=5);

    return 0 ;
}

void create(tt **rt, int v)
{
    tt *p = NULL;
    if(*rt == NULL)
    {
        p = (tt*)malloc(sizeof(tt));
        p->left = NULL ;
        p->right = NULL;
        p->data = v ;

        (*rt) = p ;
    }
    else if ((*rt)->data > v)
    {
        create(&((*rt)->left), v);
    }
    else if ((*rt)->data < v)
    {
        create(&((*rt)->right),v);
    }
    else
    {
        printf("duplicated key");
    }
}

void in_order(tt *rt)
{
    if(rt==NULL)
    {
        return ;
    }
    else
    {
        in_order(rt->left);
        printf("%d\t",rt->data);
        in_order(rt->right);
    }
}

void count(tt*rt,int *con)
{
    if(rt==NULL)
    {
        return ;
    }
    else
    {
        count(rt->left,con);
        (*con)++;
        count(rt->right,con);
    }
}


void inorder_array(tt*rt,int a[] , int *i )
{
    
    if(rt==NULL)
    {
        return ;
    }
    else
    {
        
        inorder_array(rt->left, a, i);
        a[(*i)++] = rt->data;
        inorder_array(rt->right,a,i);
    }
}

void inorder_successor(tt*rt,int k, int c)
{
    int a[c]  , i = 0 , flag = 0 ;

    inorder_array(rt,a, &i );

    i = 0 ;
    for(i=0;i<c;i++)
    {
        if(a[i]==k)
        {
            flag = 1 ;
            break ;
        }
    }

    if(flag ==1 )
    {
        if(i==c-1)
        {
            printf("no in order successor as it is the last element ");
        }
        else
        {
            printf("the inoder successor of the %d is : %d", k , a[++i]);
        }
    }
    else
    {
        printf("the key is not present in the bst ");
    }
    
}

void all_inorder_successor(tt*rt,int key,int c)
{
    int i = 0 , a[c], flag = 0 , j;

    inorder_array(rt,a,&i);

    for(i=0;i<c;i++)
    {
        if(a[i]==key)
        {
            flag =1 ;
            break ;
        }
    }

    if(flag ==1 )
    {
        if(i==c-1)
        {
            printf("no in order successor as it is the last element ");
        }
        else
        {
            printf("the inorder successor of the key are ");
            for(j = i+1 ; j < c ; j++)
            {
                printf("%d\t",a[j]);
            }
        }
    }
    else
    {
        printf("the key not found in the bst ");
    }


}