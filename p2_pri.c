#include <stdio.h>

#define INF 999

int main()
{
    int n = 5;

    int cost[5][5] = {
        {INF,2,INF,6,INF},
        {2,INF,3,8,5},
        {INF,3,INF,INF,7},
        {6,8,INF,INF,9},
        {INF,5,7,9,INF}
    };

    int visited[5]={0};

    visited[0]=1;

    int edges=0,mincost=0;

    printf("Edges in MST:\n");

    while(edges < n-1)
    {
        int min=INF,a=-1,b=-1;

        for(int i=0;i<n;i++)
        {
            if(visited[i])
            {
                for(int j=0;j<n;j++)
                {
                    if(!visited[j] && cost[i][j]<min)
                    {
                        min=cost[i][j];
                        a=i;
                        b=j;
                    }
                }
            }
        }

        printf("%d -- %d = %d\n",a,b,min);

        mincost += min;
        visited[b]=1;
        edges++;
    }

    printf("Minimum Cost = %d\n",mincost);

    return 0;
}