#include <stdio.h>
#define max 2

void  enqueue(int [] , int* ,int* );
void dequeue(int [] , int* , int* );
void display(int[],int,int);
void peek(int [] , int );


int main()
{
    int ch , front = -1 , rear =-1 , a[max];

    do
    {
        printf("1:enqueue \n2 : dequeue \n3 : display \n4 : peek \n5:exit");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1 :
                enqueue(a,&front,&rear);
                break;
            case 2 :
                dequeue(a,&front,&rear);
                break;
            case 3 :
                display(a,front,rear);
                break ;
            case 4 : 
                peek(a,front);
                break ;
        }
    }
    while(ch!=5);


    return 0 ;

    
}

void enqueue(int a[] ,int *front, int *rear)
{
    int x ;

    if(*rear== max-1)
    {
        printf("the queue is full ");
    }
    else 
    {
        printf("enter the value you insert : ");
        scanf("%d",&x);

        (*rear) ++;

        a[*rear] = x ;

    }

    if((*rear)>=0)
    {
        *front = 0 ;
    }
}

void dequeue(int a[] , int *front , int *rear )
{
    int x ;
    if((*front)==-1)
    {
        printf("the queue is empty ");
    }
    else
    {
        x = a[(*front)];
        *front++;
        printf("the deleted element is %d ", x);

        if(*front == max)
        {
            *front == -1;
            *rear == -1 ;
        }

    }
}

void display(int a[], int front , int rear)
{
    int i;
    if(front==-1&&rear==-1)
    {
        printf("the queue is empty  ");
    }
    else 
    {
        for(i=front;i<=rear;i++)
        {
            printf("%d \t",a[i]);
        }
    }
}

void peek(int a[], int front )
{
    if(front==-1)
    {
        printf("the queue is empty ");
    }
    else
    {
        printf("%d",a[front]);
    }
}