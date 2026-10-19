#include <stdio.h>
#define max 10 

void enqueue(int [],int*,int*);
void dequeue(int [] , int* , int * );

int main()
{
    int cq[max] , front = -1 , rear = -1 , ch ;
    do
    {
        printf("\n1 : enqueue \n2 : dequeue \n3 : peek \n4 : displace \n5 : exit \n:");
        scanf("%d",&ch);

        switch (ch)
        {
            case 1 :
            enqueue(cq,&front , &rear);
            break ;

            case 2 :
            dequeue(cq,&front , &rear);        
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


