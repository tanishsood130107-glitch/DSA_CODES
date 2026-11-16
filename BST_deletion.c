#include <stdio.h>
#include <stdlib.h>

typedef struct tree
{
    struct tree *left;
    int data ;
    struct tree *right;
}tt;

void inorder(tt*);
void insert_node(tt**,int);
void count(tt*,int*);
void del_node(tt **, int );
int is_pres(tt *, int);

int main()
{
    tt *root = NULL;
    int ch , val , c = 0;

    do
    {
        printf("\n 1 : insert node in the bst \n 2 : inorder \n 3 : count \n 4 : delete element from the bst \n :");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1 :
                printf("enter the element you want to insert in the bset : ");
                scanf("%d",&val);
                insert_node(&root,val);
                break;
            case 2 :
                inorder(root);
                break;
            case 3:
                c =0 ;
                count(root,&c);
                printf("the number of roots in the bst is %d ", c);
                break ;
            case 4 :
                printf("enter the element you want to delete : ");
                scanf("%d",&val);
                del_node(&root,val);
                break ;
        }
    }while(ch<=4);

    return 0 ;
    
}


void inorder(tt *root)
{
    if(root == NULL)
    {
        return ;
    }
    else
    {
        inorder(root->left);
        printf("%d\t",root->data);
        inorder(root->right);
    }
}

void insert_node(tt **rt , int val)
{
    tt *temp = NULL;

    if(*rt == NULL)
    {
        temp = (tt*)malloc(sizeof(tt));
        temp->data = val;
        temp->left = NULL;
        temp->right = NULL ;

        *rt = temp ;

    }
    else if((*rt)->data > val)
    {
        insert_node(&((*rt)->left),val);
    }
    else if((*rt)->data < val)
    {
        insert_node(&((*rt)->right),val);
    }
    else
    {
        printf("duplicated key");
    }
}

void count(tt *root , int *con)
{
    if(root == NULL)
    {
        return ;
    }
    else
    {
        (*con)++;
        count(root->left,con);
        count(root->right,con);
    }
}
tt* findMin(tt *root)
{
    while(root->left != NULL)
    {
        root = root->left;
    }

    return root;
}

void del_node(tt **rt , int key)
{

    tt *temp = NULL;

    if(*rt == NULL)
    {
        return ;
    }
    else
    {
        if(key > (*rt)->data)
        {
            del_node(&(*rt)->right,key);
        }
        else if(key< (*rt)->data)
        {
            del_node(&(*rt)->left,key);
        }
        else
        {
            if((*rt)->left == NULL && (*rt)->right == NULL)
            {
                free(*rt);
                *rt = NULL ;
            }
            else if((*rt)->left==NULL)
            {
                temp = *rt ;
                *rt = (*rt)->right ;
                free(temp );
            }
            else if((*rt)->right == NULL)
            {
                temp = *rt;
                *rt = (*rt)->left ;
                free(temp);
            }
            else
            {
                 temp = findMin((*rt)->right);

                (*rt)->data = temp->data;

                del_node(&((*rt)->right), temp->data);
            }
        }
    }
    

}
