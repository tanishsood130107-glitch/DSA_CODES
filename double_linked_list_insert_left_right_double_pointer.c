#include <stdio.h>
#include <stdlib.h>

typedef struct double_list 
{
    struct double_list *prev;
    int data ;
    struct double_list *next ;
}dl;

void insert_left(dl**,dl**);
void insert_right(dl**,dl**);
void display(dl*);

int main()
{
    dl *l = NULL , *r = NULL ;
    int ch ;

    do
    {
        printf("\n 1 : insert_left \n 2 : insert_right \n 3 : display \n enter your choice : ");
        scanf("%d",&(ch));

        switch(ch)
        {
            case 1 :
                insert_left(&l,&r);
                break ;
            case 2 :
                insert_right(&l,&r);
                break ;
            case 3 :
                display(l);
                break ;

        }


    }while(ch<=3);

    return 0 ;
}

void insert_left(dl **l, dl **r)
{
    dl *p = NULL ;

    p = (dl*)malloc(sizeof(dl));

    if(p==NULL)
    { 
        printf("not enough memory : ");
    }
    else
    {
        printf("enter the data you want to insert in the list : ");
        scanf("%d",&(p->data));

        if(*l == NULL)
        {
            p->prev = NULL ;
            p->next = NULL ;
            *l = *r = p   ;
        }
        else
        {
            p->prev = NULL ;
            p->next = *l ;
            (*l)->prev = p ;

            (*l) = p ;

        }
    }


}


void insert_right(dl **l , dl **r)
{
    dl *p=NULL ;

    p = (dl*)malloc(sizeof(dl));

    if(p==NULL)
    {
        printf("not enough memory ");
    }
    else
    {
        printf("enter the data you want to insert in the list : ");
        scanf("%d",&(p->data));

        if(*r == NULL)
        {
            p->prev = NULL ;
            p->next = NULL ;

            *l = * r = p ;
        }
        else
        {
            p->prev = *r ;
            (*r)->next = p ;
            p->next = NULL ;
            
            *r = p ;

        }
    }
}

void display(dl *l)
{
    if(l==NULL)
    {
        printf("the list is empty ");

    }
    else
    {
        while(l!= NULL)
        {
            printf("%d \t", l->data);
            l = l->next ;
        }
    }
}