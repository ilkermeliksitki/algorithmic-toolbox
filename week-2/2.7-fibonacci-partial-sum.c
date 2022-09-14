#include <stdio.h>

/*
 * The pisano cycle logic will be used again for partial sum of fibonaci
 * numbers by using the summation formula S(n) = F(n+2) - 1
 * The desired calculation Fm + Fm+1 + ... + Fn
 * F1 + F2 + ... + Fm-1 + Fm + ... + Fn = S(n) = F(n+2) - 1
 * F1 + F2 + ... + Fm-1 = S(m-1) = F(m+1) - 1
 * => Fm + ... + Fn = S(n) - S(m-1) = F(n+2) - F(m+1)
 */

void pisano_cycle(int m, int *period, int arr[]){
    int prev = 0; int curr = 1; int next = 1; int count = 0;
    do {
        prev = curr;
        curr = next;
        next = (prev + curr) % m;
        arr[count + 2] = curr;
        count++;
    } while (!(prev == 0 && curr == 1));
    *period = count;
}

int main(void){
    int period;
    int arr[100000];
    arr[0] = 0; arr[1] = 1;
    unsigned long long m, n;
    scanf("%llu %llu", &m, &n);
    pisano_cycle(10, &period, arr);

    /* last digits of F(n+2) and F(m+1) is found */
    int last_digit_n, last_digit_m;
    last_digit_n = arr[(n + 2) % period];
    last_digit_m = arr[(m + 1) % period];

    /* if the result is negative ve add the mod value to result */
    int result = last_digit_n - last_digit_m;
    if (result < 0)
        result += 10;
    printf("%d\n", result);
    return 0;
}

