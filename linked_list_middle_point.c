#include <stdio.h>
#include <stdlib.h>

typedef struct list
{
    int data ;
    struct list *next ;
}l;


void create(l**);
void display(l*);
void middle(l*);

int main()
{
    l *head = NULL ;
    int ch ;

    do{
        printf("\n 1 : create \n  2 : find_middle \n 3 : display \n enter your choice :");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1 :
                create(&head);
                break ;
            case 2 :
                middle(head);
                break ;
            case 3 :
                display(head);
                break ;
        }
    }while(ch<=3);

    return 0 ;
    
}

void create(l **head)
{
    l *p=NULL , *last = NULL;
    int ch ;

    while(1)
    {
        p = (l*)malloc(sizeof(l));

        if(p==NULL)
        {
            printf("size not allocated :");
        }
        else
        {
            printf("enter the value you want to insert : ");
            scanf("%d",&(p->data));

            if(*head==NULL)
            {
                *head = last = p ;
            }
            else
            {
                last->next = p ;
                last = p ;
            }
            last->next = NULL ;

            printf("do you want to insert more nodes (0/1) : ");
            scanf("%d",&ch);

            if(ch==0)
            {
                printf("\nlinkedkist completed\n");
                break ;
            }
        }
    }
}

void display(l* head)
{
    if(head == NULL)
    {
        printf("the list is empty ");
    }
    else
    {
        while(head !=NULL)
        {
            printf("%d \t",head->data);
            head = head->next ;
        }
    }
}

void middle(l* head)
{
    l *s=head , *f= head ;

    if(head == NULL)
    {
        printf("the list is empty : ");
       
    }
    else
    {
        while(f!=NULL && f->next!=NULL)
        {
            s = s->next ;
            f = f->next->next ;
        }

        printf("the middle element of the list is %d : ", s->data);
    }
}