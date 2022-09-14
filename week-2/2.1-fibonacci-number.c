#include <stdio.h>

unsigned long long fibo(int n){
    unsigned long long fibo_list[n];
    fibo_list[0] = 0; fibo_list[1] = 1;

    int i;
    for (i=2; i<=n; ++i)
        fibo_list[i] = fibo_list[i-1] + fibo_list[i-2];
    return fibo_list[n];
}


int main(void){
    int i;
    scanf("%d", &i);
    printf("%llu\n", fibo(i));
    return 0;
}
