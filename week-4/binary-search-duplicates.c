#include <stdio.h>

int binary_search_duplicates(long long int A[], long long int q, int size){
    int min_idx = 0;
    int max_idx = size - 1;
    int mid_idx;
    while (max_idx >= min_idx){
        mid_idx = (min_idx + max_idx) / 2;
        if (A[mid_idx] == q){
            /* check for duplicates */
            while (A[mid_idx] == q){
                mid_idx -= 1;
            }
            return mid_idx + 1;
        }
        else if (A[mid_idx] < q)
            min_idx = mid_idx + 1;
        else
            max_idx = mid_idx - 1;
    }
    return -1;
}


int main(void){
    int n;
    scanf("%d", &n);
    long long int A[n];
    int i;
    for (i = 0; i < n; ++i)
        scanf("%lld", &A[i]);

    int m;
    scanf("%d", &m);
    long long int q;
    for (i = 0; i < m; ++i){
        scanf("%lld", &q);
        printf("%d ", binary_search_duplicates(A, q, n));
    }
    printf("\n");
    
    return 0;
}

