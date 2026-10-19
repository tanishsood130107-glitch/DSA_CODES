#include <stdio.h>
#include <stdlib.h>

typedef struct list 
{
    int data ;
    struct list *next ;
}sl ;

sl* insert(sl*);
sl* insert_user_node(sl* , sl**);
int count(sl*);
void display(sl*);

int main()
{
    sl* ptr = NULL , *right = NULL ;
    int ch , c ;

    do
    {
        printf("\n 1: normal insert \n 2 : insert at particular node entered by the user \n 3 : count \n 4 :display ");
        scanf("%d",&ch);

        switch (ch)
        {
            case 1 : 
                right = insert(right);
                if(ptr==NULL)
                {
                    ptr=right ;
                }
                break ;
            case 2 :
                ptr = insert_user_node(ptr,&right);
                break ;
            case 3 :
                c = count(ptr);
                printf("the total number of nodes are  : %d ", c);
                break ;
            case 4 :
                display(ptr);
                break ;
        }
    }while(ch<=4);

    return 0 ;
    
}

sl* insert(sl *right)
{
    sl *p=NULL ;

    p = (sl*)malloc(sizeof(sl));

    if(p==NULL)
    {
        printf("memory not allocated ");
    }
    else
    {
        printf("enter the value you want to insert : ");
        scanf("%d",&(p->data));
        if(right==NULL)
        {
            right = p ;
            p->next = NULL;
        }
        else
        {
            right->next = p ;
            p->next = NULL;
            right = p ;
        }
    }
    return right ;
}

sl* insert_user_node(sl *ptr , sl **right)
{
    sl *p = NULL ,*t = ptr ;
    int Total_node , node  , i = 1 ;

    Total_node = count(ptr);
    
    printf("enter the node where you want to insert the value : ");
    scanf("%d",&node);

    printf("%d %d" , Total_node , node);


    if(node<=(Total_node +1)&&node>0)
    {
        p = (sl*)malloc(sizeof(sl));
        printf("enter the element you want to insert at the node : ");
        scanf("%d",&(p->data));

        if(node>1&&node<=Total_node)
        {
            while(i<node-1)
            {
                t = t->next ;
                i++;
            }

            p->next = t->next ;
            t->next = p ;
        }
        else if(node == Total_node+1)
        {
            while(t->next!=NULL)
            {
                t = t->next ;
            }

            t->next = p ;
            p->next = NULL ;

            *right = p ;
        }
        else if(node == 1)
        {
            p->next = t ;
            ptr  = p ;

        }

        

    }
    else
    {
        printf("out of range");
    }

    return ptr ;
}

int count(sl * ptr)
{
    int c =0 ;

    while(ptr!=NULL)
    {
        c++;
        ptr=ptr->next;
    }

    return c ;
}

void display(sl* ptr)
{
    while(ptr!=NULL)
    {
        printf("%d \t",ptr->data);
        ptr = ptr->next ;

    }
}