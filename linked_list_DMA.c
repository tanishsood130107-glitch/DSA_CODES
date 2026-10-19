#include <stdio.h>
#include <stdlib.h>

typedef struct list 
{
    int data ;
    struct list *next;
}sl;

void display( sl * );
int  count( sl *);


int main()
{
    struct list *p = NULL, *left = NULL , * right =NULL;
    int ch ,  c;

    while(1)
    {
        printf("do you want to insert a node (0/1) : ");
        scanf("%d",&ch);

        if(ch==0)
        {
            right->next =NULL;
            break;

        }
        else
        {
            p = (sl*)malloc(sizeof(sl));
            if(p!=NULL)
            {
                printf("enter the data you want to enter in that node : ");
                scanf("%d", &p->data);
                if(left==NULL&&right==NULL)
                {
                    left = right = p ;
                }
                else
                {
                    right->next = p ;
                    right = p ;
                }
            
            }
        }
    }
    display(left);

    c = count(left);

    printf("the number of nodes are : %d", c);
    return 0 ;
}


void display(sl *left )
{
    sl *p;
    p  = left ;


    if(left == NULL)
    {
        printf("there are no node in the linked list");
    }
    else
    {
        while(p!=NULL)
        {
            printf("%d \t ", p->data);
            p = p->next ;
        }

    }
}

int  count(sl *left)
{
    sl * p= left;
    int c = 0 ;

    if(left == NULL)
    {
        printf("there are no nodes in this linked list : ");
    }
    else
    {
        while(p!=NULL)
        {
            c ++ ;
            p = p->next ;
        }
    }

    return c ;
    

}