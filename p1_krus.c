#include <stdio.h>
#include <stdlib.h>

struct Edge
{
    int u, v, w;
};

int parent[100];

int find(int i)
{
    while(parent[i] != i)
        i = parent[i];

    return i;
}

void unionSet(int a, int b)
{
    parent[a] = b;
}

int compare(const void *a, const void *b)
{
    return ((struct Edge*)a)->w -
           ((struct Edge*)b)->w;
}

int main()
{
    int n = 6;
    int e = 9;

    struct Edge edges[] =
    {
        {3,0,6}, // D-A
        {0,1,5}, // A-B
        {1,2,2}, // B-C
        {0,2,2}, // A-C
        {4,2,3}, // E-C
        {3,4,3}, // D-E
        {4,0,4}, // E-A
        {5,3,7}, // F-D
        {5,4,8}  // F-E
    };

    char vertex[] = {'A','B','C','D','E','F'};

    for(int i=0;i<n;i++)
        parent[i]=i;

    qsort(edges,e,sizeof(edges[0]),compare);

    int mincost=0;

    printf("Edges in MST:\n");

    for(int i=0;i<e;i++)
    {
        int a = find(edges[i].u);
        int b = find(edges[i].v);

        if(a != b)
        {
            printf("%c -- %c = %d\n",
                   vertex[edges[i].u],
                   vertex[edges[i].v],
                   edges[i].w);

            mincost += edges[i].w;

            unionSet(a,b);
        }
    }

    printf("\nMinimum Cost = %d\n", mincost);

    return 0;
}