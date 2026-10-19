#include <stdio.h>
#include <stdlib.h>

typedef struct circular_list
{
    int data ;
    struct circular_list *next ;
}cl;

void create(cl**);
void insert_node(cl** ,int );
int count(cl*head);
void display(cl *head);
void del(cl**, int );


int main()
{
    cl *head = NULL ;
    int ch , node , value ;

    do{
        printf("\n 1 : create \n 2 : insert_node \n 3 : delete a node \n 4 :display \n 4 : count \n enter your choice :");
        scanf("%d",&ch);

        switch (ch)
        {
            case 1 :
                create(&head);
                break ;
            case 2 :
                printf("enter the node position you want to insert : ");
                scanf("%d",&node);

                insert_node(&head,node);
                break ;
            case 3 :
                printf("enter the value you want to delete : ");
                scanf("%d",&value);

                del(&head,value);
                break ;

            case 4 :
                display(head);
                break ;
            case 5 :
                printf("the number of nodes in the list : %d ",count(head));
                break ;

        }
    }while(ch<=4);

    return 0 ;
}

void create(cl **head)
{
    cl *p=NULL , *r = NULL ;
    int ch ;

    while(1)
    {
        p =(cl*)malloc(sizeof(cl));
        
        if(p==NULL)
        {
            printf("not enough memory");
            break ;
        }
        else
        {
            printf("enter the value you want to insert in the list : ");
            scanf("%d",&(p->data));
            if(*head == NULL)
            {
                *head = r = p ;
            }
            else
            {
                r->next = p;
                r=p;
            }
            r->next = *head ;


        }

        printf("do you want to insert another node(0/1) : ");
        scanf("%d",&ch);

        if(ch==0)
        {
            printf("\nLINKED LIST COMPLETED\n");
            break ;  
        }
    
    }
}

void insert_node(cl** head , int node)
{
    cl *p=NULL , *t = *head ;
    int c =1 , con = count(*head) ;

    if(node>0&&node<=con+1)
    {
        p =(cl*)malloc(sizeof(cl));

        if(p==NULL)
        {
            printf("memory not allocated ");
        }
        else
        {

            printf("enter the value you want to insert : ");
            scanf("%d",&(p->data));
            if(node==1)
            {
                p->next = *head ;
                while(t->next!=*head)
                {
                    t = t->next ;
                }
                t->next = p ;
                *head = p ;
            }
            else if (node == con+1)
            {
                while(t->next!=*head)
                {
                    t = t->next ;
                }
                t->next = p ;
                
                p->next = *head ;
            }
            else
            {
                while(c<node)
                {
                    t = t->next ;
                    c++;
                }
                p->next = t->next ;
                t->next = p ;
            }
        }

    }
    else
    {
        printf("the entered node is out of range");
    }
}

int count(cl * head)
{
    int c = 1 ;
    cl *p=head;

    if(head==NULL)
    {
        c =0 ;

    }
    else
    {
        do
        {
            c++;
            p = p->next ;

        }while(head!=p->next);
    }

    return c ;
}

void display(cl*head)
{
    cl *p= head ;

    if(p==NULL)
    {
        printf("the list is empty ");

    }
    else
    {
        do{
            printf("%d \t",p->data);
            p = p->next ;
        }while(p!=head);
    }
}

void del(cl** head , int value)
{
    cl* p = *head ,*prev = *head , *s = NULL;
    int c = 1 , present = 0;

    while(p->next!=*head)
    {
        c++;
        if(p->data== value)
        {
            present = 1 ;
            break ;
        }
        else
        {
            printf("that element is not p");
        }
        p = p->next ;
    }

    if(present == 1)
    {
        while(prev->next!=*head)
            {
                prev=prev->next ;
            }

        if(c==1)
        {
            s = p ;
            prev->next = p->next ; //prev is the last node
            p = p->next ;
            *head = p ;
            free(s);
        }
        else if(c == count(*head))
        {
            s = prev->next ; // s = p ;
            prev->next = *head;

            free(s);
        }
        else
        {
            s = p  ;
            prev->next = p ;
            free(s);
        }
    }
}