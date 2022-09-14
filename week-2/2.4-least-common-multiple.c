#include <stdio.h>

unsigned long gcd(unsigned long a, unsigned long b){
    if (b == 0)
        return a;
    unsigned long a_prime;
    a_prime = a % b;
    return gcd(b, a_prime);
}
unsigned long lcm(unsigned long a, unsigned long b){
    return (a * b) / gcd(a, b);
}

int main(void){
    unsigned long a, b;
    scanf("%lu %lu", &a, &b);

    printf("%lu\n", lcm(a, b));
    return 0;
}
