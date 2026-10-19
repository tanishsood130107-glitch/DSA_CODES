#include <stdio.h>
#include <stdlib.h>


typedef struct list 
{
    int data ;
    struct list *next ;
}l ;

void create(l**);
l *reverse(l *head);

int main()
{
    l *head ;
    int ch ;

    do
    {
        printf("\n 1 : create \n 2 : pallidrome_check \n 3 : display \n enter your choice ");
        scanf("%d",&ch);

        switch (ch)
        {
            case 1 :
                create(&head);
                break ;

        }

    }
}

void create(l **head)
{
    l *p = NULL , *r = NULL ;
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
            printf("enter the value of the node you want to insert : ");
            scanf("%d",&(p->data));

            if(*head == NULL)
            {
                *head = r = p ;
            }
            else
            {
                r->next = p ;
                r = p ;
            }
            r->next = NULL ;
        }

        printf("do you want to insert more nodes (0/1) : ");
        scanf("%d",&ch);

        if(ch==0)
        {
            break ;
        }
    }

}

l *reverse(l *head)
{
    l *p = NULL , *t = NULL , *r= NULL ;

    p = (l*)malloc(sizeof(l));
    if(head==NULL)
    {
        return ;
    }
    else
    {
        reverse(head->next);
        if(p == NULL)
        {
            p = t = head;
        }
        else
        {
            t->next = head;
            t = head;
        }
        t->next = NULL ;

    }

    return  t ; 
}