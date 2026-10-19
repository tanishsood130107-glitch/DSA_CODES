#include <stdio.h>
# define  max  15

void pat(int[]);

int main()
{
    int a[max] , i  ;

    for(i=0;i<max;i++)
    {
        printf("enter the element at a[%d] : ", i);
        scanf("%d",&a[i]);
    }

    pat(a);

    return 0 ;
}

void pat(int a[])
{
    int i , j , rep = 0 ,  count ;

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
                count=1;
                break ;
                    
            }

        }
        
    
        if(count==1)
        {
            int c = 0 ;
            for(j=0;j<i;j++)
            {
                if(a[i]==a[j])
                {
                    c = 1;
                    break;
                }
            }

            if(c==0)
            {
                rep++;
                
                if(rep==4)
                {
                    printf("%d",a[i]);
                
                }
                
            }
            
        }
    }

}
