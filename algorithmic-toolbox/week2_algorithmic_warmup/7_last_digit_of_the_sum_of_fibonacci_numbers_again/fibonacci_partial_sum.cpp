#include <bits/stdc++.h>
using namespace std;

int fibonacci_sum(long long n) {
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
        ans += fib[p];
        ans %= 10;
    }
    ans = n / period * ans % 10;
    fib[0] = 0; fib[1] = 1;
    for (int i = 1, p = 1; i <= n % period; ++i, p ^= 1) {
        fib[p] += fib[!p];
        fib[p] %= 10;
        ans += fib[p];
        ans %= 10;
    }

    return ans;
}

long long get_fibonacci_partial_sum(long long from, long long to) {
    return (fibonacci_sum(to) - fibonacci_sum(max(0LL, from - 1)) + 10) % 10;
}

int main() {
    long long from, to;
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum(from, to) << '\n';
}
