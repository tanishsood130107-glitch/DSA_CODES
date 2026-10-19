#include <stdio.h>
#include <stdlib.h>

typedef struct simple_list
{
    int data ;
    struct simple_list *next ;
}sl;

void delete_first_node(sl**);
void delete_last_node(sl**);
void delete_node_given_user(sl**,int);
void delete_node_contaning_a_value(sl**, int);
void create(sl**);
void display(sl*);
int count(sl*);

int main()
{
    sl *head = NULL ;
    int ch , node , value;

    do
    {
        printf("\n enter the choice \n 1 : create \n 2 : delete first element \n 3 : delete last element  \n 4 : delete user node \n 5 : display \n 6 node contaning a particular value  \n  ");
        scanf("%d",&ch);


        switch(ch)
        {
            case 1 :
                create(&head);
                break ;
            case 2 :
                delete_first_node(&head);
                break ;
            case 3 :
                delete_last_node(&head);
                break ;
            case 4 :
                printf("enter the node you want to delete : ");
                scanf("%d",&node);

                delete_node_given_user(&head, node );
                break ;

            case 5 :
                display(head);
                break ;
            case 6 :
                printf("enter the value you want to delete from the linked list :");
                scanf("%d",&value);
                delete_node_contaning_a_value(&head,value);
                break;
        }
       
    } while (ch<=6);
    return 0 ;
    
}


void delete_first_node(sl**head)
{
    sl *p = NULL ;

    if(*head ==NULL)
    {
        printf("the list is empty : ");
    }
    else
    {
        printf("the value delted is %d : ", (*head)->data);
        p = *head ;

        (*head) =(*head)->next ;

        free(p);
    }

    
}

void delete_last_node(sl**head)
{
    sl *p = NULL , *prev = *head ;
    int i = 0 ;
    if(*head ==NULL)
    {
        printf("the list is empty : ");
    }
    else
    {
        

        if((*head)->next == NULL)
        {
            p = *head;
            (*head) = NULL;
        }
        else
        {
            while(prev->next->next !=NULL)
            {
                prev = prev->next ;
            }

            p = (prev->next);
            prev->next = NULL ;

        }

        printf("the node which is being deleted is : %d ", p->data);
        free(p);
        
    }
}

void create(sl **head)
{
    sl *p = NULL , *r = NULL ;
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


            printf("do you want to insert more nodes(0/1) :  ");
            scanf("%d",&ch);

            if(ch ==0)
            {
                break ;
            }
        }
       }
    }
}


void display(sl*head)
{
    if(head==NULL)
    {
        printf("the list is empty : ");
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

int count(sl *head)
{
    int c = 0 ;
    if(head==NULL)
    {
        printf("the list is empty");
    }
    else
    {
        while(head != NULL)
        {
            c++;
            head = head->next ;
        }
    }

    return c;

}


void delete_node_given_user(sl**head,int N)
{
    sl * p = NULL , *prev = *head;
    int c = count(*head), i = 1;

    if(*head == NULL)
    {
        printf("the list is empty : ");
    }
    else
    {
        if((N>0)&&(N<=c))
        {
            while(i<N-1)
            {
                prev=prev->next ;
                i++;
            }

            if(N==1)
            {
                p = *head;
                *head = (*head)->next ;
            }
            else if (N == c)
            {
                p = prev->next ;
                prev->next = NULL;
            }
            else
            {
                p = prev->next ;
                

                prev->next = p->next ;
            }

            printf("the delted value is %d",p->data);
           
            free(p);
        }
        else
        {
            printf("node is out of bound : ");
        }
    }

}


void delete_node_contaning_a_value(sl**head, int val)
{
    int  c = 1 ;
    sl *prev = NULL , *p = NULL, *r = *head;

    if(*head!=NULL)
    {
        while(r!=NULL)
        {
            if(val==r->data)
            {
                p = r ;
                if(prev==NULL)
                {
                    *head = (*head)->next ;
                    r = r->next ;
                }
                else
                {
                    prev->next = r->next ;
                    r = prev->next ;
                }
                free(p);


            }
            else
            {
                prev = r ;
                r = r->next ;
            }

        }
            
              
    }
}