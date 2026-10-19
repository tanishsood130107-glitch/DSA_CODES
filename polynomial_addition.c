#include <stdio.h>
#include <stdlib.h>

typedef struct simple_list
{
    int expo , coff ;
    struct simple_list *next ;

}sl ;


void create(sl**);
void display(sl*);
void poly_add(sl** , sl* , sl*);


int main()
{
    sl *poly_1 = NULL , *poly_2 = NULL , *poly_3 = NULL ;
    int ch ;

    do
    {
        printf("\n enter your choice \n 1 : create first  polynomial \n 2 : create second polynomial \n 3 : polynomial addition \n 4 : display first polynomial \n 5 : display second polynomial \n 6 : display the added polynomial \n enter your choice : ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1 :
                create(&poly_1);
                break ;
            case 2 :
                create(&poly_2);
                break ;
            case 3 :
                poly_add(&poly_3,poly_1,poly_2);
                break ;
            case 4 :
                display(poly_1);
                break ;
            case 5 :
                display(poly_2);
                break ;
            case 6 : 
                display(poly_3);
                break ;

    
        }

    }while(ch<=6);

    return 0 ;
}


void create(sl**head)
{
    sl *p = NULL , *r = NULL;
    int ch ;
    if(*head == NULL)
    {
        while(1)
        {
            p = (sl*)malloc(sizeof(sl));

            if(p==NULL)
            {
                printf("memory not allocated : ");
            }
            else
            {
                printf("enter the power of x : ");
                scanf("%d",&(p->expo));
                printf("enter the coefficient of x^(%d) : ",p->expo);
                scanf("%d",&(p->coff));

                if((*head)==NULL)
                {
                    *head = r = p ;
                }
                else
                {
                    r->next = p;
                    r = p ;
                }
                r->next = NULL ;

                printf("do you insert more nodes(0/1) : ");
                scanf("%d",&ch);

                if(ch==0)
                {
                    break ;
                }
            }
        }
    }
    else
    {
        printf("list is already created : ");
    }
}


void display(sl*head)
{
    if(head == NULL)
    {
        printf("The list is empty : ");
    }
    else
    {
        while(head->next!= NULL)
        {
            printf("%d^%d +\t",head->coff,head->expo);
            head = head->next ;
        }
        printf("%dX^%d \t",head->coff,head->expo);
    }
}

void poly_add(sl **head3 , sl* head1 , sl *head2)
{
    sl *p = NULL , *r = NULL , *s;
    if((head1==NULL)&&(head2==NULL))
    {
        printf("both the lists are empty : ");
    }
    else
    {
        while(head1!=NULL&&head2!=NULL)
        {
            p = (sl*)malloc(sizeof(sl));

            if(p==NULL)
            {
                printf("memory not allocated : ");
            }
            else
            {
                if((head1->expo)>(head2->expo))
                {
                    p->expo = head1->expo ;
                    p->coff = head1->coff;

                    head1 = head1->next ;
                }
                else if((head1->expo)<(head2->expo))
                {   p->expo = head2->expo ;
                    p->coff = head2->coff ;

                    head2 = head2->next ; 
                }
                else if (head1->expo == head2->expo)
                {
                    p->coff = head1->coff + head2->coff ;
                    p->expo = head1->expo ;

                    head1 = head1->next ;
                    head2 = head2->next ;
                }

                if(*head3 == NULL)
                {
                    *head3 = r = p ;
                }
                else
                {
                    r->next = p ;
                    r = p ;
                }

                r->next = NULL ;


            }

        }

        if(head1!=NULL&&head2==NULL)
        {
            r->next = head1 ;
        }
        else if(head1==NULL &&head2!=NULL)
        {
            r->next = head2 ;
        }
    }
}