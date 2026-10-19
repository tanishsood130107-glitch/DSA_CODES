#include <stdio.h>
int max ;

void count(int [] , int );
int main()
{
    int   num, i ;

    printf("enter the number of element in the array : ");
    scanf("%d",&num);

    int a[num];

    for(i=0;i<num;i++)
    {
        printf("enter the element at a[%d] : ",i);
        scanf("%d",&a[i]);
    }

    count(a,num);

    return 0 ; 


}

void count(int a[], int num)
{
    int even = 0 , i;
    for(i=0;i<num;i++)
    {
        if(a[i]%2==0)
        {
            even++;
        }
    }

    printf("the number of event digits in the array is : %d ", even );
    printf("\n the number of odd digits in the array is : %d ", num-even);


}