#include <stdio.h>
#include <stdlib.h>

int push(int*,int , int );
int pop(int *, int , int );
void peek(int*,int, int );
void display(int* , int , int );


int main()
{
    int *p=NULL , num , ch , top =-1;

    printf("enter the number of elements you want : ");
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
            printf("\n 1 : push \n 2 : pop \n 3 : peek \n 4 : display \n 5 : exit ");
            scanf("%d",&ch);

            switch (ch)
            {
                case 1:
                    top = push(p, top , num);
                    break ;
                case 2 :
                    top = pop(p , top, num);
                    break ;
                case 3 :
                    peek(p,top, num);
                    break ;
                case 4 :
                    display(p,top, num);
                    break ;


            }
           
        } while(ch!=5);

        
    }
    free(p);

    return 0 ;
}

int push(int *p , int top, int num )
{
    int x ;
    if(top==num -1 )
    {
        printf("the queue is full : ");
    }
    else 
    {
        printf("enter the element you want to insert : ");
        scanf("%d",&x);

        top++;
        *(p+top) = x;

    }

    return top ;
}

int pop(int *p , int top , int num )
{
    int x ;
    if(top==-1)
    {
        printf("the stack is empty : ");
    }
    else 
    {
        printf("the deleted element is : %d  ", *(p+top));

        top--;

    }
    return top ;
}


void peek(int *p , int top , int num)
{
    if(top==-1)
    {
        printf("the stack is empty ");
    }
    else 
    {
        printf("\n%d",*(p+top));
    }
}

void display(int *p , int top , int num)
{
    int i = 0 ;
    if(top==-1)
    {
        printf("the stack is empty : ");
    }
    else
    {
        while (i<=top)
        {
            printf("%d \t",*(p+i));
            i++;
        }
        
    }
}