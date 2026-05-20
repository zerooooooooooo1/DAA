#include <stdio.h>

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int main()
{
    int n = 4;
    int W = 8;

    int wt[]  = {2, 3, 4, 5};
    int val[] = {10, 20, 50, 60};

    int dp[10][10];

    for(int i = 0; i <= n; i++)
    {
        for(int w = 0; w <= W; w++)
        {
            if(i == 0 || w == 0)
            {
                dp[i][w] = 0;
            }

            else if(wt[i-1] <= w)
            {
                dp[i][w] = max(
                                dp[i-1][w],
                                val[i-1] +
                                dp[i-1][w-wt[i-1]]
                               );
            }

            else
            {
                dp[i][w] = dp[i-1][w];
            }
        }
    }

    printf("Maximum value = %d\n\n", dp[n][W]);

    printf("Selected Objects:\n");

    int w = W;

    for(int i = n; i > 0 && w > 0; i--)
    {
        if(dp[i][w] != dp[i-1][w])
        {
            printf("Object %d\n", i);

            w = w - wt[i-1];
        }
    }

    return 0;
}