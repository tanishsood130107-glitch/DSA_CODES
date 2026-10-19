#include <stdio.h>
#include <stdlib.h>

typedef struct  circular_list
{
    int data ;
    struct circular_list *next ;
}cl;

cl *insert(cl*);
void circular_to_simple(cl*);
void simple_to_circular(cl*);
void display(cl*);

int main()
{
    cl *ptr = NULL ;
    int ch ;

    do
    {
        printf("\n 1 : insert \n 2 : circular to simple \n 3 : simple to circular \n 4 : display \n ");
        scanf("%d",&ch);

        switch (ch)
        {
            case 1 :
                ptr = insert(ptr);
                break ;
            case 2 :
                circular_to_simple(ptr);
                break ;
            case 3 :
                simple_to_circular(ptr);
                break ;
            case 4 :
                display(ptr);
                break ;
                
        }
    }while(ch<=4);

    return 0 ;
}


cl *insert(cl *ptr)
{
    cl *p = NULL ;

    p = (cl*)malloc(sizeof(cl));

    if(p==NULL)
    {
        printf("not enough memory ");
    }
    else
    {
        printf("enter the value you want to insert : ");
        scanf("%d",&(p->data));
        if(ptr==NULL)
        {
            ptr = p ;
            ptr->next = p ;
        }
        else
        {
            p->next = ptr->next ;
            ptr->next = p ;
        }
    }

    return ptr ;
}


// void circular_to_simple(cl* ptr)
// {
//     cl *p=ptr ;

//     if(ptr==NULL)
//     {
//         printf("the list is empty :");
//     }
//     else
//     {
//         while(p->next!=ptr)
//         {
//             p = p->next ;
//         }

//         p->next = NULL ;

//     }
// }


void circular_to_simple(cl *ptr)
{
    cl* p = ptr ;

    if(ptr ==NULL)
    {
        printf("the list is empty");
    }
    else
    {
        while(1)
        {
            if(p->next==NULL)
            {
                printf("its already a simple linked list : ");
                break ;
            }
            else if(p->next == ptr)
            {
                p->next = NULL;
                printf("converted");
                break ;
            }

            p = p->next ;
        }
    }
}

// void simple_to_circular(cl* ptr)
// {
//     cl *p=ptr;

//     if(ptr==NULL)
//     {
//         printf("the list is empty ");
//     }
//     else
//     {
//         while(p->next !=NULL)
//         {
//             p=p->next ;
//         }

//         p->next = ptr ;
//     }
// }


void simple_to_circular(cl* ptr)
{
    cl *p= ptr ;

    if(ptr==NULL)
    {
        printf("the list is empty : ");
    }
    else
    {
        while(1)
        {
            if(p->next == NULL)
            {
                p->next = ptr ;
                break ;
            }
            else if(p->next == ptr)
            {
                printf("its alreadya circular linked list ");
                break ;
            }

            p = p->next ;
        }
    }
}

void display(cl *head)
{
    cl *p = head->next ;
    if(head == NULL)
    {
        printf("the list is empty : ");
    }
    else
    {
        do
        {
            printf("%d \t",p->data);
            p = p->next ;
        } while (p != head->next  );
        
    }

}