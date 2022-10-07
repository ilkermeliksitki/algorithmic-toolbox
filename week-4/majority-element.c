#include <stdio.h>

int majority_element(long int A[], long int n){
    /**
     * Majority Element Problem.
     * Check whether a given squence of numbers contains an element that appears
     * more than half of the times.
     * 
     * Input: A sequence of `n` integers.
     * Output: 1 if there is an element that is repeated more than `n/2` times,
     *         and 0 otherwise.
     *
     * Input Format: The first line contains an integer `n` the next one contains
     * a sequence of `n` non-negative integers. a_0, a_1, ..., a_(n-1).
     * Output Format: Output 1 if the sequence contains an element that appears
     * more than `n/2` times and 0 otherwise
     *
     * Constraints: 1 <= n <= 10^5; 0 <= a_i <= 10^9 for all 0 <= i < n
     *
     * Samples: 
     *     Input 1:
     *     5
     *     2 3 9 2 2
     *     Output 1:
     *     1
     *
     *     2 is the majority element.
     *
     *     Input 2:
     *     4
     *     1 2 3 1
     *     Output 2:
     *     0
     *
     *     This sequence does not have a majority element. Note that the element 1 is
     *     not a majority element.
     *
     * Boyer–Moore majority vote algorithm is used in this function.
     */

    /* determination of candidate */
    long int idx = 0, count = 1, i;
    for (i = 0; i < n; ++i){
        if (A[i] == A[idx]) 
            count += 1;
        else
            count -= 1;

        if (count == 0){
            idx = i;
            count += 1;
        }
    }
    long int candidate = A[idx];

    /* traverse part for getting the number of occurence */
    count = 0;
    for (i = 0; i < n; ++i){
        if (A[i] == candidate)
            count += 1;
    }

    if (count > (n / 2))
        /* the condition where there is a majority element. */
        return 1;
    else
        return 0;
}


int main(void){
    /* taking inputs */
    long int n;
    scanf("%ld", &n);
    long int A[n];
    for (int i = 0; i < n; ++i)
        scanf("%ld", &A[i]);

    /* printing the result */
    printf("%d\n", majority_element(A, n));
    return 0;
}
