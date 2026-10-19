#include <stdio.h>
#include <stdlib.h>

typedef struct double_list
{
    struct double_list *prev ;
    int data ;
    struct double_list *next ;
}dl ;


void insert(dl** , dl**); 
void display(dl*);

int main()
{
    dl *l = NULL , *r = NULL ;
    int ch ;    

    do
    {
        printf("\n 1 : insert asending order \n 2 : display \n enter your choice ");
        scanf("%d",&ch);

        switch (ch)
        {
            case 1 :
                insert(&l , &r);
                break ;
            case 2 :
                display(l);
                break ;
        }
    }while(ch<=2);

    return 0 ;
}


void insert(dl **l , dl **r)
{
    dl *p = NULL ,  *add = (*l) ;

    p = (dl*)malloc(sizeof(dl));

    if(p==NULL)
    {
        printf("not enough memory : ");
    }
    else
    {
        printf("enter the value you want to insert : ");
        scanf("%d",&(p->data));


        if(*l==NULL)
        {
            p->prev = NULL ;
            p->next = NULL ;
            *l = *r = p ;
        }
        //else if( (*l == *r)&&(*l!=NULL))
        //{
        //  if(p->data > (*r)->data)
        //    {
        /*   (*r)->next = p ;
                p->prev = *r ;
                *r = p ;
            }
            else
            {
                p->prev = NULL ;
                p->next = *r ;
                (*r)->prev = p ;

                *l = p ;
            }
        }*/
        else 
        {
            if(p->data>(*r)->data)
            {
                p->prev = *r ;
                (*r)->next = p ;
                p->next = NULL ;
                *r = p ;
            }
            else
            {
                //((*r)->prev)->next = p ;
                //p->prev = (*r)->prev ;
                //p->next = *r ;
                //(*r)->prev = p ;

                if((*l)->data > p->data)
                {
                    (*l)->prev = p ;
                    p->prev = NULL ;
                    p->next = *l ;
                    *l = p ;
                }
                else
                {
                    while(p->data > (add->next)->data)
                    {
                        add = add->next ;
                    }

                    p->prev = add ;
                    p->next = add->next ;
                    (add->next)->prev = p ;
                    add->next = p ;
                }


            }

        }
    }

}

void display(dl *l)
{
    if(l == NULL)
    {
        printf("the list is empty : ");
    }
    else
    {
        while(l!=NULL)
        {
            printf("%d \t",l->data);
            l = l->next ;
        }
    }
}