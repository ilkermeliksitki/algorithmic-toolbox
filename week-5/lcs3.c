#include <stdio.h>

void fill_array(long int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)    
        scanf("%ld", &arr[i]);
}

long int max(long int a, long int b)
{
    if (a > b)
        return a;
    return b;
}

int lcs3(long int x[], int n, long int y[], int m, long int z[], int l)
{
    /*
     * Longest Common Subsequence of Three Sequences Problem
     * Compute the maximum length of a common subsequence of three suquences.
     *
     * Input: Three sequences.
     * Outpu: The maximum length of a common subsequence.
     *
     * Input Format: First line: n. Second line: a_1, a_2, ... , a_n
     *     Third line: m. Fourth line: b_1, b_2, ... , b_m. Fifth line: l
     *     Sixth line: c_1, c_2, ... , c_l.
     * Output Format: p, the length of common subsequence.
     *
     * Constraints: 1 <= n, m, l <= 100; -10^9 <= a_i, b_i, c_i <= 10^9
     *
     * Samples:
     *     Input 1:
     *     3
     *     1 2 3
     *     3
     *     2 1 3
     *     3
     *     1 3 5
     *
     *     Output 1:
     *     2
     *
     *     
     *     Input 2:
     *     5
     *     8 3 2 1 7
     *     7
     *     8 2 1 3 8 10 7
     *     6
     *     6 8 3 1 4 7
     *
     *     Output 2:
     *     3
     *
     */
    int C[n + 1][m + 1][l + 1];
    int i, j, k;
    for (i = 0; i < n + 1; i++) {
        for (j = 0; j < m + 1; j++) {
            for (k = 0; k < l + 1; k++) {
                if (i == 0 || j == 0 || k == 0) {
                    /* if one of the word is missing, there is no LCS. */
                    C[i][j][k] = 0;                    
                } else if (x[i - 1] == y[j - 1] && y[j - 1] == z[k - 1]) {
                    /*
                     * if the last element is same, then the LCS is  
                     * 1 + LCS of X_(i - 1), Y_(j - 1) Z_(k - 1)
                     */
                    C[i][j][k] = C[i - 1][j - 1][k - 1] + 1;
                } else {
                    C[i][j][k] = max(max(C[i - 1][j][k], C[i][j - 1][k]), C[i][j][k - 1]);
                }
            }
        }
    }
    return C[n][m][l];
}

int main(void)
{
    int n;
    scanf("%d", &n);
    long int seq1[n];
    fill_array(seq1, n);

    int m;
    scanf("%d", &m);
    long int seq2[m];
    fill_array(seq2, m);

    int l;
    scanf("%d", &l);
    long int seq3[l];
    fill_array(seq3, l);

    int r = lcs3(seq1, n, seq2, m, seq3, l);
    printf("%d\n", r);
    return 0;
}
