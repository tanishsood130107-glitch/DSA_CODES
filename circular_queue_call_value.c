#include <stdio.h>
#define max 5
int enqueue(int a[], int , int );
int dequeue(int a[], int , int );
void peek(int a[],int, int);
void display(int a[] , int , int );

int main()
{
    int cq[max] , ch , front =-1 , rear = -1;

    do
    {
        printf("\n1 : enqueue \n2 : dequeue \n3 : peek \n4 : displace \n5 : exit \n:");
        scanf("%d",&ch);

        switch (ch)
        {
            case 1 :
            rear = enqueue(cq,front , rear);
            if(front==-1)
            {
                front = 0;
            }
            break ;

            case 2 :
            front = dequeue(cq,front , rear);
            if(front==-1)
            {
                rear=-1;
            }
            // else
            // {
            //     rear = (rear+1)%max;
            // }
            break ;

            case 3 :
            peek(cq,front, rear);
            break ;

            case 4 :
            display(cq , front , rear);
            break ;
        }
    }
    while(ch!=5);

    return 0 ;
}

int enqueue(int cq[], int f , int r)
{
    if((r+1)%max == f)
    {
        printf("the queue is full");
    }
    else 
    {
        r = (r+1)%max ;
        printf("enter the value you want to insert in the queue : ");
        scanf("%d",&cq[r]);
       
    }
    return r ;

}


int dequeue(int cq[],int f , int r )
{
    int x ;
    if(f==-1&&r==-1)
    {
        printf("the queue is empty ");
    }
    else
    {
        x = cq[f];
        printf("the deleted value from the array is %d " , x);
        
        if(f==r)
        {
            f =-1;
        }
        else
        {
            f = (f+1)%max ;
        }
    }
    return f ;
}



void display(int cq[],int f , int r )
{
    if(f==-1&&r==-1)
    {
        printf("the queue is empty ");
    }
    else
    {
        while(f!=r)
        {
            printf("%d ",cq[f]);
            f = (f+1)%max ;
        }
        printf("%d",cq[f]);
    }
}

void peek(int cq [],int f ,int r)
{
    if(f==-1&&r==-1)
    {
        printf("the queue is empty ");
    }
    else
    {
        printf("%d",cq[f]);
    }
}