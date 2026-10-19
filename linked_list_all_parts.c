#include <stdio.h>
#include <stdlib.h>

typedef struct simple_list
{
    int data ;
    struct simple_list *next ;
}sl ;


void insert_left(sl **);
void insert_right(sl**);
void insert_after_first_node(sl**);
void insert_before_last_node(sl**);
void insert_after_node_given_by_user(sl**,int);
int count(sl*);
void display(sl*);

int main()
{
    sl *head = NULL ;
    int ch , node ;

    do
    {
        printf("\n enter your choice \n 1 : insert left \n 2: insert right \n 3 : insert after first node \n 4 : insert before last node \n 5 : user choice node insert : \n 6 : display \n ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1 : 
                insert_left(&head);
                break ;
            case 2 : 
                insert_right(&head);
                break ;
            case 3 : 
                insert_after_first_node(&head);
                break ;
            case 4 : 
                insert_before_last_node(&head);
                break ;
            case 5 : 
                printf("enter the node you want to insert :");
                scanf("%d",&node);
                insert_after_node_given_by_user(&head,node);
                break ;
            case 6 : 
                display(head);
                break ;

        }
    }while(ch<=6);

    return 0 ;
}


void insert_left(sl **head)
{
    sl *p = NULL , *r = NULL ;

    p = (sl*)malloc(sizeof(sl));

    if(p==NULL)
    {
        printf("memory not allocated : ");
        return ;
    }
    else
    {
        printf("enter the data you want to insert : ");
        scanf("%d",&(p->data));

        p->next = (*head);
        (*head) = p ;
    }
}


void insert_right(sl**head)
{
    sl *p = NULL  , *r = *head ;

    p = (sl*)malloc(sizeof(sl));

    if(p==NULL)
    {
        printf("memory not allocated : ");
        return ;
    }
    else
    {
        printf("enter the data you want to insert : ");
        scanf("%d",&(p->data));

        if((*head)==NULL)
        {
            (*head)=r = p ;
        }
        else
        {
            while(r->next!=NULL)
            {
                r = r->next ;
            }
            r->next = p ;
            r = p ;
            
        }
        r->next = NULL;
       

    }
}

void insert_after_first_node(sl **head)
{
    sl *p = NULL ;

    p = (sl*)malloc(sizeof(sl));

    if(p==NULL)
    {
        printf("memory not allocated : ");
    }
    else
    {

        printf("enter the value you want to insert : ");
        scanf("%d",&(p->data));


        if(*head == NULL)
        {
            *head = p ;
            (*head)->next = NULL ;

        }
        else
        {
            p->next = (*head)->next ;
            (*head)->next = p ;
        }
    }


}

void insert_before_last_node(sl **head)
{
    sl *p = NULL , *r = *head ;
    int c =count(*head);

    p = (sl*)malloc(sizeof(sl));

    if(p==NULL)
    {
        printf("memory not allocated : ");
        return ;
    }
    else
    {
        printf("enter the value  you want to insert : ");
        scanf("%d",&(p->data ));

        if(*head == NULL)
        {
            *head = r = p ;
            (*head)->next = NULL ;
        }
        else
        {
            if(c==1)
            {
                p->next = r;
                *head = p ;
            }
            else
            {
                while(r->next->next !=NULL)
                {
                    r = r->next ;
                }

                p->next = r->next ;
                r->next = p ;
            }

        }
    }

}

int count(sl*head)
{
    int c = 0 ;

    if(head == NULL)
    {
        c = 0 ;
    }
    else
    {
        while(head!=NULL)
        {
            c++;
            head = head->next ;
        }
    }

    return c ;
}

void insert_after_node_given_by_user(sl**head , int N )
{
    int c = count(*head), i = 1 ;
    sl *p = NULL , *prev = *head;

    if(N>=1&&N<=c+1)
    {
        p = (sl*)malloc(sizeof(sl));

        printf("enter the data you want to insert : ");
        scanf("%d",&(p->data));

        while(i<N-1  )
        {
            prev = prev->next ;
            i++;
        }


        if(*head == NULL)
        {
            *head = p ;
            p->next = NULL ;
        }
        else
        {
            if(N==1)
            {
                p->next = *head;
                *head = p ;
            }
            else if(N == c+1)
            {
                prev->next = p ;
                p->next = NULL;
            }
            else
            {
               p->next = prev->next ;
               prev->next = p ;

            }
        }
    }
}


void display(sl *head)
{
    if(head == NULL)
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
