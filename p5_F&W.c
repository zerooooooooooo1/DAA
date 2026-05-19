#include <stdio.h>

#define INF 999

int main()
{
    int n = 4;

    char vertex[] = {'a','b','c','d'};

    int dist[4][4] =
    {
        //a    b    c    d

        {0,   INF, 3,   INF}, // a
        {2,   0,   INF, INF}, // b
        {INF, 7,   0,   1},   // c
        {6,   INF, INF, 0}    // d
    };

    for(int k = 0; k < n; k++)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(dist[i][k] + dist[k][j]
                   < dist[i][j])
                {
                    dist[i][j] =
                    dist[i][k] +
                    dist[k][j];
                }
            }
        }
    }

    printf("All Pairs Shortest Path Matrix:\n\n");

    printf("    ");

    for(int i=0;i<n;i++)
        printf("%4c", vertex[i]);

    printf("\n");

    for(int i = 0; i < n; i++)
    {
        printf("%4c", vertex[i]);

        for(int j = 0; j < n; j++)
        {
            if(dist[i][j] == INF)
                printf("%4s","INF");
            else
                printf("%4d",dist[i][j]);
        }

        printf("\n");
    }

    return 0;
}





#include <stdio.h>

#define n 4

int main()
{
    char vertex[] = {'a','b','c','d'};

    int reach[n][n] =
    {
        //a b c d

        {0,0,1,0}, // a
        {1,0,0,0}, // b
        {0,1,0,1}, // c
        {1,0,0,0}  // d
    };

    for(int k = 0; k < n; k++)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                reach[i][j] =
                reach[i][j] ||
                (reach[i][k] &&
                 reach[k][j]);
            }
        }
    }

    printf("Transitive Closure Matrix:\n\n");

    printf("    ");

    for(int i=0;i<n;i++)
        printf("%3c", vertex[i]);

    printf("\n");

    for(int i = 0; i < n; i++)
    {
        printf("%3c", vertex[i]);

        for(int j = 0; j < n; j++)
        {
            printf("%3d", reach[i][j]);
        }

        printf("\n");
    }

    return 0;
}