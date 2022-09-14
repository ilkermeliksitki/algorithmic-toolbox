#include <stdio.h>

unsigned long gcd(unsigned long a, unsigned long b){
    if (b == 0)
        return a;
    unsigned long a_prime;
    a_prime = a % b;
    return gcd(b, a_prime);
}

int main(void){
    unsigned long a, b;
    scanf("%lu %lu", &a, &b);

    printf("%lu\n", gcd(a, b));
    return 0;
}
