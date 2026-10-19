#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 20 

void infix_to_post_fix(char []);


//main function 

int main()
{
    char  s[max] ;
    printf("enter the given infix expression  : ");
    gets(s);
    
    infix_to_post_fix(s);

    return 0 ;

}


void infix_to_post_fix(char s[])
{
    char stack[max], post_fix[max];
    int i , top = 0 , ;


    for(i=0;s[i]!='\0';i++)
    {

    } 
     
}
