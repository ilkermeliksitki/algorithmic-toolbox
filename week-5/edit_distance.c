#include <stdio.h>
#include <string.h>


int min(int a, int b, int c){
    int arr[3] = {a, b, c};
    int i, min_value = arr[0];
    for (i = 1; i < 3; i++){
        if (arr[i] < min_value) {
           min_value= arr[i]; 
        }
    }
    return min_value;
}

void print2d(int row, int col, int *arr)
{
    /* helper function for column-wise printing of 2d distance matrix. */
    int i, j;
    for (i = 0; i < col; i++){
        for(j = 0; j < row; j++){
            printf("%4d", *(arr + j * col + i));
        }
        printf("\n");
    }
}

int edit_distance(char A[], int n, char B[], int m)
{
    /**
     * Edit Distance Problem
     * Compute the edit distance between two strings.
     *
     * Input: Two strings.
     * Output: The minimum number of single-symbol insertions, deletions, and
     *     substitutions to transform one string into the other one.
     *
     * Input Format: Two strings consisting of lower case Latin letters, each
     *     on a separate line.
     * Output Format: The edit distance between them.
     *
     * Constraints: The length of both strings is at least 1 and at most 100.
     *
     * Samples:
     *     Input 1: 
     *     short
     *     ports
     *
     *     Output 1:
     *     3
     *
     *     Input 2:
     *     editing
     *     distance
     *
     *     Output 2: 
     *     5
     *
     *     Input 3:
     *     ab
     *     Output 3:
     *     0
     */
    int D[n+1][m+1];
    int i, j;
    for (i = 0; i < n+1; i++){
        D[i][0] = i;
    }
    for (j = 0; j < m+1; j++){
        D[0][j] = j;
    }

    int insertion, deletion, match, mismatch;
    for (j = 1; j < m+1; j++){
        for (i = 1; i < n+1; i++){
            insertion = D[i  ][j-1] + 1;
            deletion =  D[i-1][j  ] + 1;
            match =     D[i-1][j-1];
            mismatch =  D[i-1][j-1] + 1;

            if (A[i-1] == B[j-1])
                D[i][j] = min(insertion, deletion, match);
            else
                D[i][j] = min(insertion, deletion, mismatch);
        }
    }
    
//    print2d(n+1, m+1, (int *)D);
    return D[n][m];
}

int main(void)
{
    char A[101], B[101];
    scanf("%s %s", A, B);
    printf("%d\n", edit_distance(A, strlen(A), B, strlen(B)));
    return 0;
}

