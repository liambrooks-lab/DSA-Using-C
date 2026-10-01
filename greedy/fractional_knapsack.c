#include <stdio.h>

#define MAX 100

int main(void) {
    int n;
    float W;
    float wt[MAX], val[MAX], ratio[MAX];
    int idx[MAX];

    printf("Enter the number of items (max %d): ", MAX);
    scanf("%d", &n);

    printf("Enter the knapsack capacity: ");
    scanf("%f", &W);

    for (int i = 0; i < n; i++) {
        printf("Item %d - enter weight and value: ", i + 1);
        scanf("%f %f", &wt[i], &val[i]);
        ratio[i] = val[i] / wt[i];
        idx[i] = i;
    }

    /* Sort indices by value-to-weight ratio, descending */
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (ratio[idx[j]] < ratio[idx[j + 1]]) {
                int t = idx[j];
                idx[j] = idx[j + 1];
                idx[j + 1] = t;
            }
        }
    }

    float total = 0.0f, remaining = W;
    printf("\nItem\tFraction taken\n");
    for (int k = 0; k < n && remaining > 0; k++) {
        int i = idx[k];
        if (wt[i] <= remaining) {
            total += val[i];
            remaining -= wt[i];
            printf("%d\t1.00\n", i + 1);
        } else {
            float frac = remaining / wt[i];
            total += val[i] * frac;
            printf("%d\t%.2f\n", i + 1, frac);
            remaining = 0;
        }
    }

    printf("\nMaximum value attainable: %.2f\n", total);
    return 0;
}