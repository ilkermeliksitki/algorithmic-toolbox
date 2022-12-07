#include <stdio.h>
#include <string.h>
#define MAXLENGTH 30

long long int m[MAXLENGTH][MAXLENGTH];
long long int M[MAXLENGTH][MAXLENGTH];

long long int get_min(long long int m, long long int a, long long int b, long long int c, long long int d)
{
    long long int arr[] = {m, a, b, c, d};
    long long int min_val = +9223372036854775807;;
    long long int i;
    for (i = 0; i < 5; i++) {
        if (arr[i] < min_val) {
           min_val = arr[i]; 
        }
    }
    return min_val;
}

long long int get_max(long long int m, long long int a, long long int b, long long int c, long long int d)
{
    long long int arr[] = {m, a, b, c, d};
    long long int max_val = -9223372036854775807;;
    int i;
    for (i = 0; i < 5; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }
    return max_val;
}

long long int do_operation(long long int a, long long int b, int op)
{
    if (op == '*') {
        return a * b;
    } else if (op == '+') {
        return a + b;
    } else if (op == '-') {
        return a - b;
    }
}

void min_and_max(int i, int j, int op[], int n, long long int *min, long long int *max)
{
    /*note that here i and j are assumed to be 0-based index.*/
    extern long long int m[][MAXLENGTH];
    extern long long int M[][MAXLENGTH];
    *min = +9223372036854775807;
    *max = -9223372036854775807;
    long long int k;
    long long int a, b, c, d;
    for (k = i; k <= j -1; k++) {
        a = do_operation(M[i][k], M[k+1][j], op[k]);
        b = do_operation(M[i][k], m[k+1][j], op[k]);
        c = do_operation(m[i][k], M[k+1][j], op[k]);
        d = do_operation(m[i][k], m[k+1][j], op[k]);
        *min = get_min(*min, a, b, c, d);
        *max = get_max(*max, a, b, c, d);
    }
}

void digit_and_operator_array_filler(char *str, int d[], int op[])
{
    int i;
    int a = 0, b = 0;
    for (i = 0; i < strlen(str); i++) {
        if (i % 2 == 0) {
            d[a] = str[i] - '0';
            a++;
        } else {
            op[b] = str[i];
            b++;
        }
    }
}

long long int parenthesis(char *str)
{
    /*
     * Maximum Value of an Arithmetic Expression
     * Parenthesize an arithmetic expression to maximize its value.
     *
     * Input: An arithmetic expression consisting of digits as well as
     *     plus, minus, and multiplication signs.
     *
     * Output: Add parentheses to the expression in order to maximize
     *     its value.
     *
     * Input Format: The only line of input contains a string s of length
     *     2n + 1 for some n, with symbols s_0, s1, ... , s_{2n}. Each 
     *     symbol at an even position of s is a digit (that is, an integer
     *     from 0 to 9) while each symbol at an odd position is one of 
     *     three operations from {+, -, *}
     *
     * Constraints: 0 <= n <= 14 (hence the string contains at most 29 
     *     symbols)
     *
     * Sample:
     *     Input:
     *     5-8+7*4-8+9
     *
     *     Output:
     *     200
     *
     */
    extern long long int M[][MAXLENGTH];
    extern long long int m[][MAXLENGTH];

    int l = strlen(str);
    int d[(l + 1) / 2], op[(l - 1) / 2];
    digit_and_operator_array_filler(str, d, op);

    int i;
    int n = (l + 1) / 2;
    for (i = 0; i < n; i++) {
        M[i][i] = d[i];
        m[i][i] = d[i];
    }

    int s, j;
    for (s = 1; s <= n - 1; s++) {
        for (i = 1; i <= n - s; i++) {
            j = i + s;
            min_and_max(i-1, j-1, op, n - 1, &m[i-1][j-1], &M[i-1][j-1]);
        }
    }

    /*
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%16lld", M[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%16lld", m[i][j]);
        }
        printf("\n");
    }
    */

    return M[0][n - 1];
}

int main(void)
{
    /* 
     * fill the 2D arrays m and M with 0 for better visualization.
     * if you want.
    int i, j;
    for (i = 0; i < MAXLENGTH; i++) {
        for (j = 0; j < MAXLENGTH; j++) {
            m[i][j] = 0;
            M[i][j] = 0;
        }
    }
    */

    char inp[MAXLENGTH];
    scanf("%s", inp);
    long long int r = parenthesis(inp);
    printf("%lld\n", r);
    return 0;
}
