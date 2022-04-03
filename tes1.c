#include <conio.h>
#include <stdio.h>
#include<string.h>
#include <stdbool.h>
int main()
{
    int n, ne = 0, x, y,min_cost=0;
    printf("Enter the no of vertices:");
    scanf("%d", &n);
    int graph[n][n];
    printf("\nEnter the adjacency matrix:");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    bool visited[n];
    memset(visited, false, sizeof(visited));
    visited[0] = true;
    while (ne < n-1)
    {
        int min = 9999; //finding minimum adjacency vertex which is not added to the mst
        x = 0;
        y = 0;
        for (int i = 0; i < n; i++)
        {
            if (visited[i])
            {
                for (int j = 0; j < n; j++)
                {
                    if (graph[i][j] && graph[i][j] < min && !visited[j])
                    {
                        min = graph[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }
        printf("\n(%d,%d) cost:%d", x + 1, y + 1, graph[x][y]);
        min_cost+=min;
        visited[y]=true;
        ne++;
    }

    printf("\nthe total minimum cost is : %d",min_cost); 
    return 0;
}