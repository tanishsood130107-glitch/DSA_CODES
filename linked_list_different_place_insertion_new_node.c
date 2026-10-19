#include <stdio.h>
#include <stdlib.h>

typedef struct list 
{
    int data ;
    struct list *next ;
}sl ;

sl* insert(sl*);
sl* insert_bef_fir_node(sl*);
void insert_aft_fir_node(sl*);
sl* insert_aft_last_node(sl*);
sl*  insert_bef_last_node(sl*);
void display(sl*);
int count(sl*);

int main()
{
    sl *ptr = NULL , *right = NULL ; 
    int ch , c ; 

    do
    {
        printf("\n 1: insert \n 2 : insert node before first node \n 3: insert after first node \n 4 : insert after last node \n 5 : insert before last node  \n 6 : display \n 7 : count \n 8 : exit \n");
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
                ptr = insert_bef_fir_node(ptr);
                break ;
            case 3 :
                insert_aft_fir_node(ptr);
                break;
            case 4 :
                right = insert_aft_last_node(ptr);
                break ;
            case 5 :
                ptr = insert_bef_last_node(ptr);
                break ;
            case 6 :
                display(ptr );
                break ;
            case 7 :;
                c = count(ptr);
                printf("the total number of nodes are : %d ", c);
                break ;
                

        }

    }while(ch<=7 );

    return 0 ;
}

sl *insert( sl* right )
{
    sl *p =NULL;

    p = (sl*)malloc(sizeof(sl));

    if(p!=NULL)
    {
        printf("enter the value you want to insert at the node : ");
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

    return right ;
}

sl *insert_bef_fir_node(sl* ptr)
{
    sl *p=NULL ;
    int v ;

    if(ptr==NULL)
    {
        printf("there are no nodes in the linked list ");
    }
    else 
    {
        p = (sl*)malloc(sizeof(sl));

        if(p!=NULL)
        {
                
            printf("enter the value you want to insert in this node : ");
            scanf("%d",&v);
            p->data = v ;
            p->next = ptr ;
            ptr = p ;

                
        }
    }    

    return ptr ;

     

}

void insert_aft_fir_node(sl* ptr)
{
    sl *p=NULL , *t = NULL ;
    int v ;

    if(ptr==NULL)
    {
        printf("there no node present in the linked list ");

    }
    else
    {
        
    p = (sl*)malloc(sizeof(sl));

    if(p!=NULL)
    {
        printf("enter the value you want to insert : ");
        scanf("%d",&v);
        p->data = v ;
        p->next = ptr->next ;
        ptr->next = p;
    }
    }

}

sl* insert_aft_last_node(sl* ptr)
{
    sl *p = NULL , *t=ptr ;
    int v ;

    if(ptr==NULL)
    {
        printf("the list is empty ");
    }
    else
    {
        p = (sl*)malloc(sizeof(sl));

        if(p!=NULL)
        {
           
            while(t->next!=NULL)
            {
                t = t->next ;
            }

            printf("enter the value you want to insert at the node : ");
            scanf("%d",&v);

            p->data = v ;

            t->next = p ;
            p->next = NULL ;
            
        }
        else
        {
            printf("memory not allocated ");
        }
    }

    return p ;
}

sl* insert_bef_last_node(sl *ptr) 
{
    sl *p = NULL , *t = ptr;
    int c , i = 1 , v;

    if(ptr==NULL)
    {
        printf("list is empty ");
    }
    else
    {
        p =(sl*)malloc(sizeof(sl));

        if(p==NULL)
        {
            printf("memory not allocated : ");
        }
        else
        { 

            printf("enter the value you want to enter inside the node ");
            scanf("%d",&v);
            p->data = v ;
            c = count(ptr);
            if(c>=2)
            {
                while(i!=c)
                {
                    if(i==(c-1))
                    {
                        p->next = t->next;
                        t->next = p ;
                        break ;
                    }
                    t = t->next ;
                    i++;
                }
            }
            else
            {
                p->next = ptr;
                ptr = p ;

            }
            
            
        }
    }
    return ptr ;
    
}


void display(sl* ptr)
{
    if(ptr ==NULL)
    {
        printf("the are no nodes ");
    }
    else
    {
        while(ptr!=NULL)
        {
            printf("%d \t",ptr->data);
            ptr = ptr->next ;
        }
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