#include <stdio.h>


int greedy_calculator(int n)
{
    /*
     * Greedy Primitive Calculator
     * Finds the minimum number of operation needed to get a positive integer
     * `n` from 1 by using only three operations: add 1, multiply by 2 and
     * multiply by 3.
     *
     * Unfortunately, this algorithm fails in the following cases.
     *     20 = x3 x3 x2 +1 +1 <= 5 operations.
     * But the optimal solution is:
     *     20 = x3 x3 +1 x2    <= 4 operations.
     *
     *     90 = x3 x3 x3 x3 +1 +1 +1 +1 +1 +1 +1 +1 +1 <= 13 operations. (greedy)
     *     90 = x3 x3 +1 x3 x3 <= 5 operations (optimal)
     *
     *     etc.
     *
     * A new approach is needed.
     *
     */
    int number_of_operations = 0;
    int current_number = 1;

    while (current_number < n) {
        if (current_number <= n/3) {
            current_number = 3 * current_number;
            printf("%3s", "x3");
        } else if (current_number <= n/2){
            current_number = 2 * current_number;
            printf("%3s", "x2");
        } else{
            current_number = 1 + current_number;
            printf("%3s", "+1");
        }

        number_of_operations += 1;
    }

    return number_of_operations;
}


int main(void)
{
    int n;
    scanf("%d", &n);
    printf("\n%d\n", greedy_calculator(n));
    return 0;
}
