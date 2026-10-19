#include <stdio.h>
#include <stdlib.h>

typedef struct circular_linked_list
{
    int data ;
    struct circular_linked_list * next ;
}cl;

cl *insert(cl*,cl*);
void display(cl*);


int main()
{
    cl *front = NULL , *last = NULL ;
    int ch ;

    do
    {
        printf("1 : insert \n 2 : display ");
        scanf("%d",&ch);

        switch (ch)
        {
            case 1 :
                last = insert(front, last);
                if(front==NULL)
                {
                    front = last ;
                }
                break ;
            case 2 :
                display(front);
                break;
        }

    }while(ch<=2);


    return 0 ;

}

cl *insert(cl *front , cl*last)
{
    cl *p = NULL ;
    int x ;
    p = (cl*)malloc(sizeof(cl));

    if(p==NULL)
    {
        printf("memory not allocated ");

    }
    else
    {
        printf("enter the value you want to insert : ");
        scanf("%d", &x);
        p->data = x ;

        if(front == NULL)
        {
            front =last =  p ;
            front->next = front ;
        }
        else
        {
            last->next = p ;
            p->next = front ;
            last = p ;
        }
    }

    return last ;
}


void display(cl * front )
{
    cl * p= front ;
    do{
        printf("%d \t",p->data);
        p = p->next;
    }while(p!=front);
    

}