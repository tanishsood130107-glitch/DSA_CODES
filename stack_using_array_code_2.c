#include <stdio.h>
void insert(int [], int *);
void del(int [] , int *);
void display(int [] , int * );

int main()
{
    int a[10],i=-1, ch ;

    do
    {
        printf("/n 1 : insert \n 2 : delete \n 3 : exit");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                insert(a,&i);
                break ;
            case 2 :
                del(a,&i);
                break ;
            case 3 :
                break ; 
            
        }

    }
    while(ch<2) ;
    
    display(a,&i);

    return 0 ;
}


void insert(int a[], int *i)
{
    if(*i ==9)
    {
        printf("the stack is full");
    }
    else 
    {
        (*i)++;
        printf("enter th value you want to insert : ");
        scanf("%d",&(a[*i]));
    }
}

void del(int a[] , int *i)
{
    if(*i == -1)
    {
        printf("the stack is empty ");

    }
    else
    {
        printf("the deleted element is %d : ", a[*i]);
        (*i)--;

    }
}

void display(int a[], int *i )
{
    int j ;
    if((*i)==-1)
    {
        printf("the array is emplty ");
    }
    else
    {
        for(j=(*i);j>=0;j--)
        {
            printf("%d \t", a[*i]);
        }
    }
}