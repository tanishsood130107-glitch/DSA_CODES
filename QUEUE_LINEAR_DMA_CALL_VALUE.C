#include <stdio.h>
#include <stdlib.h>

int enq(int * , int , int , int );
int deq(int * , int , int , int);
void peek(int * , int );
void display(int * , int , int );

int main()
{
    int *p=NULL , front = -1 , rear = -1 , num , ch ;

    printf("enter the number of elements is the queue : ");
    scanf("%d",&num);

    p = (int*)malloc(num*sizeof(int));

    if(p==NULL) 
    {
        printf("the memory is not allocated ");
    }
    else
    {
        do
        {
            printf("\n 1: enqueue \n 2 : dequeue \n 3 : peek \n 4 : display \n 5 : exit ");
            scanf("%d",&ch);

            switch (ch)
            {
                case 1 :
                    rear = enq(p, front , rear, num);
                    if(front ==-1)
                    {
                        front = 0 ;
                    }
                    break ;
                case 2 :
                    front = deq(p , front , rear , num );
                    if(front == -1 )
                    {
                        rear = -1 ;
                    }
                    break ;
                case 3 :
                    peek(p , front );
                    break ;
                case 4 : 
                    display(p , front , rear );
                    break ;
            }
        }while(ch!=5);
        
        
        free(p);
        return 0 ;

    }
}

int enq(int *p , int front , int rear , int num)
{
    int x ;
    if(rear == num -1  )
    {
        printf("the queue is full");
    }
    else
    {
        printf("enter the element you want to enqueue : ");
        scanf("%d",&x);

        rear++ ;
        *(p+rear) = x ;
    }
    return rear ;
}

int deq(int *p , int front , int rear , int num)
{
    if(front==-1)
    {
        printf("the queue is empty ");
    }
    else 
    {
        printf("the deleted element is : %d ", *(p+front));
        front++ ;

        if(rear == front-1 )
        {
            front = -1;
        }
    }
    return front ; 
    
}

void peek(int *p , int front )
{
    if(front == -1)
    {
        printf("the queue is empty : ");
    }
    else
    {
        printf("%d", *(p+front));
    }
}

void display(int *p, int front , int rear)
{
    if(front == -1)
    {
        printf("the queue is empty : ");
    }
    else 
    {
        while(front<=rear)
        {
            printf("%d \t", *(p+front));
            front ++ ;
        }
    }

}