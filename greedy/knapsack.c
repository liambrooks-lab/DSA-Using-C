#include <stdio.h>

#define MAX 100

int max(int a, int b) { return (a > b) ? a : b; }

int main(void) {
    int n, W;
    int wt[MAX], val[MAX];
    int dp[MAX + 1][1001];

    printf("Enter the number of items (max %d): ", MAX);
    scanf("%d", &n);

    printf("Enter the knapsack capacity (max 1000): ");
    scanf("%d", &W);

    for (int i = 1; i <= n; i++) {
        printf("Item %d - enter weight and value: ", i);
        scanf("%d %d", &wt[i], &val[i]);
    }

    /* Build the DP table bottom-up */
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (wt[i] <= w)
                dp[i][w] = max(val[i] + dp[i - 1][w - wt[i]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    printf("\nMaximum value attainable: %d\n", dp[n][W]);

    /* Backtrack to identify the selected items */
    printf("Items selected: ");
    int w = W;
    for (int i = n; i > 0; i--) {
        if (dp[i][w] != dp[i - 1][w]) {
            printf("%d ", i);
            w -= wt[i];
        }
    }
    printf("\n");
    return 0;
}