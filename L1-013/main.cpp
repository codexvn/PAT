#include <iostream>

int main() {
    unsigned int n, sum[10] = {1, 3, 9, 33, 153, 873, 5913, 46233, 409113, 4037913};
    std::cin >> n;
    std::cout << sum[n - 1];
    return 0;
}