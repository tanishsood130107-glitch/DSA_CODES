#include <stdio.h>
#include <stdlib.h>

typedef struct list
{
    int data ;
    struct list *next ;
}l;

void create(l**);
void stack_display(l*);
void queue_display(l*);


int main()
{
    l *head = NULL ;
    int ch ;

    do
    {
        printf("\n 1 : create \n 2 : queue_using_stack \n 3 : stack_display \n enter you choice : ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1 :
                create(&head);
                break ;
            case 2 : 
                queue_display(head);
                break ;
            case 3 : 
                stack_display(head);
                break ;
        }
    }while(ch<=3);

    return 0 ;
}


void create(l **head)
{
    l *p=NULL;
    int ch ;
    while(1)
    {

        p = (l*)malloc(sizeof(l));

        if(p==NULL)
        {
            printf("not enough memory : ");
        }
        else
        {
            printf("enter the data you want to insert : ");
            scanf("%d",&(p->data));

            p->next = *head;
            *head = p ;
        }

        printf("do you want to insert more nodes(0/1) : ");
        scanf("%d",&ch);

        if(ch == 0)
        {
            break ; 
        }


    }
}

void stack_display(l *head )
{
    if(head == NULL)
    {
        printf("the list is empty : ");
    }
    else
    {
        while((head != NULL))
        {
            printf("%d \t",head->data);
            head = head->next ;
        }
    }
}


void queue_display(l * head)
{
    if(head->next==NULL)
    {
        printf("%d \t",head->data);
        return ;
    }
    else 
    {
        queue_display(head->next);

        printf("%d \t",head->data);
    }
}