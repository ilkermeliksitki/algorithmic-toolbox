#include <stdio.h>

/* Fibonacci sum of squares can be solved with the help of geometry.
 * The sum of squares creates a rectangular whose short part is F(n) 
 * and long part is (F(n) + F(n-1). The area of the rectangular is 
 * equal to sum of squares. Again, pisano_cycle method will be used
 * because the mod of the sum of square should be the output.*/

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
    /* arr will be stored the pisano cycle values for m, which is the
     * mod vaue, and period will be the size of this array, i.e.
     * the period of pisano cycle for m. */
    int arr[10000]; arr[0] = 0; arr[1] = 1; int period;
    int m = 10;
    
    unsigned long long n;
    scanf("%llu", &n);
    pisano_cycle(m, &period, arr);
    
    int area;
    area = (arr[n % period]) * (arr[n % period] + arr[(n-1) % period]);
    area = area % m;
    printf("%d\n", area);

    return 0;
}
