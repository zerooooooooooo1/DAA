#include <stdio.h>

#define INF 999

int main()
{
    int n = 7;

    char *city[] = {
        "San Francisco",
        "Los Angeles",
        "Denver",
        "Dallas",
        "Chicago",
        "New York",
        "Boston"
    };

    int graph[7][7] = {

    //SF  LA  DE  DA  CH  NY  BO

    {0,  3,  4, INF, 5, INF, INF}, // SF
    {3,  0,  7, 5, INF, INF, INF}, // LA
    {4,  7,  0, 4, 6, INF, INF},   // Denver
    {INF,5,  4, 0, 5, 6, INF},     // Dallas
    {5, INF,6, 5, 0, 4, 3},        // Chicago
    {INF,INF,INF,6,4,0,2},         // New York
    {INF,INF,INF,INF,3,2,0}        // Boston
    };

    int visited[7] = {0};
    int dist[7];

    for(int i = 0; i < n; i++)
        dist[i] = INF;

    dist[0] = 0;

    for(int count = 0; count < n-1; count++)
    {
        int min = INF, u;

        for(int i = 0; i < n; i++)
        {
            if(!visited[i] && dist[i] < min)
            {
                min = dist[i];
                u = i;
            }
        }

        visited[u] = 1;

        for(int v = 0; v < n; v++)
        {
            if(!visited[v] &&
               graph[u][v] != INF &&
               dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printf("Shortest distance from San Francisco:\n\n");

    for(int i = 0; i < n; i++)
    {
        printf("To %-15s = %d sec\n",
               city[i],
               dist[i]);
    }

    return 0;
}