#include <stdio.h>
# define max  10 
void seq(int []);

int main()
{
    int a[max] , i ;
    for(i=0;i<max;i++)
    {
        printf("enter the value at a[%d] :  " ,i);
        scanf("%d",&a[i]);

    }

    seq(a);

    return 0 ;

}


void seq(int a[max])
{
    int temp , neg = 0 , pos = max  ,i;

    for(neg=0;neg<pos;neg++)
    {
        if(a[neg]<0)
        {
            pos--;
            continue;
        }
        else if(a[neg]>0)
        {
            for(i=neg+1;i<max;i++)
            {
                if(a[i]<0)
                {
                    temp = a[neg];
                    a[neg] = a[i];
                    a[i] = temp ;
                    pos--;
                    break;

                    
                }
                else 
                {
                    temp = a[neg];
                    a[neg] = a[i];
                    a[i] = temp ;

                }
            }
        }
    }

    for(i=0;i<max;i++)
    {
        printf("%d \t",a[i]);
    }


    
}