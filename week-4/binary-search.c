#include <stdio.h>
    
int binary_search(long long int A[], int q, int size){
    /* return the index of searched array */
    int min_idx = 0;
    int max_idx = size - 1;
    int mid_idx;
    while (max_idx >= min_idx){
        mid_idx = (min_idx + max_idx) / 2;
        if (A[mid_idx] == q)
            return mid_idx;
        else if (A[mid_idx] < q)
            min_idx = mid_idx + 1;
        else
            max_idx = mid_idx - 1;
    }
    return -1;
}

int main(void){
    /* taking inputs */
    int n;
    scanf("%d", &n);
    long long int A[n];
    int i;
    for (i = 0; i < n; ++i)
        scanf("%lld", &A[i]);

    /* printing output */
    int m;
    scanf("%d", &m);
    long long int q;
    for(i = 0; i < m; ++i){
        scanf("%lld", &q);
        printf("%d ", binary_search(A, q, n));
    }
    printf("\n");

    return 0;
}
