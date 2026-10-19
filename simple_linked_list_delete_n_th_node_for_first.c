#include <stdio.h>
#include <stdlib.h>

typedef struct list 
{
    int data ;
    struct list *next ;
}l; 

void create(l**);
int count(l*);
void remove_f(l**, int );
void remove_l(l** , int );
void display(l*);


int main()
{
    l *head = NULL;
    int ch , node ;

    do
    {
        printf("\n 1 : create \n 2 : remove fron front \n 3 : remove from last  \n 4 : display \n enter your choice : ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1 :
                create(&head);
                break ;
            case 2 :
                printf("enter the node you want to search ");
                scanf("%d",&node);

                remove_f(&head,node);
                break ;
            case 3 :
                printf("enter the node you want to search ");
                scanf("%d",&node);

                node = count(head)- node +1 ;
                remove_f(&head,node);
                break ;
            case 4 :
                display(head);
                break ;

        }
    }while(ch<=4);

    return 0 ;


}



void create(l **head)
{
    l *p=NULL, *last = NULL ;
    int ch ;

   
    
        while(1)
        {

            p = (l*)malloc(sizeof(l));

            if(p==NULL)
            {
                printf("memory not allocated ");
                break ;
            }
            else
            {
                printf("enter the value you want to insert : ");
                scanf("%d",&(p->data));

                if(*head == NULL)
                {
                    *head = p ;
                    last = p ;
                }
                else
                {
                    (last)->next = p ;
                    last = p ;
                }
                (last)->next = NULL ;

                printf("do you want to enter another node(0/1) : ");
                scanf("%d",&ch);

                if(ch==0)
                {
                    printf("\nlinked list completed\n");
                    break ;
                }
            }
        }
    

}

int count(l *head)
{
    int c = 0 ;

    if(head==NULL)
    {
        c = 0 ;
    }
    else 
    {
        while(head!=NULL)
        {
            c++;
            head = head->next;
        }
    }

    return c ;
}

void remove_f (l **head, int node)
{
    l* curr =*head , *prev = NULL,  *p=NULL;
    int i ;

    if(*head == NULL)
    {
        printf("the list is empty ");
    }
    else
    {
       if(count(*head)==1)
       {
            if(node==1)
            {
                free(curr);
                *head = NULL ;
            }
            else
            {
                printf("node is out of range ");
            }

       }
       else
       {
            if(node<=count(*head)&&node>0)
            {
                 i =1 ;
                while(i<node)
                {
                    prev = curr ;
                    curr =  curr->next ;
                    i++;
                }

                if(node ==1)
                {
                    *head =  curr->next ;

                }
                else if(curr->next == NULL)
                {
                    prev->next = NULL;
                }
                else
                {
                    prev->next = curr->next ;
                    curr->next = NULL ;
                }
                free(curr);
            }
            else
            {
                printf("node is out of the range : ");
            }

       }
        
    }


}



void display(l *head)
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
            head = head->next;
        }
    }
}