#include <stdio.h>
#include <stdlib.h>

typedef struct double_list
{
    int data ;
    struct double_list *prev , *next ;
}dl;

void create(dl **);
void swap(dl **);
void display(dl*);

int main()
{
    dl *head = NULL ;
    int ch ;

    do
    {
        printf(" 1 : create \n : 2 : swap adjucent node \n 3 : display \n enter your choice   ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1 :
                create(&head);
                break ;
            case 2 :
                swap(&head);
                break ;
            case 3 : 
                display(head);
                break ;
        }


    }while(ch<=3);

    return 0 ;
}


void create(dl **head)
{
    dl *p = NULL , *r = NULL ;
    int ch ;

    while(1)
    {
        p = (dl*)malloc(sizeof(dl));

        if(p == NULL )
        {
            printf("not enough memory ");
        }
        else
        {
            printf("enter the element you want to insert : ");
            scanf("%d",&(p->data));

            if(*head == NULL)
            {
                p->prev = NULL ;
                p->next = NULL ;
                *head  = r = p ;
            }
            else
            {
                r->next = p ;
                p->prev = r ;
                r = p ;
                r->next = NULL;
            }

            printf("do you want to insert more elements (0/1) : ");
            scanf("%d",&ch);

            if(ch==0)
            {
                break ;
            }
        }
    }
}

void swap(dl **head)
{
    dl *curr = *head  , *p = (*head)->next ;
    int temp ;
    
    if(curr==NULL)
    {
        printf("the list is empty : ");
    }
    else
    {
        while(curr->next!=NULL)
        {
            if(curr == *head)
            {
                temp = curr->data ;
                curr->data = p->data ;
                p->data = temp ;
                //curr->data , (curr->next)->data = (curr->next)->data , curr->data ;
                *head = curr ;
            }
            else
            {
                temp = curr->data ;
                curr->data = p->data ;
                p->data = temp ;
                //curr->data , (curr->next)->data = (curr->next)->data , curr->data ;
            }

            
            curr = curr->next->next ;
            p = p->next->next ;
            

            /*if(curr == *head )
            {
                
                p->prev = NULL ;
                curr->next = p->next ;
                (p->next)->prev = curr ; 
                curr->prev = p ;
                p->next = curr ;

                *head = p ;
            }
            else
            {

                p->prev = curr->prev;
                curr->next = p->next ;
                (curr->prev)->next  = p ;
                curr->prev = p;
                p->next = curr ;

            }
                */

              
        }
    }

}

void display(dl *head)
{
    if(head==NULL)
    {
        printf("the list is empty : ");

    }
    else
    {
        while(head!=NULL)
        {
            printf("%d \t",head->data);
            head = head->next ;
        }
    }
}