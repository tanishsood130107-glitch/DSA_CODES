#include <stdio.h>
#define max 6

void merge(int[],int[],int[]);
void sort(int []);

int main()
{
    int i , a[max], b[max],c[max*2];

    for(i=0;i<max;i++)
    {
        printf("enter the element at a[%d] : ",i);
        scanf("%d",&a[i]);
    }

     for(i=0;i<max;i++)
    {
        printf("enter the element at b[%d] : ",i);
        scanf("%d",&b[i]);
    }

    merge(a,b,c);

    return 0 ;
}

void merge(int a[],int b[], int c[])
{

    int ind = 0 , i;
    for(i=0;i<max;i++)
    {
        c[ind] = a[i];
        ind++;
    }
    for(i=0;i<max;i++)
    {
        c[ind] = b[i];
        ind++;
    }

    sort(c);

    for(i=0;i<(2*max);i++)
    {
        printf("%d \t",c[i]);
    }

}
void sort(int a[])
{
    int i , j , temp;

    for(i=0;i<(2*max);i++)
    {
        for(j=i+1;j<(2*max);j++)
        {
            if(a[i]>a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp ;

            }
        }
    }
}

