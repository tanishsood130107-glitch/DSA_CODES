#include <stdio.h>
int main()
{
    int num ;
    printf("enter the number if element in the array : ");
    scanf("%d",&num);

    int a[num], i  , positive[num] , zero[num] , negative[num] , pos =0 , neg =0  , zer = 0;

    for(i=0;i<num;i++)
    {
        printf("enter the element at a[%d] : ", i);
        scanf("%d",&a[i]);
    }

    for(i=0;i<num;i++)
    {
        if(a[i]>0)
        {
            positive[pos] = a[i];
            pos++;

        }
        else if (a[i]<0)
        {
            negative[neg] = a[i];
            neg ++ ;
        }
        else 
        {
            zero[zer] = a[i];
            zer++;
        }

    }

    printf(" \n postive element \n");

    for(i=0;i<pos;i++)
    {
        printf("%d \t",positive[i]);
    }

    printf(" \n negative element \n ");

    for(i=0;i<neg;i++)
    {
        printf("%d \t" , negative[i]);
    }

    printf("\n all the zeros \n");

    for(i=0;i<zer;i++)
    {
        printf("%d \t ", zero[i]);


    }

    return 0 ;

}