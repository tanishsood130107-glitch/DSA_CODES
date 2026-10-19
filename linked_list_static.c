#include <stdio.h>
#include <stdlib.h>

struct list
{
    int a ;
    float b;
    struct list *next;

}x,y,z ;

int main()
{
    struct list *p ;
    p = &x ;
    printf("enter the value of x.a : ");
    scanf("%d",&x.a);
    printf("enter the value of x.b : ");
    scanf("%f",&x.b);
    x.next = &y;
    printf("enter the value of y.a : ");
    scanf("%d",&y.a);
    printf("enter the value of y.b : ");
    scanf("%f",&y.b);
    y.next = &z ;
    printf("enter the value of z.a : ");
    scanf("%d",&z.a);
    printf("enter the value of z.b : ");
    scanf("%f",&z.b);
    z.next = NULL ;
    while(p!=NULL)
    {
        // printf("%d \n",p);
        printf("%d %f \n ",p->a , p->b);
        p = p->next ;
    }



    return 0 ;
}