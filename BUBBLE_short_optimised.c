#include <stdio.h>
#define max 100 
void bubble_sort(int [],int);

int main()
{
    int a[max] , num , i ;

    printf("enter the number of elements in the array : ");
    scanf("%d",&num);

    

    for(i=0;i<num;i++)
    {
        printf("enter the element at a[%d] : ",i);
        scanf("%d",&a[i]);
    }
    printf("\n elements before sorting \n");
    for(i=0;i<num;i++)
    {
        printf("%d \t",a[i]);
    }

    bubble_sort(a, num);

    printf("\n elements after sorting \n");
    for(i=0;i<num;i++)
    {
        printf("%d \t",a[i]);
    }
}

void bubble_sort(int a[], int num)
{
    int i  , j , temp , c = 0 , f = 0 ;

    for(i=0;i<num-1;i++)
    {
        for(j=0;j<num-1-i;j++)
        {
            c++;
            if(a[j]>a[j+1])
            {
                f = 1 ;
                
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp ;
            }

            if(f==0)
            {
                break ;
            }

        }
    }

    printf("the number of times it iterated %d :", c);
}