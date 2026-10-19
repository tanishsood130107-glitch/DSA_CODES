#include <stdio.h>
#include <stdlib.h>

typedef struct queue
{
    int data ;
    struct queue *next ;
}s ;

s* enq(s*);
s* deq(s*, s*);
void display(s*,s*);

 
int main()
{
    s *rear = NULL , *front = NULL ;
    int ch ;
    
    do
    {
        printf("\n 1 : enqueue \n 2 : dequeue \n 3 : display \n :");
        scanf("%d",&ch);

        switch (ch)
        {
            case 1 :
                rear = enq(rear);
                if(front == NULL)
                {
                    front = rear ;
                }
                break ;
            case 2 :
                front = deq(front , rear );
                if(front == NULL)
                {
                    rear = NULL ;
                }
                break ;
            case 3 :
                display(front , rear);
                break ;
        }
    }while(ch<=3);

    return 0 ;
}

s *enq(s *rear)
{
    s* p=NULL;
    int v ;

    p = (s*)malloc(sizeof(s));

    if(p==NULL)
    {
        printf("enque operation cannot not take place ");
    }
    else
    {
        printf("enter the value you want to insert in the queue : ");
        scanf("%d",&v);
        p->data = v ;
        
        if(rear == NULL)
        {
            p->next = NULL;
            rear = p ;
        }
        else
        {
            rear->next = p;
            p->next = NULL;
            rear = p ;
        }

    }

    return rear ;
}

s *deq(s* front, s* rear)
{
    s *p = front;
    
    if(front == NULL )
    {
        printf("the queue is empty ");
    }
    else
    {
        printf("the deleted element is : %d",front->data);
        if(front == rear )
        {
            front = NULL;
        }
        else
        {
            front = front->next ;
        }
        free(p);
    }

    return front ;

    
}

void display(s *front , s *rear )
{
    if(front == NULL)
    {
        printf("the queue is empty ");
    }
    else
    {
        while(front!=NULL)
        {
            printf("%d \t",front->data);
            front = front->next ;
        }
    }
}