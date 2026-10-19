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

    for(i=0;i<max-1;i++)
    {
        for(j=0;j<max-1-i;j++)
        {
            if(arr[j]>arr[j+1])
            { 
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp ;    
            }
        }
    }

    for(i=0;i<max;i++)
    {
        printf("%d \t",arr[i]); 
    }

    return 0 ;
}