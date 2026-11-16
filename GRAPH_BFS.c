#include <stdio.h>
#define max 100

int adj_mat[100][100];
int visited[100];
int queue[100];
int num, front = -1 , rear = -1 ;

void BFS(int);
void enqueue(int);
int dequeue();
int graph_creat();

int main()
{
    int source ;

    printf("enter the number of nodes :");
    scanf("%d",&num);

    source = graph_creat();
    BFS(source);

    return 0 ;
    
}

void enqueue(int num)
{
    if(rear == max-1)
    {
        printf("queue is overfowed");
    }

    queue[++rear] = num ;

    if(front==-1)
    {
        front = 0 ;
    }
}

int dequeue()
{
    int item;

    if(front == -1)
    {
        return -1;
    }

    item = queue[front];

    if(front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front++;
    }

    return item;
}

int graph_creat()
{
    int i , j , source ;

    printf("\n aducency graph \n ");

    for(i=0;i<num;i++)
    {
        for(j=0;j<num;j++)
        {
            printf("is there a vertex between edge %d and %d (0/1) : ",i,j);
            scanf("%d",&adj_mat[i][j]);
        }
    }

    printf("enter the root vertes : ");
    scanf("%d",&source);

    return source ;

}

void BFS(int root)
{
    int i ,vertex;

    visited[root] = 1 ;
    enqueue(root);

    while(front!=-1)
    {
        vertex = dequeue();
        printf("%d ",vertex);

        for(i=0;i<num;i++)
        {
            if( adj_mat[vertex][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1 ;
                enqueue(i);
            }
        }
    }

}