#include <stdio.h>
#include <stdlib.h>

typedef struct polynomial
{
    int expo , coeff ;
    struct polynomial *next ;
}poly ;

poly* add(poly*,poly*);
poly* create();
void display(poly*);


int main()
{
    poly *f1 = NULL , *f2 = NULL , *f3 = NULL ;
    
    printf(" enter first polynomial \n");
    f1 = create();
    display(f1);
    printf(" enter second polynomial \n");
    f2 = create();
    display(f2);

    printf(" adding two polynomial \n");
    f3 = add(f1 , f2);
    display(f3);

    return 0 ;

}

poly* create()
{
    poly *p = NULL , *L =NULL , *R = NULL ;
    int ch ;
    while(1)
    {
        p = (poly*)malloc(sizeof(poly));
        if(p==NULL)
        {
            printf("not enough memory");
        }
        else
        {
            printf("enter the power of x and its coefficent \n");
            scanf("%d %d",&(p->expo),&(p->coeff));

            if(L==NULL&&R==NULL)
            {
                L=R=p;
            }
            else
            {
                R->next = p;
                R = p ;
            }

            R->next = NULL ;

            printf("do you want to enter more values to the polynomial (1:yes/0:no) ");
            scanf("%d",&ch);

            if(ch==0)
            {
                break ;
            }
        }
    }

    return L ;
    
}

void display(poly *F)
{
    if(F==NULL)
    {
        printf("the list is empty ");
    }
    else
    {
        while(F!=NULL)
        {
            if(F->next==NULL)
            {
                printf("%dx^%d ",F->coeff,F->expo);

            }
            else
            {
                
                printf("%dx^%d +",F->coeff,F->expo);

            }

            F = F->next ;
        }
    }
}

poly* add(poly*f1 , poly*f2)
{
    poly *p=NULL , *L = NULL , *R = NULL ;

    while(f1!=NULL&&f2!=NULL)
    {
        p = (poly*)malloc(sizeof(poly));

        if(p==NULL)
        {
            printf("not enough memory ");
        }
        else
        {
            if(f1->expo==f2->expo)
            {
                p->expo = f1->expo;
                p->coeff = f1->coeff+f2->coeff ;

                f1 = f1->next ;
                f2 = f2->next ;
            }
            else if(f1->expo > f2->expo)
            {
                p->expo = f1->expo ;
                p->coeff = f1->coeff;

                f1 = f1->next ;
            }
            else if(f2->expo > f1->expo)
            {
                p->expo = f2->expo ;
                p->coeff = f2->coeff ;

                f2 = f2->next ;
            }


            if(L==NULL && R==NULL)
            {
                L=R=p;
            }
            else
            {
                R->next = p ;
                R = p;
            }

            // R->next = NULL ;
        }
    }
    
 
    if(f2==NULL&& f1 == NULL)
    {
        R->next == NULL;
    }
    else if(f1!=NULL)
    {
        R->next = f1 ;
    }
    else if(f2!=NULL)
    {
        R->next = f2 ;
    }


    return L ;
}