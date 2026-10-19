#include <stdio.h>
#include <stdlib.h>

typedef struct stack 
{
    int data ;
    struct stack *next ;
}s ;

s* push(s*);
s* pop(s*);
void display(s*);


int main()
{
    s* top = NULL ;
    int ch ;

    do
    {
        printf("\n 1 : push \n 2 : pop \n 3 : display ");
        scanf("%d",&ch);

        switch (ch)
        {
            case 1 :
                top = push(top);
                break ;
            case 2 :
                top = pop(top);
                break ;
            case 3 :
                display(top);
                break ;
        }

    }while(ch<=3);

    return 0 ;
}


s* push(s* top)
{
    s *p=NULL;
    p = (s*)malloc(sizeof(s));

    if(p==NULL)
    {
        printf("memory not allocated : ");
    }
    else
    {
        printf("enter the value you want to insert : ");
        scanf("%d",&(p->data));

        p->next = top ;
        top = p ;
    }

    return top ; 


}


s* pop(s* top)
{
    s* p = NULL ;

    if(top == NULL)
    {
        printf("the queue is empty : ");
    }
    else 
    {
        printf("the deleted element is : %d " , top->data);
        p = top ; 
        top = top->next ;
        free(p);
    }
    return top ;
}

void display(s* top)
{

    if(top==NULL)
    {
        printf("the queue is empty ");
    }
    else
    {
        while(top!=NULL)
        {
            printf("%d \t", top->data);
            top = top->next ;
        }
    }
}