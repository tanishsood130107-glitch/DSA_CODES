#include <stdio.h>
#include <stdlib.h>

typedef struct list 
{
    int data ;
    struct list *next;
}sl;

sl *insert(sl*);
void  middle(sl*);
void display(sl*);
int count(sl*);


int main()
{
    sl *p=NULL , *ptr = NULL , *right = NULL ;
    int ch , val;

    do{
        printf("\n 1:insert \n 2: middle  \n 3 : display  ");
        scanf("%d",&ch);

        switch (ch)
        {
            case 1 :
                right = insert(right);
                if(ptr==NULL)
                {
                    ptr = right ;
                }
                break ;
            case 2 :
                middle(ptr);
                break ;
            case 3 :
                display(ptr);
                break;
                

        }

    }while(ch<=4);

    return 0 ;
}

sl *insert(sl *right)
{
    sl *p=NULL;

    p =(sl*)malloc(sizeof(sl));

    if(p==NULL)
    {
        printf("memory not allocated ");
    }
    else
    {
        printf("enter the value you want to insert in the list : ");
        scanf("%d",&(p->data));

        if(right==NULL)
        {
            right = p ;
        }
        else
        {
            right->next = p;
            right = p ;
        }

        right->next = NULL;
    }

    return right ;
}


void display(sl *ptr)
{
    while(ptr!=NULL)
    {
        printf("%d \t",ptr->data);
        ptr = ptr->next ;
    }
}


void middle(sl  *front)
{
    
    sl *one=front , *two = front ;
    if(front == NULL)
    {
        printf("the list is empty : ");
    }
    else
    {
        while(two!=NULL&&two->next!=NULL)
        {
            one = one->next ;
            two = two->next ;
            two = two->next ;

        }
        
        
            printf("the value of middle node is  : %d" , one->data);
    }
}

int count(sl* front)
{
    int c =0 ;
    if(front ==NULL)
    {
        printf("the list is empty : ");
    }
    else
    {
        while(front!=NULL)
        {
            c++;
            front=front->next ;
        }
    }
    return c ;
}