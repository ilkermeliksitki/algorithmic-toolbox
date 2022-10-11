#include <stdio.h>
#include <stdlib.h>

void swap(long int *x, long int *y){
    long int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void partition3(long int A[], long int p, long int r, long int *q1, long int *q2){
    /* 
     * Dijkstra's Dutch national flag problem's algorithm is used.
     */
    long int idx = rand() % (r - p) + p;
    swap(&A[r - 1], &A[idx]);

    long int i = 0, j = 0, k = r - 1;
    long int x = A[r - 1];
    while (j <= k) {
        if (A[j] < x) {
            swap(&A[i], &A[j]);
            i += 1;
            j += 1;
        } else if (A[j] > x){
            swap(&A[j], &A[k]);
            k -= 1;
        } else {
            j += 1;
        }
    }

    *q1 = i;
    *q2 = j-1;
}
void randomized_quick_sort(long int A[], long int p, long int r){
    /*
     * Speeding Up Randomized-Quick-Sort
     * Sort a given sequence of numbers (that may contain duplicates) using a
     * modification of randomized quick sort algorithm (one-partitioning) that
     * works in O(nlogn) expected time.
     *
     * Input: An integer array with `n` elements that may contain duplicates.
     * Output: Sorted array (generated using a modification of randomized quick
     *     sort) that works in O(nlogn) expected time.
     *
     * Input Format: The first line of the input contains an integer `n`. The
     *     next line contains a sequence of `n` integers a_0, a_1, ... a_(n-1).
     * Output Format: Output this sequence sorted in non-decreasing order.
     *
     * Constraints: 1 <= n <= 10^5; 0 <= a_i <= 10^9 for all 0 <= i < n
     *
     * Sample:
     *     Input:
     *     5
     *     2 3 9 2 2
     *     Output:
     *     2 2 2 3 9
     */
    if (p < r){
        long int q1, q2;
        partition3(A, p, r, &q1, &q2);
        randomized_quick_sort(A, p, q1);      // note that q1 is not included!
        randomized_quick_sort(A, q2 + 1, r);
    }
}


int main(void){
    long int n, i;
    scanf("%ld", &n);
    long int A[n];
    for (i = 0; i < n; ++i)
        scanf("%ld", &A[i]);

    randomized_quick_sort(A, 0, n);
    for (i = 0; i < n; ++i)
        printf("%ld ", A[i]);
    printf("\n");

    return 0;
}
