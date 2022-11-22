#include <stdio.h>
#include <stdlib.h>

int knapsack(int W, int weights[], int n)
{
    /*
     * Maximum Amount of Gold Problem
     * Given a set of gold bars of various weights and a backpack that can hold
     * at most W pounds, place as much gold as possible into the backpack.
     *
     * Input: A set of `n` gold bars of integer weights w_1, ... , w_n and a 
     *     backpack that can hold at most W pounds.
     * Output: A subset of gold bars of maximum total weight not exceeding `W`
     *
     * Input Format: The first line of the input contains an integer `W` (capacity
     *     of the backpack) and the number `n` of gold bars. The next line contains
     *     `n` integers w_1, ... , w_n defining the weights of the gold bars.
     * Output Format: The maximum weight of gold bars that fits into a backpack of
     *     capacity `W`.
     *
     * Constraints: 1 <= W <= 10^4; 1 <= n <= 300; 0 <= w_1, ... , w_n <= 10^5
     *
     * Sample:
     *     Input:
     *     10 3
     *     1 4 8
     *
     *     Output:
     *     9
     */

    /* create dynamically pointer array because of size limitation of the stack. */
    int* value[n+1], k;
    for (k = 0; k < n + 1; k++) {
        value[k] = (int *)malloc( (W + 1) * sizeof(int));
    }
  
    int i, w, val;
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            /* initialization part for the first rown and column */
            if (i == 0 || w == 0) {
                value[i][w] = 0;
                continue;
            }
            
            /* note that the value of gold is proportional to its weight.*/
            value[i][w] = value[i - 1][w];
            if (weights[i - 1] <= w) {
                val = value[i - 1][w - weights[i - 1]] + weights[i - 1];
                if (value[i][w] < val) {
                    value[i][w] = val;
                }
            }
        }
    }

    int result = value[n][W];

    /* free up the allocated memory parts */
    for (k = 0; k < n + 1; k++) {
        free(value[k]);
    }
    return result;
}

int main(void)
{
    int W, n;
    scanf("%d %d", &W, &n);

    int weights[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &weights[i]);
    }

    int r = knapsack(W, weights, n);
    printf("%d\n", r);
    return 0;
}
