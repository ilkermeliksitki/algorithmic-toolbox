#include <stdio.h>
/* The pisano cycle logic will be used again with a small difference.
 * Let us say S(n) represents the sum of fibonacci numbers up to F(n)
 * S(n) can be equated to the following with a  math trick
 * S(n) = F(n+2) - 1
 * Finding F(n+2) is sufficient to calculate the sum of fibonacci 
 * numbers.
 * Do not forget substract 1.
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
    unsigned long long n;
    int m = 10;
    int arr[10000];
    arr[0] = 0; arr[1] = 1;

    scanf("%lld", &n);
    pisano_cycle(m, &period, arr);

    int last_digit = arr[(n + 2) % period] - 1;
    if (last_digit == -1)
        last_digit = 9;
    printf("%d\n", last_digit);

    return 0;
}
