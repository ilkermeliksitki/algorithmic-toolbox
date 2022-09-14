#include <stdio.h>
#include <stdlib.h>

void pisano_cycle(int m, int *period, int *p){
    /* write the # of pisano cycle into period, and write the pisano cycle items in *p pointed array. */
    int prev = 0; int curr = 1; int next = 1; int count = 0;
    do { 
        prev = curr;
        curr = next;
        next = (prev + curr) % m;
        *(p + count + 2) = curr;
        count++;
//      printf("prev: %d curr: %d next: %d count: %d\n", prev, curr, next, count);
    } while (!(prev==0 && curr==1));
    *period = count;
}

int main(void){
    int period, m; unsigned long long n;
    int *p = (int*)malloc(sizeof(int) * 10000);

    *p = 0; *(p+1) = 1;
    scanf("%lld %d", &n, &m);
    pisano_cycle(m, &period, p);

    int last_digit = *(p + (n % period));
    printf("%d\n", last_digit);

    free(p);
    return 0;
}

