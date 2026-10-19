#include <stdio.h>

int main()
{
    int num ;
    printf("enter the number of element in the array : ");
    scanf("%d",&num);

    int a[num] , i , max ,j;

    for(i=0;i<num;i++)
    {
        printf("enter the element at a[%d] : ",i);
        scanf("%d",&a[i]);

    }

    

    for(i=0;i<num;i++)
    {

        max = a[i];
        for(j=1+i;j<num;j++)
        {
            if(a[j]>max)
            {
                a[i] = a[j];
                a[j] = max ;
                max = a[i];
            }

        }
    }

    for(i=0;i<num;i++)
    {
        printf("%d",a[i]);
    }

    int count = 1 ;
    for(i=0;i<num-1;i++)
    {
        if(a[i]==a[i+1])
        {
            
            count ++ ;

        }
        else
        {
            printf("Frequency of %d = %d\n", a[i], count);
            count = 1;
        }
    }
    printf("Frequency of %d = %d\n", a[num-1], count);

    return 0 ;
}