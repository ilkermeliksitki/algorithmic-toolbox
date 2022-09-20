#include <stdio.h>

int max_index(long double arr[], int n){
    // assuming all items are natural numbers.
    int i, idx = -1;
    long double max_value = -1.0;
    for (i = 0; i < n; ++i){
        if (arr[i] > max_value){
            max_value = arr[i];
            idx = i;
        }
    }
    return idx;
}

long double knapsack(unsigned long int cost[], unsigned long int weight[], int n, unsigned long int W){
    long double unit_price[n];
    for (int i = 0; i < n; ++i){
        scanf("%lu %lu", &cost[i], &weight[i]);
        unit_price[i] = (long double)cost[i] / weight[i];
    }
    
    long double treasure = 0.0;
    int idx;
    while (W > 0){
        idx = max_index(unit_price, n);
        if (weight[idx] <= W && weight[idx] != 0){
            // take all of the item
            W -= weight[idx];
            treasure += weight[idx] * unit_price[idx];
            cost[idx] = 0;
            weight[idx] = 0;
            unit_price[idx] = 0;
        } else {
            // take as the amount of W.
            treasure += W * unit_price[idx];
            unit_price[idx] = 0;
            W = 0;
        }
    }
    return treasure;
}

int main(void){
    int n, i;
    unsigned long int W;
    scanf("%d %ld", &n, &W);

    unsigned long int cost[n], weight[n];
    long double treasure = knapsack(cost, weight, n, W);
    printf("%Lf\n", treasure);

    return 0;
}

