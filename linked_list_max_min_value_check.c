#include <stdio.h>
#include <stdlib.h>


typedef struct list 
{
    int data ;
    struct list *next ;
}sl ;

sl* insert(sl*);
void display(sl*);
void max(sl*);
void min(sl*);



int main()
{
    sl *front = NULL , *last = NULL;
    int ch ;

    do
    {
        printf("\n 1 : insert \n 2 : max \n 3 : min \n 4 : disaply \n");
        scanf("%d",&ch);


        switch (ch)
        {
            case 1 :
                last = insert(last);
                if(front==NULL)
                {
                    front = last;
                }
                break ;
            case 2 :
                max(front);
                break ;
            case 3 :
                min(front);
                break ;
            case 4 :
                display(front);
                break ;
        }  
    }while(ch<=4);

    return 0 ;
}

sl *insert(sl* last)
{
    sl* p=NULL ;

    p = (sl*)malloc(sizeof(sl));

    if(p==NULL)
    {
        printf("not enough memory : ");
    }
    else
    {
        printf("enter the value you want to insert : ");
        scanf("%d",&(p->data));

        p->next = NULL;
        if(last == NULL)
        {
            last = p ;
        }
        else 
        {
            last->next = p ;
            last = p ;
        }
    }

    return last ;
}


void max(sl* front)
{
    
    if(front==NULL)
    {
        printf("the list is empty ");
    }
    else
    {

        sl *p=front->next  ;
        int max = front->data ;

        if(p!=NULL)
        {
            while(p!=NULL)
            {
                if((p->data)>max)
                {
                    max = p->data ;
                }

                p = p->next ;
            }

        }
        printf("the maximum element of the list is : %d ", max );
    }

    
}

void min(sl*front)
{
    

    if(front==NULL)
    {
        printf("the list is empty : ");
    }
    else
    {

        sl *p = front->next ;
        int min = front->data ;
        if(p!=NULL)
        {
            while(p!=NULL)
            {
                if((p->data)<min)
                {
                    min = p->data ;
                }
                p = p->next ;
            }

        }

        printf("the mainmun  element of the linked list is  : %d  ", min );

    }
}

void display(sl*front)
{
    if(front == NULL)
    {
        printf("the queue is empty ");
    }
    else
    {
        while(front!=NULL)
        {
            printf("%d \t ", front->data);
            front = front->next ;
        }
    }
}