#include <stdio.h>
#include <stdlib.h>

typedef struct double_list
{
    struct double_list *prev ;
    int data ;
    struct double_list *next ;
}dl ;

dl* insert_left(dl*);
dl* insert_right(dl*);
void display_l_to_r(dl*);
void display_r_to_l(dl*);
void display_without_overlap(dl*, dl*);

// main function

int main()
{
    dl *l = NULL , *r = NULL ;
    int ch ;

    do
    {
        printf("\n 1 : insert left \n 2 : insert_right \n 3 : display left to right  \n 4 : display right to left \n 5 : display without overlapping \n enter your choice : ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1 :
                r = insert_right(r);
                if(l==NULL)
                {
                    l = r ;
                }
                break ;
            case 2 :
                l = insert_left(l);
                if(r == NULL)
                {
                    r = l ;
                }
                break ;
            case 3 :
                display_l_to_r(l);
                break ;
            case 4 :
                display_r_to_l(r);
                break ;
            case 5 :
                display_without_overlap(l,r);
                break ;
        }

    }while(ch<=5);
}


// left insert 

dl* insert_left(dl* left)
{
    dl *p = NULL ; 

    p = (dl*)malloc(sizeof(dl));

    if(p==NULL)
    {
        printf("not enough memory ");
    }
    else
    {
        printf("enter the value you want to insert : ");
        scanf("%d",&(p->data));
        if(left == NULL)
        {
            p->prev = NULL ;
            p->next = NULL ;
            left = p ;
        }
        else
        {
            p->prev = NULL ;
            p->next = left ;
            left->prev = p ;
            left = p ;

        }
    }

    return left ; 

}

// right insert 

dl *insert_right(dl *r)
{
    dl *p=NULL ;
    p = (dl*)malloc(sizeof(dl));


    if(p==NULL)
    {
        printf("memory not allocated : ");
    }
    else
    {
        printf("enter the data you want to insert in the list : ");
        scanf("%d",&(p->data));


        if(r==NULL)
        {
            p->prev = NULL ;
            p->next = NULL ;
            r = p ;
        }
        else
        {
            r->next = p ;
            p->prev = r ;
            p->next = NULL ;
            r = p ;
        }
    }

    return r ;
}


// display left to right

void display_l_to_r(dl *l)
{
    dl* p = l ;

    if(p==NULL)
    {
        printf("the list is empty : ");
    }
    else
    {
        while(p!=NULL)
        {
            printf("%d \t",p->data);
            p = p->next ;
        }
    }
}

// display right to left 

void display_r_to_l(dl *r)
{
    dl *p = r ;

    if(p==NULL)
    {
        printf("the list is empty : ");
    }
    else
    {
        while(p!=NULL)
        {
            printf("%d \t",p->data);
            p = p->prev ;
        } 
    }
}


// display without overlapping 

void display_without_overlap(dl *l , dl *r)
{
    int ch = 0 ;
    if(l == NULL )
    {
        printf("the list is empty ");
    }
    else
    {
        while(1)
        {
            if(ch==0)
            {
                printf("%d \t",l->data);
                if(l==r)
                {
                    break ;
                }
                l = l->next ;
                ch = 1 ;
            }
            else
            {
                printf("%d \t", r->data);
                if(l==r)
                {
                    break ;
                }
                r = r->prev ;
                ch = 0 ;
            }
        }
    }
}
