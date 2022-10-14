#include <stdio.h>

void merge(long int A[], long int p, long int q, long int r){
    /*
     * The algorithm assumes that the sub arrays(A[p:q] and A[q + 1:r]) are aldready sorted.
     */
    long int n_l = q - p + 1;   // length of A[p:q]
    long int n_r = r - q;       // length of A[q + 1:r]

    int i, j, k;
    long int L[n_l], R[n_r];
    for (i = 0; i < n_l; ++i)
        L[i] = A[p + i];
    for (j = 0; j < n_r; ++j)
        R[j] = A[q + 1 + j];

    /* As long as each array L and R contain an element, copy the smallest one back to A[p:r] */
    i = 0; j = 0; k = p;
    while (i < n_l && j < n_r) {
        if (L[i] <= R[j]){
            A[k] = L[i];
            i += 1;
            k += 1;
        } else {
            A[k] = R[j];
            j += 1;
            k += 1;
        }
    }

    /* copy the remaining element from one of the unmerged array(the other one is aldready copied) */
    while (i < n_l) {
        A[k] = L[i];
        i += 1;
        k += 1;
    }
    while (j < n_r) {
        A[k] = R[j];
        j += 1;
        k += 1;
    }
}

void merge_sort(long int A[], long int p, long int r){
    if (p >= r)                 // zero or one element.
        return;
    long int q = (p + r) / 2;   // midpoint
    merge_sort(A, p, q);        // recursively sort A[p:q]
    merge_sort(A, q + 1, r);    // recursively sort A[q + 1:r]
    
    merge(A, p, q, r);
}


int main(void){
    long int n;
    scanf("%ld", &n);
    long int A[n];
    for (int i = 0; i < n; ++i) {
        scanf("%ld", &A[i]);
    }
    merge_sort(A, 0, n);
    for (int i = 0; i < n; ++i) {
        printf("%ld ", A[i]);
    }
    printf("\n");

    return 0;
}
