#include <stdio.h>
#include <stdlib.h>

typedef struct Tree_type
{
    struct Tree_type *left ;
    int data ;
    struct Tree_type *right ;
}tt ;

void create(tt**,int );
 
int main()
{
    tt *root = NULL ;
    int ch ;


    do
    {
        printf("\n enter the choice \n 1 : insert \n 2 : display preorder \n 3 : display inorder \n 4 : display preorder ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1 :
                break ;
            case 2 : 
                break ;
            case 3 : 
                break ;
            case 4 :
                break ;
        }
    }while(ch<=4);

    return 0 ;
    
}


void create(tt **rt , int v)
{
       
}



