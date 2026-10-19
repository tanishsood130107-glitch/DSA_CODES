#include <stdio.h>
#include <stdlib.h>

typedef struct double_list
{
    struct double_list *prev ;
    int data ;
    struct double_list *next ;
}dl ;


void create(dl**);
void display(dl*);

int main()
{
    dl *head = NULL ;
    int ch ;
    
    do
    {

        printf("\n 1 : create a doubly linked list \n 2 : display \n enter your choice : ");
        scanf("%d",&ch);

        switch (ch)
        {
            case 1 :
                create(&head);
                break ;
            case 2 :
                display(head);
                break ;
        }
    }while(ch<=2);

    return 0 ;
}

void create(dl **head )
{
    dl *p = NULL , *r = NULL;
    int ch ;

        while(1)
        {
            p = (dl*)malloc(sizeof(dl));
            if(p==NULL)
            {
                printf("not enough memory ");
                
            }

            else 
            {

                printf("enter the element you want to insert : ");
                scanf("%d",&(p->data));
                if(*head == NULL)
                {
                    p->prev = p ;
                    p->next = p ;
                    *head = r = p ;
                }
                else 
                {
                    p->prev = r ;
                    r->next = p ;

                    p->next = *head ;
                    (*head)->prev = p ;

                    r = p ;

                }

                printf("do you want to insert more nodes to the list(0/1) : ");
                scanf("%d",&ch);

                if(ch == 0)
                {
                    break ;
                }


            }

        }

    }


void display(dl * head)
{
    dl *p = head ; 

    if(head == NULL )
    {
        printf("the list is empty : ");
    }
    else
    {
        do
        {
            printf("%d \t", p->data);
            p = p->next ;
        }
        while(p!=head);
    }
}