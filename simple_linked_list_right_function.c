#include <stdio.h>

typedef struct list
{
    int data ;
    struct list * next ;
}sl;

sl *insert(sl*);
void display(sl*);
void count(sl*);

int main()
{
    sl  *left = NULL , *right = NULL ;
    int ch ;

    do
    {
        printf("\n 1:insert \n 2 : display \n 3 : count \n 4 : exit");
        scanf("%d",&ch);

        switch (ch)
        {
            case 1 :
                right = insert(right);
                if(left==NULL)
                {
                    left = right;
                }
                break ;
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

sl *insert(sl* right)
{
    sl *p=NULL ;
    int v ;

    p = (sl*)malloc(sizeof(sl));


    if(p!=NULL)
    {
    printf("enter the value at the node : ");
    scanf("%d",&v);
    p->data = v;
    
    if(right==NULL)
    {
        right = p ;
    }

    else
    {
        right->next = p ;
        right = p ;
    }

    right->next = NULL ;
    
    }
    return right ;
}

void display(sl* left )
{
    sl *p = left ; 

    while(p!=NULL)
    {
        printf("%d \t",p->data);
        p = p->next ;
    }
}

void count(sl *left)
{
    sl *p=left ;
    int c = 0 ;

    while(p!=NULL)
    {
        c++;
        p = p->next   ;
        
    }

    printf("the number of nodes in the linked list is : %d ", c);
}