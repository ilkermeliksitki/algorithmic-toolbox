#include <stdio.h>

void print2d_array(int *arr, int row, int col)
{
    int i, j;
    for (i = 0; i < row; i++){
        for (j = 0; j < col; j++){
            printf("%4d", *(arr + i * col + j));
        }
        printf("%c", '\n');
    }
}

int knapsack(int W, int weights[], int prices[], int n)
{
    int value[n + 1][W + 1];
    int i, w, val;
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            /* initialization part for the first column and row. */
            if (i == 0 || w == 0) {
               value[i][w] = 0;
               continue;
            }
            
            /* note that w_i = weights[i - 1], v_i = prices[i - 1] */
            value[i][w] = value[i - 1][w];
            if (weights[i - 1] <= w) {
                val = value[i - 1][w - weights[i - 1]] + prices[i - 1];
                if (value[i][w] < val) {
                    value[i][w] = val;
                }
            }
        }
    }
        
    print2d_array((int *)value, n + 1, W + 1);

    printf("\n%s", "The optimal solution is: ");
    i = n, w = W;
    while (i > 0 && w > 0) {
        if (value[i - 1][w - weights[i - 1]] + prices[i - 1] > value[i - 1][w]) {
            printf("%2d", weights[i - 1]);
            w = w - weights[i - 1];
            i--;
        } else {
            i--;
        }
    }
    return value[n][W];
}

int main(void)
{
    int n, W;
    scanf("%d %d", &n, &W);

    int weights[n], prices[n];
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &weights[i], &prices[i]);
    }

    int r = knapsack(W, weights, prices, n);
    printf("\n%d\n", r);
    return 0;
}
