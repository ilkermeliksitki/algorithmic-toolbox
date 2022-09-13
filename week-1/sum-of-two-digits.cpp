#include <iostream>

int sum(int a, int b){
    return a + b;
}

int main(){
    int a, b;
    std::cin >> a;
    std::cin >> b;

    std::cout << sum(a, b) << "\n";

    return 0;
}
