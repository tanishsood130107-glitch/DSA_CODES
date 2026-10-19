#include <stdio.h>
#include <stdlib.h>

typedef struct circular_list 
{
    int data ;
    struct circular_list *next ;

}cl ;

void insert(cl**,cl**);
void deletenode(cl**,cl**);
void display(cl*);

int main()
{
    cl *front = NULL, *right = NULL ;
    int ch ;

    do
    {
        printf("\n 1 : insert \n 2 : remove \n 3 : display \n ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                insert(&front, &right);
                break ;
            case 2 :
                deletenode(&front,&right);
                break ;
            case 3 :
                display(front);
                break ;

                
        }
    }while(ch<=3);

    return 0 ;
}

void insert(cl **front , cl **right)
{
    cl* p=NULL ;

    p =(cl*)malloc(sizeof(cl));

    if(p==NULL)
    {
        printf("memory not allocated ");
    }
    else
    {
        printf("enter the data you want to insert : ");
        scanf("%d",&(p->data));

        if(*front ==NULL && *right == NULL)
        {
            (*front)=*right = p ;
        }
        else 
        {
            (*right)->next = p ;
            *right = p ;
        }

        p->next = *front ;


    }
}

void display(cl *front)
{
   cl *p=front ;

   if(p==NULL)
   {
    printf("the list is empty : ");
   }
   else
   {
    do
    {
        printf("%d \t", p->data);
        p = p->next ;
    }while(p!=front);
    
   }
}

void deletenode(cl **front , cl **right )
{
    cl *p=NULL ;

    if(*front == NULL && *right == NULL)
    {
        printf("the list is empty ");
    }
    else
    {
        p = *front ;

        printf("the deleted element is : %d ", p->data);

        if(*front == *right )
        {
            *front = *right = NULL;
        }
        else
        {
            (*front) = (*front)->next;
            (*right)->next = *front ;
        }
    }

    free(p);
}

