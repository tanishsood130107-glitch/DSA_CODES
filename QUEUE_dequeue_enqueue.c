#include <stdio.h>
#define max 5 

int enqueue(int [],int , int);
int dequeue(int[], int , int);
void display(int[],int , int );
void peek(int[],int);

int main()
{
    int a[max] , front = -1 , rear=-1  , ch , i;

    do
    {
        printf("1:enqueue \n2 : dequeue \n3 : peek \n4 : display \n5:exit");
        scanf("%d",&ch);


        switch (ch)
        {
            case 1 :
            rear = enqueue(a,front,rear);

            if(rear>=0)
            {
                front = 0;
            }

            break ;

            case 2 :

            front = dequeue(a, front , rear);
            if(front==max)
            {
                front =-1;
                rear =-1;
            }

            break ;

            case 3 :
            display(a,front,rear);
            break;

            case 4:
            peek(a , front );
            break ;




        }
    }
    while(ch<5);


    for(i=front;i<rear;i++)
    {
        printf("%d \t",a[i]); 
    }

    return 0 ;


}


int enqueue(int a[], int front , int rear)
{
    int x ;
    if(rear==max-1)
    {
        printf("the queue is full");
    }
    else
    {
        printf("enter the number you want to enter in the queue : ");
        scanf("%d",&x);
        rear++;
        a[rear] = x ;
    }

    return rear ;
}

int dequeue(int a[] , int front , int rear)
{
    int x ;
    if(front==-1&&rear==-1)
    {
        printf("the queue is empty");
    }
    else
    {
        x = a[front];
        printf("the deleted element is %d : ", x);
        front++;
        
    }

    return front ;
}

void display(int a[], int front,int rear)
{
    int i =0;

    if(front==-1)
    {
        printf("the queue is empty ");
    }
    else 
    {

    for(i=front;i<=rear;i++)
    {
        printf("%d \t",a[i]);
    }
    }
}

void peek(int a[], int front)
{
    if(front==-1)
    {
        printf("the queue is empty : ");
    }
    else 
    {
        printf("%d",a[front]);
    }
}