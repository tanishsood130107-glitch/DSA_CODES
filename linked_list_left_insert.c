#include <stdio.h>
#include <stdlib.h>

typedef struct list
{
    int data  ;
    struct list *next ;
}sl;

int main()
{
    sl *p=NULL , *left = NULL ;
    int ch , v , count =0;

    while(1)
    {
        printf("do you want to insert node (1/0)");
        scanf("%d",&ch);

        if(ch==0)
        {
            break;
        }

        p = (sl*)malloc(sizeof(sl));
        printf("enter the value you want to insert at the node : ");
        scanf("%d",&v);
        p->data = v ;
        p->next = left ;
        left = p ;
    }

    p = left ;

    while(p!=NULL)
    {
        printf("%d \t",p->data);
        p = p->next ;
    }

    p = left ;
    while(p!=NULL)
    {
        p = p->next ;
        count ++ ;        
    }

    printf("\n the number of nodes are : %d ", count );


    return 0 ;


}