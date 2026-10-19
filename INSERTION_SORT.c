#include <stdio.h>
#define max 5 

int main()
{
    int arr[max] , i , j , temp;

    for(i=0;i<max;i++)
    {
        printf("enter the element at arr[%d] : ",i);
        scanf("%d",&arr[i]);
    }

    for(i=1;i<max;i++)
    {
        temp = arr[i];
        j = i -1 ;

        while(j>=0&& arr[j]>temp)
        {
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = temp ;
    }

    for(i=0;i<max;i++)
    {
        printf("%d \t",arr[i]);
    }

    return 0 ;
}