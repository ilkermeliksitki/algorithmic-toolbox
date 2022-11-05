#include <stdio.h>

int min(int a, int b){
    if (a < b) {
        return a;
    }
    return b;
}

void print2d(int *arr, int row, int col)
{
    int i, j;
    for (i = 0; i < row; i++){
        for (j = 0; j < col; j++){
            printf("%3d", *(arr + i * col + j));
        }
        printf("%c", '\n');
    }
}

int change(int n, int coins[], int size)
{
    /*
     * Money Change Again Problem
     * Compute the minimum number of coins needed to change the given
     * value into coins with denominations 1, 3, and 4.
     *
     * Input Format: Integer money.
     * Output Format: The minimum number of coins with denominations 1, 3,
     *     and 4 that changes money.
     *
     * Constraints: 1 <= money <= 10^3
     *
     * Samples:
     *     Input:
     *     34
     *
     *     Output:
     *     9
     */
   int A[size][n + 1]; 
   int i, j;
   for (i = 0; i < size; ++i) {
       A[i][0] = 0;
   }

   for (j = 1; j < n + 1; ++j) {
       A[0][j] = j;
   }

   for (i = 1; i < size; ++i) {
        for (j = 1; j < n + 1; ++j) {
            if (coins[i] > j) {
                A[i][j] = A[i - 1][j];
            } else {
                A[i][j] = min(A[i - 1][j], 1 + A[i][j - (coins[i])]);
            }
        }
   }
   //print2d((int *)A, size, n+1);
   return A[size - 1][n];
}

int main(void)
{
    int coins[] = {1, 3, 4};
    int s = sizeof(coins) / sizeof(coins[0]);
    int num;
    scanf("%d", &num);
    int r = change(num, coins, s);
    printf("%d\n", r);
    return 0;
}

