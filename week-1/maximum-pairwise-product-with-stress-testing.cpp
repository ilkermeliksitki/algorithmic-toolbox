#include <iostream>
#include <vector>


long long max_pairwise_product(const std::vector<int> &numbers ) {
    long long result = 0;
    long long current = 0;
    int n = numbers.size();
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            current = ((long long)(numbers[i])) * numbers[j];
            if (current > result) {
                result = current;
            }        
        }
    }
    return result;
}


long long max_pairwise_product_fast(const std::vector<int> &numbers){
    int n = numbers.size();

    int max_index1 = -1;
    for (int i = 0; i < n; ++i) {
        if ( (max_index1 == -1) || (numbers[i] > numbers[max_index1]) ){
            max_index1 = i;
        }
    }
    int max_index2 = -1;
    for (int j = 0; j < n; ++j) {
        if ((j != max_index1) && ((max_index2 == -1) || (numbers[j] > numbers[max_index2]))) {
            max_index2 = j;
        }
    }

    return ((long long)(numbers[max_index1]) * numbers[max_index2]);
}



int main(void){
// The following while code block is for stress testing
/*    while (true) {
        int n = rand() % 100 + 2;
        std::cout << "Vector length: " << n << std::endl;
        std::vector<int> a;
        for (int i = 0; i < n; ++i) {
            a.push_back(rand() % 100000);
        }
        for (int i = 0; i < n; ++i) {
            std::cout << a[i] << " ";
        }
        std::cout << std::endl;
        long long res1 = max_pairwise_product(a);
        long long res2 = max_pairwise_product_fast(a);
        if (res1 != res2) {
            std::cout << "The results differ." << "slow-one: " << res1 << " fast-one: " << res2 << std::endl;
            break;
        } else {
            std::cout << "The results are same.\n" << std::endl;
        }
    }
*/

    int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    long long result = max_pairwise_product_fast(numbers);
    std::cout << result  << std::endl;
}

