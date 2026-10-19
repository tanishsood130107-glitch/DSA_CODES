#include <stdio.h>
#define max 6
#include <math.h>
void prime(int[]);
void armstrong(int[]);
int digit(int);
void pallidrome(int []);

int main()
{
    int a[max], i , x;
    
    for(i=0;i<max;i++)
    {
        printf("enter the value  at a[%d] : " , i);
        scanf("%d",&x);

        if(x%10==0)
        {
            i--;
        }
        else
        {
            a[i] = x;
        }
    }

    prime(a);
    printf("\n");
    armstrong(a);
    printf("\n");
    // pallidrome(a);

    return 0 ;

}

void prime(int a[])
{
    int i , j ,count  , prime = 0;

    for(i=0;i<max;i++)
    {
        count = 0 ;

        for(j=2;j<=(a[i]/2);j++)
        {
            if(a[i]%j==0)
            {
                count ++;
                
            }
        }

        if(count ==0)
        {
            prime++;
        }
        
    }

    printf("the number of prime numbers are : %d ", prime);
}

void armstrong(int a[])
{
    int i , num , j , count =0 , rem , digits , sum ;

    for(i=0;i<max;i++)
    {
        
        sum =0;
        num = a[i];
        digits = digit(a[i]);
        
        while(num!=0)
        {
            rem = num%10;
           
            sum = sum + (int) (pow(rem,digits));
            num = num/10;
        }

        if(sum==a[i])
        {
            count ++;
        }
    }

    printf("the number of armstong numbers are : %d ", count );
}

int digit(int num)
{
    int count=0 ;

    while(num!=0)
    {
        num = num/10;
        count ++ ;
    }

    return count ;
}

// void pallidrome (int a[])
// {
//     int is_palli  , i , j , count = 0 , digits ;

//     for(i=0;i<max;i++)
//     {
//         is_palli = 1;
//         digits = digit(a[i]);

//         for(j=0;j<(digits/2);j++)
//         {
//             if(a[j]!=a[max-1-j])
//             {
//                 is_palli = 0 ;
//                 break ;

//             }

//         }

//         if(is_palli == 1)
//         {
//             count++;
//         }



//     }

//     printf("the number of pallidrome in this array are : %d ", count );
// }