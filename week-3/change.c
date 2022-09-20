#include <stdio.h>

int change(int money){
    int num_coins = 0;
    while (money > 0) {
        if (money >= 10)
            money -= 10;
        else if (money >= 5)
            money -= 5;
        else
            money -= 1;
        num_coins += 1;
    }
    return num_coins;
}

int main(void){
    int i;
    scanf("%d", &i);
    printf("%d\n", change(i));
    return 0;
}
