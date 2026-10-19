#include <stdio.h>
#include <stdlib.h>


typedef struct circular_list
{
    int data ;
    struct circular_list *next  ;
}cl;

void left_insert(cl**);
void right_insert(cl**);

void left_insert(cl**head)
{
    cl *p = NULL ,*r = NULL;

    p = (cl*)malloc(sizeof(cl));

    if(p==NULL)
    {
        printf("memory not allocated ");
    }
    else
    {
        if((*head)==NULL)
        {
            *head = r = p ;
            p->next = r ;
        }
        else
        {
            p->next = r ;


        }
    }

}