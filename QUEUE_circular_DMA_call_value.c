#include <stdio.h>
#include <stdlib.h>

int enq(int * , int , int , int );
int deq(int * , int , int , int );
void peek(int * , int );
void display(int*, int , int , int );

int main()
{
    int front = -1 , rear  = -1 , num , ch , *p=NULL;

    printf("enter the size of the queue : ");
    scanf("%d",&num);

    p = (int*)malloc(num*sizeof(int));

    if(p==NULL)
    {
        printf("memory not allocated ");
    }
    else 
    {
        do
        {
            printf("\n 1: enqueue \n 2 : dequeue \n 3 : peek \n 4 : display \n 5 : exit ");
            scanf("%d",&ch);

            switch (ch)
            {
                case 1:
                    rear = enq(p,   front , rear , num);
                    if(front==-1)
                    {
                        front = 0 ;
                    }
                    break ;
                case 2 :
                    front = deq(p,front , rear, num);
                    if(front==-1)
                    {
                        rear = -1 ;
                    }
                    break ;
                case 3 :
                    peek(p,front);
                    break ;
                case 4 :
                    display(p,front , rear , num );
                    break ;
            }
            
        }while(ch!=5);
        
    }

    free(p);
    return 0 ;

}

int enq(int *p , int front , int rear , int num)
{
    int x ;
    if((rear+1)%num == front)
    {
        printf("the queue is full ");
    }
    else 
    {
        rear = (rear+1)%num ;
        printf("enter the number you want to insert : ");
        scanf("%d",&x);
        *(p+rear) = x ;
    }

    return rear ;
}

int deq(int *p , int front , int rear , int num )
{
    if(front ==-1 &&rear == -1)
    {
        printf("the queue is empty ");
    }
    else
    {
        printf("the deleted element is : %d ", *(p+front));
       
    }

    if(front==rear)
    {
        front = -1;
    }
    else
    {
        front = (front+1)%num ;
    }

    return front ;
}

void peek(int *p , int front )
{
    if(front ==-1)
    {
        printf("the queue is empty ");
    }
    else
    {
        printf("%d",*(p+front));
    }
}

void display(int * p , int front , int rear , int num)
{
    if(front ==-1 && rear ==-1 )
    {
        printf("the queue is empty : ");
    }
    else
    {
        while(front!=rear)
        {
            printf("%d",*(p+front));
            front = (front+1)%num ;
        }
        printf("%d",*(p+front));

    }
}