#include <stdio.h>


void print2d_array(int *arr, int row, int col)
{
    int i, j;
    for (i = 0; i < row; i++){
        for (j = 0; j < col; j++){
            printf("%4d", *(arr + i * col + j));
        }
        printf("%c", '\n');
    }
}

int lcs2(long int x[], int n, long int y[], int m)
{
    /*
     * Longest Common Subsequence of Two Sequences Problem
     * Compute the maximum length of a common subsequence of two sequences.
     *
     * Input: Two sequences
     * Output: The maximum length of a common subsequences
     *
     * Input Format: First line: n. Second line: a_1, a_2, ... , a_n
     *     Third line: m. Fourth line: b_1, b_2, ... , b_m
     * Output Format: p, where the number of LCS.
     *
     * Constraints: 1 <= n, m <= 100; -10^9 <= a_i, b_i, <= 10^9 for all i.
     *
     * Samples:
     *     Input 1:
     *     3
     *     2 7 5
     *     2
     *     2 5
     *
     *     Output 1:
     *     2
     *
     *
     *     Input 2:
     *     1
     *     7
     *     4
     *     1 2 3 4
     *
     *     Output 2:
     *     0
     *     
     *
     *     Input 3:
     *     4
     *     2 7 8 3
     *     4
     *     5 2 8 7
     *
     *     Output 3:
     *     2
     *
     * Let's C[i][j] be the length of LCS of the given sequences X_i and Y_j.
     *
     *           /
     *           | 0                                  if i = 0 or j = 0
     * C[i][j] = | C[i - 1][j - 1] + 1                if i, j > 0 and x_i  = y_j
     *           | max{C[i][j - 1], C[i - 1][j]}      if i, j > 0 and x_i != y_j
     *           \
     * , where x_i and y_i are the elements of the sequences X_i and Y_j respectively.
     *
     * Ref: Introduction to Algorithms CLRS 4th Ed, p:396
     *
     */
    int C[n + 1][m + 1];
    int i;
    for (i = 1; i <= n; i++)
        C[i][0] = 0;
    int j;
    for (j = 0; j <= m; j++)
        C[0][j] = 0;

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            if (x[i - 1] == y[j - 1]){
                C[i][j] = C[i - 1][j - 1] + 1;
            }
            else if (C[i - 1][j] <= C[i][j - 1]) {
                C[i][j] = C[i][j - 1];
            } else {
                C[i][j] = C[i - 1][j];
            }
        }
    }
        
//  print2d_array((int *)C, n + 1, m + 1);
    return C[n][m];
}


int main(void)
{
    int n, i;
    scanf("%d", &n);
    long int seq1[n];
    for (i = 0; i < n; i++){
        scanf("%ld", &seq1[i]);
    }

    int m;
    scanf("%d", &m);
    long int seq2[m];
    for (i = 0; i < m; i++){
        scanf("%ld", &seq2[i]);
    }

    int r = lcs2(seq1, n, seq2, m);
    printf("%d\n", r);
    return 0;
}
