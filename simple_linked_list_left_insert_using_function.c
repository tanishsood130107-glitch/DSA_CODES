#include <stdio.h>
#include <stdlib.h>

typedef struct list 
{
    int data ;
    struct list *next ;
}sl;

sl *insert(sl*);
void display(sl*);
void count(sl*);

int main()
{
    sl *left = NULL ;
    int ch ;

    do
    {
        printf("\n1:insert \n , 2:display \n 3 : count \n 4 : exit ");
        scanf("%d",&ch);

        switch (ch)
        {
            case 1 :
                left = insert(left);
                break;
            case 2 :
                display(left);
                break ;
            case 3 :
                count(left);
                break ;

        }
    }while(ch<=3);
    return 0 ;

}

sl *insert(sl *left)
{
    sl *p=NULL;
    int ch , v;

    
        p = (sl*)malloc(sizeof(sl));
        printf("enter the value you want to insert at this node : ");
        scanf("%d",&v);
        p->data = v;
        p->next = left;
        left = p ;

    
    return left ;
}

void display(sl *left)
{
    sl *p=left ;
    while(p!=NULL)
    {
        printf("%d\t",p->data);
        p = p->next ;
    }
}

void count(sl *left)
{
    sl *p=left;
    int c =0 ;
    while(p!=NULL)
    {
        c++;
        p = p->next ;
        
    }

    printf("the total number of nodes are :  %d ", c);
}

