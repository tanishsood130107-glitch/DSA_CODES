#include <stdio.h>
int insert(int [], int);
int del(int [] , int);
void display(int [], int );

int main()
{
    int a[10], i=-1, ch, j;

    do
    {
        printf("/n 1 : insert \n 2 : delete \n 3 : exit");
        scanf("%d",&ch);

        switch (ch)
        {
            case 1 :
                i = insert(a,i);
                break;
            case 2 :
                i = del(a,i);
                break ;
            case 3 :
                break ;
        }
    }
    while(ch<=2);

    display(a,i);

  

    
    return 0 ;


}

int insert(int a[], int i)
{
    int x ;
    if(i==9)
    {
        printf("the array is full");
        return i ;
    }
    else 
    {
        printf("enter the value you want to enter in the array : ");
        scanf("%d",&x);
        i++ ;
        a[i] = x;
        return i ;
    }
}

int del(int a[], int i )
{
    int x ;
    if(i==-1)
    {
        printf("the array is emplty ");
        return i ;
    }
    else
    {
        x = a[i];
        printf("the deleted value is : %d ", x);
        i--;
        return i ;

    }
    
}

void display(int a[], int i)
{
    int j ;
    if(i==-1)
    {
        printf("the stack is empty");

    }
    else
    {
        for(j=i;j>=0;j--)
        {
            printf("%d \t",a[j]);
        }
    }
}