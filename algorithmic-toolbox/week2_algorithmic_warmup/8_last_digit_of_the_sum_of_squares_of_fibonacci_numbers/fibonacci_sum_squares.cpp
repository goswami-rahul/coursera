#include <bits/stdc++.h>
using namespace std;

int fibonacci_sum_squares(long long n) {
    if (n <= 1)
        return n;

    int fib[2];
    fib[0] = 0; fib[1] = 1;
    int period;
    for (int i = 2, p = 0; ; ++i, p ^= 1) {
        fib[p] += fib[!p];
        fib[p] %= 10;
        if (fib[p] == 1 && fib[!p] == 0) {
            period = i - 1;
            break;
        }
    }
    fib[0] = 0; fib[1] = 1;
    int ans = 1;
    for (int i = 2, p = 0; i < period; ++i, p ^= 1) {
        fib[p] += fib[!p];
        fib[p] %= 10;
        ans += fib[p] * fib[p];
        ans %= 10;
    }
    ans = n / period * ans % 10;
    fib[0] = 0; fib[1] = 1;
    for (int i = 1, p = 1; i <= n % period; ++i, p ^= 1) {
        fib[p] += fib[!p];
        fib[p] %= 10;
        ans += fib[p] * fib[p];
        ans %= 10;
    }

    return ans;
}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_squares(n);
}
