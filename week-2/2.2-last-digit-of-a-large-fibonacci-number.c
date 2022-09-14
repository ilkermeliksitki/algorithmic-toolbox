#include <stdio.h>

int fibo_last_digit(int n){
    /* fibo elements will be put into array after their mod is taken with respect to 10 */
    int fibo_list[n];
    fibo_list[0] = 0; fibo_list[1] = 1;

    int i;
    for (i=2; i<=n; ++i)
        fibo_list[i] = (fibo_list[i-1] + fibo_list[i-2]) % 10;
    return fibo_list[n];
}

int main(void){
    int i;
    scanf("%d", &i);
    printf("%d\n", fibo_last_digit(i));
    return 0;
}
