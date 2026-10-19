#include <stdio.h>
#include <stdlib.h>


typedef struct simple_list 
{
    int data ;
    struct simple_list *next ;
}sl;

void create(sl**);
void delete_even_nodes(sl**);
void display(sl*head);


int main()
{
    sl * head = NULL;
    int ch , flag ;

    do
    {

        printf("\n enter your choice \n 1 : create a linked list \n 2 : delte even node \n 3 : display");
        scanf("%d",&ch);


        switch (ch)
        {
            case 1 :
                create(&head);
                break ;
            case 2 :
                delete_even_nodes(&head);
                break ;
            case 3 : 
                display(head);
                break ;
        }

    }while(ch<=3);

    return 0 ;
}

void create(sl**head)
{
    sl *p = NULL , *r = NULL;
    int ch ;
    if(*head==NULL)
    {
        while(1)
        {
            p = (sl*)malloc(sizeof(sl));

            if(p!=NULL)
            {
                printf("enter the data you want to insert : ");
                scanf("%d",&(p->data));
                if(*head ==NULL)
                {
                    *head = r = p ;
                }
                else
                {
                    r->next = p;
                    r= p;
                }
                r->next = NULL;

                printf("do you want to insert more node(0/1) : ");
                scanf("%d",&ch);

                if(ch==0)
                {
                    break ;
                }

            }
        }
    }
    else
    {
        printf("the list is alredy created");
    }
}


void delete_even_nodes(sl**head)
{
    sl *p = NULL, *r = *head , *prev = *head ;
    int c = 1 ;

    if(*head == NULL)
    {
        printf("the list is empty : ");
    }
    else
    {
        while(r!=NULL)
        {
            prev = *head ;
            if(c%2==0)
            {
                while(prev->next!=r)
                {
                    prev = prev->next ;
                }
                
                if(r->next==NULL)
                {
                    prev->next = NULL ;

                }
                else
                {
                    prev->next = r->next ;
                }
                p = r ;
                r = prev->next ;
                free(p);

            }
            else
            {
                r=r->next ;
            }

            c++;
           
            
        }

    }
}


void display(sl*head)
{
    if(head ==NULL)
    {
        printf("The list is being empty :");
    }
    else
    {
        while(head!=NULL)
        {
            printf("%d\t",head->data);
            head = head->next ;
        }
    }
}