#include <stdio.h>
#include <conio.h>

void dijkstras();
int c[10][10], n, src;
void printPath(int parent[], int node);

void main()
{
    int i, j;
    printf("\nEnter the no of vertices:\t");
    scanf("%d", &n);
    printf("\nEnter the cost matrix:\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &c[i][j]);
        }
    }
    printf("\nEnter the source node:\t");
    scanf("%d", &src);
    dijkstras();
    getch();
}

void dijkstras()
{
    int vis[10], dist[10], parent[10], u, j, count, min;
    for (j = 1; j <= n; j++)
    {
        dist[j] = c[src][j];
        parent[j] = src;
    }
    for (j = 1; j <= n; j++)
    {
        vis[j] = 0;
    }
    dist[src] = 0;
    vis[src] = 1;
    count = 1;
    while (count != n)
    {
        min = 9999;
        for (j = 1; j <= n; j++)
        {
            if (dist[j] < min && vis[j] != 1)
            {
                min = dist[j];
                u = j;
            }
        }
        vis[u] = 1;
        count++;
        for (j = 1; j <= n; j++)
        {
            if (min + c[u][j] < dist[j] && vis[j] != 1)
            {
                dist[j] = min + c[u][j];
                parent[j] = u;
            }
        }
    }
    printf("\nThe shortest distance is:\n");
    for (j = 1; j <= n; j++)
    {
        printf("\n%d-->%d=%d (Path: %d", src, j, dist[j], src);
        printPath(parent, j);
        printf(")");
    }
}

void printPath(int parent[], int node)
{
    if (parent[node] == src)
    {
        printf("->%d", node);
        return;
    }
    printPath(parent, parent[node]);
    printf("->%d", node);
}

