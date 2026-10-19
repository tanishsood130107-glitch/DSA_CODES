#include <stdio.h> 
# define max 5
void uni(int [] , int [] , int []);
void inter(int[],int [] , int []);
int main()
{
    int i; 

    int a[max], b[max] , c[2*max];

    for(i=0;i<max;i++)
    {
        printf("enter the value at a[%d] : " , i);
        scanf("%d",&a[i]);
    }

     for(i=0;i<max;i++)
    {
        printf("enter the value at b[%d] : " , i);
        scanf("%d",&b[i]);
    }

    uni(a,b,c);
    printf("\n");
    inter(a,b,c);

    return 0 ;

}

void uni(int a[],int b[] , int c[])
{
    int i , ind = 1 , j, count = 1;
    c[0] = a[0]; 
    for(i=1;i<max;i++)
    {
        count = 0 ;

        for(j=0;j<ind;j++)
        {
            if(c[j]==a[i])
            {
                count ++;
            }

        }

        if(count==0)
        {
            c[ind] = a[i];
            ind++;
        }

        
        
    }

    for(i=0;i<max;i++)
    {
        count = 0 ;
        for(j=0;j<ind;j++)
        { 
            if(c[j]==b[i])
            {
                count ++;

            }

        }

        if(count ==0 )
        {
            c[ind] = b[i];
            ind++;
            
        }
    }

    for(i=0;i<ind;i++)
    {
        printf("%d ",c[i]);
    }



}

void inter(int a[],int b[] , int c[])
{
    int i , j , count , ind = 0 , count1 ;

    for(i=0 ; i<max;i++)
    {
        count = 0 ;
        for(j=0;j<max;j++)
        {
            if(a[i]==b[i])
            {
                count ++ ;
            }
        }

        
        if(count>0)
        {
            if(ind==0)
            {
                c[ind] = a[i];
                ind ++ ;
            }
            else
            {
                for(j=0;j<ind;j++)
                {
                    count1 = 1 ;
                    if(c[j]==a[i])
                    {
                        count1 =0;
                    }
                }

                if(count1==1)
                {
                    c[ind] = a[i];
                    ind++ ;
                }
            }
        }
    }

    

    for(i=0;i<ind;i++)
    {
        printf("%d ",c[i]);
    }
}