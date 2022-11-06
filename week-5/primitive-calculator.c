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

void print_array(int array[], size_t len)
{
    for (size_t i = 0; i < len; ++i){
        printf("%2d", array[i]);
    }
    printf("\n");
}

int primitive_calculator(int n)
{
    if (n == 1)
        return 0;

    int A[n + 1], i, j;
    A[0] = 0;
    for (j = 1; j < n + 1; j++) {
        if (j == 1 || j == 2 || j == 3){
            A[j] = 1;
            continue;
        } else {
            if (j % 3 == 0 && j % 2 == 0){
                A[j] = 1 + min(3, A[j / 3], A[j / 2], A[j - 1]);
            } else if (j % 3 == 0) {
                A[j] = 1 + min(2, A[j / 3], A[j - 1]);
            } else if (j % 2 == 0) {
                A[j] = 1 + min(2, A[j / 2], A[j - 1]);
            } else {
                A[j] = 1 + A[j - 1];
            }
        }
    }

    print_array(A, n + 1); 
    return A[n];
}

int main(void)
{
    int n;
    scanf("%d", &n);
    int r = primitive_calculator(n);
    printf("%d\n", r);
    return 0;
}
