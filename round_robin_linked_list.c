#include <stdio.h>
#include <stdlib.h>
#include <string.h>
# define time  10 

typedef struct round_robin
{
    int PT ;
    char PN[3];
    struct round_robin *next ;
}rr;
 
void create(rr **);
void process(rr**);
void display(rr*);

int main()
{
    rr *head = NULL ;
    int ch ;

    do
    {
        printf("\n 1 : create \n 2 : procees \n 3 : display \n : ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1 :
                create(&head);
                break ;
            case 2 :
                process(&head);
                break ;
            case 3 :
                display(head);
                break; 
        }
    }while(ch<=3);

    return 0 ;
}

void create(rr **head)
{
    rr *p=NULL , *last = NULL ;
    int ch ;

    while(1)
    {
        p = (rr*)malloc(sizeof(rr));

        if(p==NULL)
        {
            printf("memory not allocated ");
            break ;
        }
        else
        {
            getchar();
            printf("enter the process name : ");
            gets(p->PN);
            getchar();
            printf("enter the process time : ");
            scanf("%d",&p->PT);


            if((*head==NULL))
            {
                *head = p ;
                (*head)->next = *head;
                last = *head ;
            }
            else
            {
                last->next = p ;
                last = p ;
                p->next = *head ;
                
                
            }

            printf("do you want to create more nodes (1/0) :" );
            scanf("%d",&ch);

            if(ch==0)
            {
                break ;
            }
        }
    }
}

void process(rr **head)
{
    rr *p= *head , *s=NULL;
    int count = 0 , t = 0;

    if(p==NULL)
    {
        printf("there are currently no proceess");
    }
    else
    {
        while((*head)!=NULL)
        {
            count = count + time; 
            p->PT = p->PT-time ;

            if(p->PT<=0)
            {
                if(p==p->next)
                {
                    *head = NULL ;
                    printf("process completed is %s : \n", p->PN);
                    
                    printf("time taken in sec to complete this process : %d \n", count);
                    free(p);
                    p= NULL ;
                }
                else
                {
                    
                    printf("process completed is %s : \n", p->PN);
                    
                    printf("time taken in sec to complete this process : %d \n", count);
                    if(p==(*head))
                    {
                        rr *s = p ;
                        while(s->next!=p)
                        {
                            s = s->next ;
                        }
                        s->next = p->next ;
                        *head = p->next ;
                        s = p ;
                        p = p->next ;
                        *head = p ;

                        s->next = NULL ;

                        free(s);
                        s = NULL ;
                    }
                    else if(p->next == *head )
                    {
                        rr *s=p ;

                        while(s->next!=p)
                        {
                            s = s->next ;
                        }
                        p = s;
                        s = p->next ;
                        p->next = *head ;
                        s->next = NULL ;
                        free(s);
                        s = NULL ;
        
                    }
                    
                    else 
                    {
                        rr *s=p ;

                        while(p!=s->next)
                        {
                            s = s->next ;
                        }

                        s->next  = p->next ;
                        s = p ;
                        p=p->next ;
                        s->next = NULL ;

                        free(s);
                        s = NULL ;
                    }

                    
                }
                

            }
            else
            {
                p = p->next; 
            }

           
            
            

        }
    }
}

void display(rr* head)
{
    rr *p=head  ;

    if(head == NULL)
    {
        printf("the list is empty : ");
    }
    else
    {
        do
        {
            printf("process name : %s \n",p->PN);
            printf("process time : %d \n ", p->PT);
            p = p->next ;
        } while (p!=head);
        
    }
}

