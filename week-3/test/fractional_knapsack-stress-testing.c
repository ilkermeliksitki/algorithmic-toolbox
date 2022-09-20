#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

long double knapsack(unsigned long int cost[], unsigned long int weight[], int n, unsigned long int W, long double unit_price[]){
    long double treasure = 0.0;
    int idx;
    while (W > 0){
        idx = max_index(unit_price, n);
        if (weight[idx] <= W && weight[idx] != 0){
            // take all of the item
            W -= weight[idx];
            treasure += (long double)weight[idx] * (long double)unit_price[idx];
            cost[idx] = 0;
            weight[idx] = 0;
            unit_price[idx] = 0;
        } else {
            // take as the amount of W.
            treasure += (long double)W * (long double)unit_price[idx];
            unit_price[idx] = 0;
            W = 0;
        }
    }
    return treasure;
}

long double knapsack2(unsigned long int cost[], unsigned long int weight[], int n, unsigned long int W, long double unit_price[]){
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
    /* Stress testing was applied and eventually two functions become equal. 
     * and that function was submitted. */
    int cond = 1;
    while (cond) {
        int n = rand() % 10 + 1;
        int W = rand() % 20 + 30;

        unsigned long int cost[n], weight[n];
        int i;
        for (i = 0; i < n; ++i) {
            cost[i] = rand() % 60 + 70;
            weight[i] = rand() % 10 + 25;
        }

        long double unit_price[n];
        for (i = 0; i < n; ++i) {
            unit_price[i] = (long double)cost[i] / weight[i];
        }

        printf("\nW: %d\n", W);
        printf("cost: ");
        for (i = 0; i < n; ++i)
            printf("%lu ", cost[i]);

        printf("\nweight: ");
        for (i = 0; i < n; ++i)
            printf("%lu ", weight[i]);
        
        printf("\nunit_price: ");
        for (i = 0; i < n; ++i)
            printf("%Lf ", unit_price[i]);
        printf("\n");

        // copy arrays for two function because the knapsack functions modify the array.
        unsigned long int cost2[n], weight2[n];
        long double unit_price2[n]; 
        for (i = 0; i < n; ++i){
            cost2[i] = cost[i];
            weight2[i] = weight[i];
            unit_price2[i] = unit_price[i];
        }
 
        long double treasure = knapsack(cost, weight, n, W, unit_price);
        long double treasure2 = knapsack2(cost2, weight2, n, W, unit_price2);
        printf("knapsack: %Lf - knapsack2: %Lf", treasure, treasure2);

        if (fabs(treasure - treasure2 < 0.0001))
            /* this part is for the precision of the return values of two functions. */
            printf("\nOK\n");
        else{
            printf("\nSTOP\n");
            cond = 0;
        }
    } 
    return 0;
}

