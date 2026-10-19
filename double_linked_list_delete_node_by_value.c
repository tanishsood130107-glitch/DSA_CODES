#include <stdio.h>
#include <stdlib.h>


typedef struct double_list
{
    int data ;
    struct double_list *next , *prev ;
}dl;


void del(dl** l , dl **r , int val)
{
    dl *p = *l ;
    int found = 0 ;

   if(p==NULL)
   {
        printf("the list is empty : ");
   }
   else
   {
        while(1)
        {
            if(val == p->data)
            {
                found = 1 ;
                break ;
            }
            p = p->next ;
        }

        if(found==0)
        {
            printf("the value is not present in the list : ");
        }
        else
        {
            if(p->prev == NULL)
        {
            *l = p->next ;
            p->next = NULL ;
        }
        else if(p->next == NULL)
        {
            *r = p->prev ;
            (*r)->next == NULL ;
            p->prev = NULL ;
        }
        else
        {
            (p->next)->prev = p->prev ;
            (p->prev)->next = p->next ;
            p->next = NULL ;
            p->prev = NULL ;
        }

        free(p);
        }
   }
}