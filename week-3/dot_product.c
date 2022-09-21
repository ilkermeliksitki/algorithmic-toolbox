#include <stdio.h>
#include <stdlib.h>

int compare_unsigned(const void * p, const void * q){
    unsigned int x = *(const unsigned int *)p;
    unsigned int y = *(const unsigned int *)q;
    return (x > y) - (x < y);
}

void sort_arrays(unsigned int * a, unsigned int * b, int size){
    qsort(a, size, sizeof(*a), compare_unsigned);
    qsort(b, size, sizeof(*b), compare_unsigned);
}

unsigned long int dot_product(unsigned int price[], unsigned int clicks[], int size){
    sort_arrays(price, clicks, size);
    unsigned long int result = 0;
    for (int i = 0; i < size; ++i) {
        result += (unsigned long int)price[i] * clicks[i];
    }
    return result;
}

int main(void){
    int n;
    scanf("%d", &n);
    
    int i;
    unsigned int price[n], clicks[n];
    for (i = 0; i < n; ++i)
        scanf("%u",&price[i]);
    for (i = 0; i < n; ++i)
        scanf("%u", &clicks[i]);

    unsigned long int result =  dot_product(price, clicks, n);
    printf("%lu\n", result);

    return 0;
}
