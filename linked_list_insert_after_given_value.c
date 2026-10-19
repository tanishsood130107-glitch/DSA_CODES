#include <stdio.h>
#include <stdlib.h>

typedef struct list 
{
    int data ;
    struct list *next;
}sl;

sl *insert(sl*);
void insert_aft_val(sl*,int);
sl *insert_bef_val(sl* , int );
void display(sl*);


int main()
{
    sl *p=NULL , *ptr = NULL , *right = NULL ;
    int ch , val;

    do{
        printf("\n 1:insert \n 2: insert_after_particular_value \n 3 : insert before a given value \n 4 : display  ");
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
                printf("enter the value after which you want to insert the value in the list : ");
                scanf("%d",&val);
                insert_aft_val(ptr,val);
                break ;
            case 3 :
                printf("enter the value after which you want to insert the value in the list : ");
                scanf("%d",&val);

                ptr = insert_bef_val(ptr , val);
                break ;
                
            case 4 :
                display(ptr);
                break;
                

        }

    }while(ch<=4);

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

void insert_aft_val(sl*ptr , int val)
{
    sl *p=NULL ,*t=ptr;
    int c = 0 , found = 0 , v ;

    while(t!=NULL)
    {
        c++;
        if(t->data==val)
        {
            found=1;
            break;
        }
        t = t->next ;  
    }

    if(found==0)
    { 
        printf("no such value is present in the list : ");
    }
    else
    {
        p = (sl*)malloc(sizeof(sl));

        if(p==NULL)
        {
            printf("memory not alloacted : ");
        }
        else
        {
            printf("enter the value you want to insert : ");
            scanf("%d",&v);

            p->data = v;

            if(t->next==NULL)
            {
                t->next = p ;
                p->next = NULL ;
            }
            else
            {
                p->next = t->next ;
                t->next = p ;
            }
        }
    }
}


sl * insert_bef_val(sl* ptr , int val)
{
    sl* p=NULL , *t=ptr , *s = ptr;
    int found = 0   , c =0 , i;

    while(t!=NULL)
    {
        c++ ;
        if(val == t->data)
        {
            found = 1 ;
            break ;
        }

        t = t->next ;
    }

    if(found == 0)
    {
        printf("no such value is present in the list ");
    }
    else
    {
        p = (sl*)malloc(sizeof(sl));

        if(p==NULL)
        {
            printf("not enough memory : ");
        }
        else
        {   
            printf("enter the value you want to insert in list : ");
            scanf("%d",&(p->data));
            if(t==ptr)     //shows first node 
            {
                p->next = ptr ;
                ptr = p ;
            }
            else
            {
                i = 1;
                while(i<c-1)
                {
                    s = s->next ;
                    i++;
                }

                s->next = p ;
                p->next = t ; 
            }
        }
    }

    return ptr ;
}
