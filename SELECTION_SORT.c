#include <stdio.h>
# define elem 5

int main()
{
    int arr[elem] , i , j , temp , min ;

    for(i=0;i<elem;i++)
    {
        printf("the element at arr[%d] : ", i);
        scanf("%d",&arr[i]);
    }

    min = arr[1];

    for(i=0;i<elem-1;i++)
    {
        min = i ;

        for(j=i+1;j<elem;j++)
        {
            if(arr[j]<arr[min])
            {
                min = j ;
            }
        }


        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp ; 
    }

    for(i=0;i<elem;i++)
    {
        printf("%d \t",arr[i]);
    }

    return 0 ;
}