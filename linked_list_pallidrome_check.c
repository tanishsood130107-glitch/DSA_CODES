#include <stdio.h>
#include <stdlib.h>

typedef struct simple_list
{
    int data ;
    struct simple_list *next ;
}sl ;

void create(sl**);
void stack(sl**, sl*head);
int check(sl*);
void display(sl*);


int main()
{
    sl * head = NULL;
    int ch , flag ;

    do
    {

        printf("\n enter your choice \n 1 : create a linked list \n 2 : pallidrome_check \n 3 : display");
        scanf("%d",&ch);


        switch (ch)
        {
            case 1 :
                create(&head);
                break ;
            case 2 :
                flag = check(head);
                if(flag==1)
                {
                    printf("the linked list is a pallidrome ");
                }
                else
                {
                    printf("the linked list is not a pallidrome ");
                }
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

    sl* p = NULL , *r = NULL ;
    int ch ;

    if(*head == NULL)
    {
        while(1)
        {
            p = (sl*)malloc(sizeof(sl));

            if(p==NULL)
            {
                printf("memory not allocated : ");

            }
            else
            {
                printf("enter the data you want to insert : ");
                scanf("%d",&(p->data));

                if(*head==NULL)
                {
                    *head = r = p ;
                }
                else
                {
                    r->next = p;
                    r = p ;
                }
                r->next = NULL;


                printf("do you want to add more nodes(0/1) : ");
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
        printf("list already created ");
    }

}

void stack(sl** s_h ,sl *head)
{
    sl* p= NULL;

    if(head == NULL)
    {
        printf("the list is empty ");
    }
    else
    {
        while(head!=NULL)
        {
            p = (sl*)malloc(sizeof(sl));

            if(p==NULL)
            {
                printf("memory not allocated : ");
            }
            else
            {
                p->data  = head->data;
                p->next = *s_h;
                *s_h = p;
            }

            head= head->next ;
        }
    }
}

int  check(sl*head)
{
    sl *s_h = NULL ;
    int flag = 1 ;
    if(head==NULL)
    {
        printf("the list is empty ");
    }
    else
    {
        stack(&s_h,head);

        while(head!=NULL)
        {
            if(head->data==s_h->data)
            {
            
            }
            else
            {
                flag = 0 ;
                break ;
            }

            head = head->next ;
            s_h = s_h->next ;
        }

    }

    return flag ;
}


void display(sl*head)
{
    if(head==NULL)
    {
        printf("the list is empty ");
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