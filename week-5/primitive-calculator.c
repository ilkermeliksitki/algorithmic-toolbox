#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>


int min(int n, ...)
{
    /*
     * variadic functions finding the minimum of the presented
     * arguments.
     */
    va_list args;
    va_start(args, n);
    int minimum = 99999, c;

    for (int i = 0; i < n; ++i) {
        c = va_arg(args, int);
        if (c < minimum)
            minimum = c;
    }

    va_end(args);
    return minimum;
}

void print_array(int array[], size_t len)
{
    for (size_t i = 0; i < len; ++i) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void print_steps(int A[], int n, int r)
{
    /*
     * Finds the best possible steps and store them into the array
     * R. First conditions is making use of DP array A, whereas 
     * the other conditions are trivial.
     */
    int R[r + 1];
    R[r] = n;
    for (int i = r - 1; n > 1; i--) {
        if (A[n] == A[n - 1] + 1) {
            n = n - 1;
        } else if (n % 3 == 0) {
            n = n / 3;
        } else if (n % 2 == 0) {
            n = n / 2;
        }
        R[i] = n;
    }
    print_array(R, r + 1);
}

int *primitive_calculator(int n, int *result)
{
    /*
     * Primitive Calculator Problem
     * Find the minimum number of operations needed to get a positive
     * integer n from 1 by using only three operationss: add 1, multiply
     * by 2, and multiply by 3.
     *
     * Input: An integer n
     * Output: The minimum number of operations "+1", "x2" and "x3"
     *     needed to get n from 1.
     *
     * Input Format: An integer n.
     * Output Format: In the first line, output the minimum number k of
     *    operations needed to get n from 1. In the second line, output
     *    a sequence of intermediate numbers. That is, the second line
     *    should contain positive integers a_0, a_1, ... , a_k such that
     *    a_0 = 1, a_k = n and for all 1 <= i <= k, a_i is equal to either
     *    a_{i-1} + 1, 2a_{i-1}, or 3a_{i-1}, If there are many such
     *    sequences, output any one of them.
     *
     * Constraints: 1 <= n <= 10^6
     *
     * Samples:
     *     Input 1:
     *     1
     *
     *     Output 1:
     *     0
     *     1
     *
     *
     *     Input 2:
     *     96234
     *
     *     Output 2:
     *     14
     *     1 2 6 7 21 22 66 198 594 1782 5346 16038 16039 32078 96234
     *
     *     etc...
     *
     */
    if (n == 1){
        int *A = (int *)malloc(1 * sizeof(int));
        *result = 0;
        return A;
    }

    int *A = (int *)malloc( (n + 1) * sizeof(int) );
    int j;
    A[0] = 0;
    for (j = 1; j < n + 1; j++) {
        if (j == 1 || j == 2 || j == 3){
            A[j] = 1;
            continue;
        } else {
            if (j % 3 == 0 && j % 2 == 0) {
                A[j] = 1 + min(3, A[j / 3], A[j / 2], A[j - 1]);
            } else if (j % 3 == 0) {
                A[j] = 1 + min(2, A[j / 3], A[j - 1]);
            } else if (j % 2 == 0) {
                A[j] = 1 + min(2, A[j / 2], A[j - 1]);
            } else {
                A[j] = 1 + A[j - 1];
            }
        }
    }
    *result = A[n];
    return A;
}

int main(void)
{
    int n;
    scanf("%d", &n);
    /* 
     * r will store the number of operations, whereas A will store
     * operations' themselves.
     */
    int r;
    int *A = primitive_calculator(n, &r);
    printf("%d\n", r);
    print_steps(A, n, r);

    free(A);
    return 0;
}

