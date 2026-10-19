#include <stdio.h>
#include <stdlib.h>

typedef struct list
{
    int data ;
    struct list *next ;
}sl ;

void ins_left(sl**);
void  ins_right(sl**);
void display(sl*);
void del_left(sl**);
void del_right(sl**);
void reverse(sl**);
void print_reverse(sl*);

int main()
{
    sl *head = NULL ;
    int ch ;

    do
    {
        printf("\n 1 : insert left \n 2 : insert right \n 3 : del left \n 4 : del right \n 5 : display \n 6 reverse print \n 7 reverse linked list \n enter your choice ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1 :
                ins_left(&head);
                break ;
            case 2 : 
                ins_right(&head);
                break ;
            case 3 : 
                del_left(&head);
                break ;
            case 4 : 
                del_right(&head);
                break ;
            case 5 : 
                display(head);
                break ;
            case 6 :
                print_reverse(head);
                break ;
            case 7 : 
                reverse(&head);
                break ;
                
        }

    }while(ch<=7);

    return 0 ;
}


void ins_left(sl **head)
{
    sl *p = NULL ;
    p = (sl*)malloc(sizeof(sl));


    if(p == NULL)
    {
        printf("memory not allocated ");
    }
    else
    {
        printf("enter the data you want to insert : ");
        scanf("%d",&(p->data));

        p->next = *head ;
        *head = p ;
    }

   
}

// sl *ins_right(sl* right)
// {
//     sl* p = NULL ;

//     p = (sl*)malloc(sizeof(sl));

//     if(p==NULL)
//     {
//         printf("memory not allocated ");
//     }
//     else
//     {

//         printf("enter the data you want to insert ");
//         scanf("%d",&(p->data));
//         if(right==NULL)
//         {
//             right = p ;
//         }
//         else
//         {
//             right->next = p ;
//             right = p ;
//         }
//         right->next = NULL ;
//     }

//     return right ;
// }

void ins_right(sl **head)
{
    sl * p = NULL ,*r = *head ;

    p = (sl*)malloc(sizeof(sl));

    if(p==NULL)
    {
        printf("memory not allcated ");
    }
    else
    {
        printf("enter the value you want to insert : ");
        scanf("%d",&(p->data));
        if(*head == NULL )
        {
            *head = p ;
            (*head)->next = NULL ;
        }
        else
        {
            while(r->next!=NULL)
            {
                r = r->next ;
            }

            r->next = p ;
            p->next = NULL ;
        }
    }

}

void display(sl *head)
{
    if(head == NULL)
    {
        printf("the list is empty : ");
    }
    else
    {
        while(head!=NULL)
        {
            printf("%d\t",head->data);
            head = head->next ;
        }
    }
}

void  del_left(sl**head)
{
    sl* p = *head;
    if(*head == NULL)
    {
        printf("the list is empty no element will be deleted : ");
    }
    else
    {
        (*head) = (*head)->next ;
        free(p);
        p = NULL ;
    }
}

void del_right(sl** head)
{
    sl* p = *head , * r = NULL;

    if(*head == NULL)
    {
        printf("the list is empty no element would be deleted : ");
    }
    else
    {
        while(p->next->next!=NULL)
        {
            p = p->next ;
        }

        r = p->next ;

        p->next = NULL ;
        free(r);
        r = NULL ;
    }
}

void reverse(sl**head)
{
    sl *prev = NULL , *curr = *head  , *nextt = NULL;

    while(curr!=NULL)
    {
        nextt = curr->next ;
        curr->next = prev ;
        prev = curr ;
        curr = nextt ;
    }

    *head = prev ;
}


void print_reverse(sl*head)
{
    if(head == NULL)
    {
        return ;
    }
    else 
    {
    print_reverse(head->next);
    printf("%d \t",head->data);
    }
}