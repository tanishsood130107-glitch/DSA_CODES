#include <stdio.h>
#define max 100

int adj_mat[max][max];
int visited[max],stack[max];
int num , top =-1;


void DFS(int);
void push(int);
int pop();
int graph_creat();

int main()
{
    int i , source ;

    printf("enter the number of vertex :");
    scanf("%d",&num);

    for(i=0;i<num;i++)
    {
        visited[i] = 0 ;
    }

    source = graph_creat();
    DFS(source);

    return 0 ;
}

int graph_creat()
{
    int i,j,root;

    for(i=0;i<num;i++)
    {
        for(j=0;j<num;j++)
        {
            printf("is there a vertex between %d and %d (0/1) :",i,j);
            scanf("%d",&adj_mat[i][j]);
        }

        printf("\n");
    }

    printf("enter the root node : ");
    scanf("%d",&root);

    return root ;
}

void push(int n)
{
    if(top==max-1)
    {
        printf("the stack is full");
    }
    else
    {
        stack[++top] = n;
    }
}

int pop()
{
    int value;

    if(top==-1)
    {
        return -1;
    }
    else
    {
        value = stack[top--];
    }

    return value ;
}

void DFS(int source)
{
    int i , vertex ,count = 0;

    visited[source] = 1;
    count++;
   

    push(source);

    while(top!=-1)
    {
        vertex = pop();
        printf("%d ",vertex);
        

        for(i=num-1; i>=0; i--)
        {
            if(adj_mat[vertex][i] == 1 && visited[i] == 0 )
            {
                visited[i] = 1;
                push(i);
                
            }
        }
    }

        

}


// void DFS(int source)
// {
//     int i, vertex, count = 0;

//     visited[source] = 1;
//     count++;

//     push(source);
//     printf("%d ", source);

//     while(count < num && top != -1)
//     {
//         vertex = stack[top];

//         for(i = 0; i < num; i++)
//         {
//             if(adj_mat[vertex][i] == 1 && visited[i] == 0)
//             {
//                 visited[i] = 1;
//                 count++;
//                 push(i);
//                 printf("%d ", i);
//                 break;
//             }
//         }

//         if(i == num)
//         {
//             pop();
//         }
//     }
// }