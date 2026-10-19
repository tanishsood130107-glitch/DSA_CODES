#include <stdio.h>
#include <stdlib.h>

typedef struct list 
{
    int data ;
    struct list *next ;
}sl;

sl* insert(sl*);
void display(sl*);
sl* reverse(sl*, sl**);
int count(sl*);

int main()
{
    sl *ptr = NULL , *right = NULL ;
    int ch ;

    do
    {
        printf("1 : insert \n 2 : reverse \n 3 : reverse \n");
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
                ptr = reverse(ptr, &right);
                break ;
            case 3 :
                display(ptr);
                break ;
        }
    }while(ch<=3);

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

        p->next = NULL ;

        if(right==NULL)
        {
            right = p ;
        }
        else
        {
            right->next = p ;
            right = p ;
        }

    }
}

void display(sl* ptr)
{
    while(ptr!=NULL)
    {
        printf("%d \t", ptr->data);
        ptr = ptr->next ;
    }
}
  
int count(sl* ptr)
{
    int c = 0 ;
    while(ptr!=NULL)
    {
        c++;
        ptr = ptr->next ;

    }
    return c ;
}

sl* reverse(sl* ptr , sl **right)
{
    sl *p=NULL , *t=NULL ,*left = NULL ;
    int c , i = 1 , c1;
    
    c = count(ptr);

    while(i<c)
    {
        sl *t=ptr , *p = ptr ;
        c1 = 0 ;
        c1 = count(ptr);
        int i1= 1;
        if(c1>1)
        {
            while(i1<c1-1)
            {
                t = t->next ;
                i1++;
            }
            p = t->next ;
            
            if(left == NULL)
            {
                left = p ;
            }

           
            p->next = t ;
            t->next = NULL;
            i++;
        }
        

        *right = t ;
    }


    return left ;


}