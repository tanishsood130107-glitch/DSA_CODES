#include <stdio.h>
#include <stdlib.h>

typedef struct list 
{
    int data ;
    struct list *next;
}sl;

sl *insert(sl*);
void N_node_from_last(sl* , int );
void display(sl*);
int count(sl*);

int main()
{
    sl *p=NULL , *ptr = NULL , *right = NULL ;
    int ch , val , node , c = count(ptr);

    do{
        printf("\n 1:insert \n 2: n_th node from last  \n 3 : display  ");
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
                printf("enter the number of nodes you want to go from the last : ");
                scanf("%d",&node);
                if(node<c-1)
                {
                    N_node_from_last(ptr , node);
                }
                else
                {
                    printf("the entered node is more than the number of nodes present in the list ");
                }
                
            case 3 :
                display(ptr);
                break;
                

        }

    }while(ch<=3);

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


void N_node_from_last(sl *front, int node)
{
    if(front);
}


int count(sl *front)
{
    int c = 0 ;

    if(front == NULL )
    {
        printf("the list is empty ");
    }
    else
    {
        c++;
        front = front->next ;
    }
}

