#include <stdio.h>
#include <stdlib.h>
# define max_node 4 

struct node
{
    int data ;
    struct node *next;
};

struct list
{
    struct node *head ;
};

struct list *addlist[max_node] ;

void AddNode(int  , int );
void printlist();


int main()
{
    int i = 0 ;

    for(i=0;i<max_node;i++)
    {
        addlist[i] = (struct list*)malloc(sizeof(struct list));
        addlist[i]->head = NULL ;
    }

    AddNode(0, 1);
    AddNode(0, 2);
    AddNode(0, 3);

    AddNode(1, 0);
    AddNode(1, 2);
    AddNode(1, 3);

    AddNode(2, 3);
    AddNode(2, 0);
    AddNode(2, 1);

    AddNode(3, 1);
    AddNode(3, 2);
    AddNode(3, 0);


    printlist();

    return 0 ;
}

void AddNode(int s , int d)
{
    struct node *src = NULL , *dest = NULL , *temp = NULL ;

    if(addlist[s]->head == NULL)
    {
        src = (struct node*)malloc(sizeof(struct node));
        src->data = d ;
        src->next = NULL ;
        addlist[s]->head = src;
    }
    else
    {
        dest = (struct node*)malloc(sizeof(struct node));
        dest->data = d;
        dest->next = NULL;

        temp = addlist[s]->head ;

        while(temp->next !=NULL)
        {
            temp = temp->next ;
        }

        temp->next = dest ;
    }

}


void printlist()
{
    int i ;
    struct node *p = NULL ;

    for(i=0;i<max_node;i++)
    {
        p = addlist[i]->head;

        printf("\n adjucency list for %d ",i);

        while(p!=NULL)
        {
            printf(" -> %d", p->data);
            p = p->next;
        }

        printf(" -> NULL\n");
    }
}