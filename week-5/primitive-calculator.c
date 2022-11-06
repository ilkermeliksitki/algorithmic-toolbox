#include <stdio.h>
#include <stdarg.h>

int min(int n, ...)
{
    /* variadic minimum function */
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

void print2d_array(int *arr, int row, int col)
{
    int i, j;
    for (i = 0; i < row; i++){
        for (j = 0; j < col; j++){
            printf("%3d", *(arr + i * col + j));
        }
        printf("%c", '\n');
    }
}

int primitive_calculator(int n)
{
    if (n == 1)
        return 0;

    int A[3][n + 1], i, j;
    for (i = 0; i < 3; i++) {
        A[i][0] = 0;
    }

    for (j = 1; j < n + 1; j++) {
        /* +1 column */
        A[0][j] = j;
    }

    for (i = 1; i < 3; i++) {
        for (j = 1; j < n + 1; j++) {
            if (i == 1) {
                /* x2 column */
                if (j % 2 == 0) {
                    if (j == 2)
                        A[i][j] = 1;
                    else
                        A[i][j] = 1 + A[i][j / 2];
                } else {
                    A[i][j] = 1 + A[i][j - 1];
                }
            } else {
                /* x3 column */
                if (j == 1 || j == 2 || j == 3){
                    A[i][j] = 1;
                    continue;
                } else {
                    if (j % 3 == 0 && j % 2 == 0){
                        A[i][j] = 1 + min(3, A[i][j / 3], A[i][j / 2], A[i][j - 1]);
                    } else if (j % 3 == 0) {
                        A[i][j] = 1 + min(2, A[i][j / 3], A[i][j - 1]);
                    } else if (j % 2 == 0) {
                        A[i][j] = 1 + min(2, A[i][j / 2], A[i][j - 1]);
                    } else {
                        A[i][j] = 1 + A[i][j - 1];
                    }
                }
            }
        }
    }

    print2d_array((int *)A, 3, n + 1);
    return A[2][n];
}

int main(void)
{
    int n;
    scanf("%d", &n);
    int r = primitive_calculator(n);
    printf("%d\n", r);
    return 0;
}
