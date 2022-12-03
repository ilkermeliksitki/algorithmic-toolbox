#include <stdio.h>

int max(int a, int b)
{
    if (a > b){
        return a;
    }
    return b;
}

int sum_array(int arr[], int size)
{
    /* sum the array up to nth index */
    int total = 0;
    for (int i = 0; i < size; i++) {
        total += arr[i];
    }
    return total;
}

int partition3(int items[], int n)
{
    int sum = sum_array(items, n);
    if (sum % 3 != 0)
        return 0;

    int W = sum / 3;
    int value[n + 1][W + 1], i, w;
    int count = 0;
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0){
                value[i][w] = 0;
                continue;
            }
            value[i][w] = value[i - 1][w];
            if (items[i - 1] <= w) {
                value[i][w] = max(value[i - 1][w - items[i - 1]] + items[i - 1], value[i][w]);
            }
            if (value[i][w] == W)
                count++;
        }
    }

    /*
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            printf("%4d", value[i][w]);
        }
        printf("%c",'\n');
    }*/

    if (count >= 3) {
        /*
        printf("%d\n", n);
        for (i = 0; i < n; i++)
            printf("%d ", items[i]);
        printf("%c", '\n');
        */
        return 1;
    }
    return 0;
}

int main(void)
{
    int n;
    scanf("%d", &n);

    int V[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &V[i]);
    }
    /*
    int a;
    scanf("%d", &a);

    int A[a];
    for (int i = 0; i < a; i++) {
        scanf("%d", &A[i]);
    }*/

    int r = partition3(V, n);
    //int r2 = partition3(A, a);
    //printf("should be 1 0 = %d %d\n", r, r2);
    printf("%d\n", r);
    return 0;
}
