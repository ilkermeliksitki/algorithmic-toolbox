#include <stdio.h>

int knapsack(int W, int weights[], int price[], int n)
{
    /*
     * let value(w) be the maximum value of knapsack of weight w.
     *
     * value(w) = max{value(w - w_i) + v_i} where for all i w_i <= w.
     * and v_i is the value of the item of weight w_i.
     *
     */
    int value[W+1], val;
    value[0] = 0;
    for (int w = 1; w <= W; w++) {
        value[w] = 0;
        for (int i = 0; i < n; i++) {
            if (weights[i] <= w) {
                val = value[w  - weights[i]] + price[i];
                if (val > value[w]){
                    value[w] = val;
                }
            }
        }
    }
    
    for (int i = 0; i < W+1; i++) {
        printf("%d ", value[i]);
    }
    printf("\n");
    return value[W];
}

int main(void)
{
    int n, W;
    scanf("%d %d", &n, &W);

    int weights[n], price[n];
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &weights[i], &price[i]);
    }

    int r = knapsack(W, weights, price, n);
    printf("%d\n", r);
    return 0;
}
