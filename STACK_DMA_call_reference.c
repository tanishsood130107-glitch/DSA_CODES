#include <stdio.h>
#include <stdlib.h>

void push(int*, int* , int );
void pop(int* , int * , int );
void peek(int * , int );
void display(int * , int , int);

int main()
{
    int *p = NULL , top =-1 , ch , num ;

    printf("enter the size of the array : ");
    scanf("%d", &num);

    p = (int*)malloc(num*sizeof(int));

    if(p==NULL)
    {
        printf("memory not allocated : ");
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
                    push(p, &top , num);
                    break ;
                case 2 :
                    pop(p , &top, num);
                    break ;
                case 3 :
                    peek(p,top);
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

void push(int *p ,int  *top , int num  )
{
    int x ;

    if(*top==num-1)
    {
        printf("the queue is full : ");
    }
    else
    {
        printf("enter the element you want to insert in the stack : ");
        scanf("%d",&x);

       (*top)++;
       *(p+(*top)) = x; 
    }
}

void pop(int *p , int *top , int num )
{
    int x ;
    if(*top==-1)
    {
        printf("the queue is empty : ");
    }
    else 
    {
        printf("the deleted element is : %d ", *(p+(*top)));   
        (*top)--;
    }
}

void peek(int *p , int top)
{
    if(top==-1)
    {
        printf("the stack is empty : ");
    }
    else 
    {
        printf("%d", *(p+(top)));
    }
}

void display(int *p , int top, int num)
{
    if(top==-1)
    {
        printf("the stack is empty ");
    }
    else
    {
        while(top>=0)
        {
            printf("%d",*(p+top));
            top--;
        }
    }

}