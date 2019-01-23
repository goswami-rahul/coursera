#include <iostream>
#include <vector>
#include <algorithm>


long long MaxPairwiseProduct(std::vector<int>& numbers) {
    sort(numbers.begin(), numbers.end(), std::greater<int>());
    return (long long) numbers[0] * numbers[1];
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    long long result = MaxPairwiseProduct(numbers);
    std::cout << result << "\n";
    return 0;
}
