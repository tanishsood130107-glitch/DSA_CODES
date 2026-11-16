
#include <stdio.h>

#define MAX 100

typedef struct Edge
{
    int src, dest, weight;
}se ;

se heap[MAX];
int heapSize = 0;

int parent[MAX];
int rank[MAX];

void swap(se*,se*);
void uni(int , int);
int find(int);
void markset(int);
void insert(se);
se deletemin();
void kruskals(int,int);

int main()
{
    int n, e;
    se temp;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter source, destination and weight:\n");

    for(int i = 0; i < e; i++)
    {
        scanf("%d %d %d",
              &temp.src, &temp.dest, &temp.weight);

        insert(temp);
    }

    kruskal(n, e);

    return 0;
}



void swap(se *a, se *b)
{
    se temp = *a;
    *a = *b;
    *b = temp;
}


void insert(se e)
{
    int i = ++heapSize;

    heap[i] = e;

    while(i > 1 && heap[i].weight < heap[i/2].weight)
    {
        swap(&heap[i], &heap[i/2]);
        i = i/2;
    }
}


struct Edge deleteMin()
{
    struct Edge min = heap[1];

    heap[1] = heap[heapSize--];

    int i = 1;

    while(1)
    {
        int smallest = i;
        int left = 2*i;
        int right = 2*i + 1;

        if(left <= heapSize &&
           heap[left].weight < heap[smallest].weight)
            smallest = left;

        if(right <= heapSize &&
           heap[right].weight < heap[smallest].weight)
            smallest = right;

        if(smallest == i)
            break;

        swap(&heap[i], &heap[smallest]);
        i = smallest;
    }

    return min;
}


void makeSet(int n)
{
    for(int i = 1; i <= n; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }
}


int find(int x)
{
    if(parent[x] != x)
        parent[x] = find(parent[x]);

    return parent[x];
}


void uni(int x, int y)
{
    int rootX = find(x);
    int rootY = find(y);

    if(rootX == rootY)
        return;

    if(rank[rootX] < rank[rootY])
        parent[rootX] = rootY;

    else if(rank[rootX] > rank[rootY])
        parent[rootY] = rootX;

    else
    {
        parent[rootY] = rootX;
        rank[rootX]++;
    }
}


void kruskal(int n, int e)
{
    struct Edge edge;
    int count = 0;
    int totalCost = 0;

    makeSet(n);

    printf("\nEdges in Minimum Spanning Tree:\n");

    while(heapSize > 0 && count < n-1)
    {
        edge = deleteMin();

        if(find(edge.src) != find(edge.dest))
        {
            printf("%d -- %d = %d\n",
                   edge.src, edge.dest, edge.weight);

            uni(edge.src, edge.dest);

            totalCost += edge.weight;
            count++;
        }
    }

    if(count == n-1)
        printf("\nMinimum Cost = %d\n", totalCost);
    else
        printf("\nMST does not exist. Graph is disconnected.\n");
}

