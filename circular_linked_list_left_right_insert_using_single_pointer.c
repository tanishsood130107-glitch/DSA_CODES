#include <stdio.h>
#include <stdlib.h>


typedef struct circular_list 
{
    int data ;
    struct circular_list *next ;
}cl;


cl *insert_left(cl*);
cl *insert_right(cl*);
void display(cl*);

int main()
{
    cl *head = NULL ;
    int ch ;

    do
    {
        printf("\n 1 : insert at left \n 2 : insert at right \n 3 : display \n ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1 :
                head = insert_left(head);
                break ;
            case 2 :
                head = insert_right(head);
                break ;
            case 3 :
                display(head);
                break ;
        }
    }while(ch<=3);
    
    return 0 ;
}

cl *insert_left(cl *head )
{
    cl *p=NULL ;

    p =(cl*)malloc(sizeof(cl));

    if(p==NULL)
    {
        printf("not enough memory ");
    }
    else
    {
        printf("enter the data you want to insert in list : ");
        scanf("%d",&(p->data));

        if(head==NULL)
        {
            head = p ;
            head->next  = p ;
        }
        else
        {
            p->next = head->next ;
            head->next = p;

        }
        
    }

    return head ;
}


cl *insert_right(cl *head)
{
    cl* p = NULL ;

    p = (cl*)malloc(sizeof(cl));

    if(p==NULL)
    {
        printf("the list is empty ");
    }
    else
    {
        printf("enter the value you want to insert : ");
        scanf("%d",&(p->data));
        if(head==NULL)
        {

            head = p ;
            head->next = p ;
        }
        else
        {
            p->next = head->next ;
            head->next = p;
            head = p ;
        }
    }

    return head ; 
}

void display(cl *head)
{
    cl *p = head->next ;
    if(head == NULL)
    {
        printf("the list is empty : ");
    }
    else
    {
        do
        {
            printf("%d \t",p->data);
            p = p->next ;
        } while (p != head->next  );
        
    }

}