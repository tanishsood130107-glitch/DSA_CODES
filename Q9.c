#include <stdio.h>
#define max 14

void pat(int []);
int main()
{
    int a[max],i;

    for(i=0;i<max;i++)
    {
        printf("enter the value at a[%d] : " , i);
        scanf("%d",&a[i]);
    }

    pat(a);

    return 0 ;
}

void pat(int a[])
{
    int i , j , count , non_rep =0;
    
    for(i=0;i<max;i++)
    {
        count = 0 ;
        for(j=0;j<max;j++)
        {
            if(i==j)
            {
                continue;
            }

            if(a[i]==a[j])
            {
                count =1 ;
                break;
            }
        }

        if(count==0)
        {
            non_rep++;
            if(non_rep==4)
            {
                printf("%d", a[i] );
                break ;
            }
        }
    }
   
}