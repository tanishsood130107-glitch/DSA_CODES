#include <stdio.h>
void check_ap(int [], int);
int main()
{
    int num ;

    printf("enter the number of elements in the array : ");
    scanf("%d",&num);

    int a[num] , i ;

    for(i=0;i<num;i++)
    {
        printf("enter the element at a[%d] : ", i);
        scanf("%d",&a[i]);
    }

    check_ap(a,num);

    return 0 ;

}

void check_ap(int a[], int num)
{
    int d , i ,count =1 ;

    for(i=0;i<num-2;i++)
    {
        if(a[i+1]-a[i]!=a[i+2]-a[i+1])
        {
            count = 0 ;
        }
    }

    if(count == 0 )
    {
        printf("the series is not a ap");

    }
    else 
    {
        printf("the series is an ap ");
    }
}