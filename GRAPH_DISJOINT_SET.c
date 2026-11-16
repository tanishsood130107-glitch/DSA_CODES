#include <stdio.h>

int par[100];
int rank[100];


void uni(int,int);
int find(int);
void markset(int);
void print_par(int);


int main()
{
    int num ,c ;

    printf("enter the number of nodes of the graph :");
    scanf("%d",&num);

    markset(num);

    uni(2,3);
    uni(0,3);
    uni(4,5);
    uni(0,4);
    uni(6,7);
    // uni(1,4);
    // uni(1,3);

    print_par(num);



    return 0 ;
}

int find(int num)
{
    if(par[num]==num)
    {
        return par[num];
    }
    else
    {
        return find(par[num]);
    }
}

void markset(int num)
{
    int i = 0 ;

    for(i=0;i<num;i++)
    {
        par[i] = i;
        rank[i] = 0;
    }

}

void uni(int num1 , int num2)
{
    int par1 , par2 ;

    par1 = find(num1);
    par2 = find(num2);

    if(rank[par1] == rank[par2])
    {
        par[par2] = par1;
        rank[par1]++;
    }
    else if(rank[par1] > rank[par2])
    {
        par[par2] = par1;

    }
    else if(rank[par1] < rank[par2])
    {
        par[par1] = par2;
    }
    else
    {
        return ;
    }
}

void print_par(int num)
{
    int i = 0 ,c;
    for(i=0;i<num;i++)
    {
        c = find(i);
        printf("\n parent of %d is %d  and rank is %d \n",i ,c , rank[i]);
    }
} 