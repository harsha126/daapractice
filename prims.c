#include <stdio.h>
#include <conio.h>
int a, b, u, v, n, i, j, ne = 1;
int visited[10] = {0};
int min = 999, mincost = 0, cost[10][10];
void main()
{
    printf("Enter the no of nodes(<=10):");
    scanf("%d", &n);
    printf("\nenter the adjacency matrix:");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = 999;
        }
    }

    visited[1] = 1;
    while (ne < n)
    {
        min = 999;
        a=0;
        b=0;
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                if (cost[i][j] < min && visited[i] != 0)
                {
                    a = u = i;
                    b = v = j;
                    min = cost[a][b];
                }
                if (visited[v] == 0)
                {
                    printf("\nedge %d : (%d,%d) cost:%d", ne++, a, b, min);
                    mincost += min;
                    visited[b] = 1;
                }
                cost[a][b] = cost[b][a] = 999;
            }
        }
    }
    printf("\nmincost = %d", mincost);
}