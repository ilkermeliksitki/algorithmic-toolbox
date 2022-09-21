#include <stdio.h>
#include <math.h>

unsigned long int gauss_formula_variable(unsigned long int n){
    /*
     * finds the nearest variable k for n
     * k(k+1) / 2 <= n  ->  k = floor((sqrt(8*n + 1)-1)/2
     */
    return floor((sqrt(8*n+1)-1)/2);
}

void summand_coefficients(unsigned long n, unsigned long int * k, unsigned long int * m){
    /*
     * we want all numbers to be unique, so if last one is in the previous set, 
     * the previous one and the last one is merged.
     * n = 1, 2, 3, ... , k, m. (general assumption.)
     *
     * let us consider n = 125 case,
     * gauss_formula_variable(125) -> k = 15.
     * 125 = 1, 2, 3, 4, 5, 6,..., 14, 15, 5 (not accepted.) 
     *     = 1, 2, 3, 4, 5, 6,..., 14, 20    (accepted.)
     */
    *k = gauss_formula_variable(n);
    if ((n - *k*(*k+1)/2) <= *k ){
        *k -= 1;
        *m = n - *k*(*k+1)/2;
    }
}

int main(void){
    unsigned long int n;
    scanf("%lu", &n);

    unsigned long int k, m;
    summand_coefficients(n, &k, &m);

    /* the following code is for formatting*/
    if (k == 0){
        printf("1\n%lu\n", m);
    } else {
        printf("%lu\n", k+1);
        for (unsigned long int i = 1; i < k+1; ++i) {
            printf("%lu ", i);
        }
        printf("%lu\n", m);
    }
    return 0;
}
