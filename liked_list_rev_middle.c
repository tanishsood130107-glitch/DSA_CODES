#include <stdio.h>
#include <stdlib.h>

typedef struct list
{
    int data ;
    struct list *next ;
}l;


void create(l**);
void display(l*);
l* middle(l*);
l* reverse(l*);  
l* reverse_st(l*);
int count(l*);

int main()
{
    l *head = NULL , *mid = NULL ,*p=NULL ;
    int ch ;

    do{
        printf("\n 1 : create \n  2 : find_middle \n 3 : reverse_middle \n  4 : display \n enter your choice :");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1 :
                create(&head);
                break ;
            case 2 :
                mid  = middle(head);
                break ;
            case 3 : 
                mid = middle(head);
                p = mid->next ;
                mid->next = NULL ;
                head = reverse_st(head);
                p = reverse_st(p);
                mid->next = p ; 
                display(head);
                break ;
            case 4 :
                display(head);
                break ;
        }
    }while(ch<=4);

    return 0 ;
    
}

void create(l **head)
{
    l *p=NULL , *last = NULL ;
    int ch ;

    while(1)
    {
        p = (l*)malloc(sizeof(l));

        if(p==NULL)
        {
            printf("size not allocated :");
        }
        else
        {
            printf("enter the value you want to insert : ");
            scanf("%d",&(p->data));

            if(*head==NULL)
            {
                *head = last = p ;
            }
            else
            {
                last->next = p ;
                last = p ;
            }
            last->next = NULL ;

            printf("do you want to insert more nodes (0/1) : ");
            scanf("%d",&ch);

            if(ch==0)
            {
                printf("\nlinkedkist completed\n");
                break ;
            }
        }
    }
}

void display(l* head)
{
    if(head == NULL)
    {
        printf("the list is empty ");
    }
    else
    {
        while(head !=NULL)
        {
            printf("%d \t",head->data);
            head = head->next ;
        }
    }
}

l* middle(l* head)
{
    l *s=head , *f= head ;

    if(head == NULL)
    {
        printf("the list is empty : ");
       
    }
    else
    {
        while(f!=NULL && f->next!=NULL)
        {
            s = s->next ;
            f = f->next->next ;
        }

        printf("the middle element of the list is %d : ", s->data);
    }

    return s ;
}



// using recursion 
l* reverse(l* head)
{
    l* p;

    // Base case
    if(head == NULL || head->next == NULL)
    {
        return head;
    }

    // Reverse the remaining list
    p = reverse(head->next);

    // Reverse the current link
    head->next->next = head;
    head->next = NULL;

    // Return the new head
    return p;
}

int count(l *head)
{
    int c =0 ;

    while(head!=NULL)
    {
        head = head->next ;
        c++;
    }

    return c ;
}

l* reverse_st(l *head)
{
    l *p = NULL , *linked = head , *stack = NULL;

    //left insert ;
    while(linked!=NULL)
    {
        p = (l*)malloc(sizeof(l));

        if(p==NULL)
        {
            printf("memory not allocated");
            break ;
        }
        else
        {
            p->data = linked->data ;

            linked = linked->next ;

            // if(stack==NULL)
            // {
            //     stack = p ;
            //     p->next = NULL;
            // }
            // else
            // {
            //     p->next = stack ;
            //     stack = p ;
            // }

            p->next = stack ;
            stack = p ;
        }

    }

    linked = head ;
    while(stack != NULL )
    {
        linked->data = stack->data ;
        linked = linked->next ;
        p = stack ;
        stack = stack->next ;
        free(p);
    }

    return head ;


}
