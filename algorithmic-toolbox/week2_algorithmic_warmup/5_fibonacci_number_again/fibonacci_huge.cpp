#include <iostream>

int fibonacci_fast(int n, int m) {
    // write your code here
    int fib[2];
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i <= n; ++i) {
        fib[i % 2] += fib[(i + 1) % 2];
        fib[i % 2] %= m;
    }
    return fib[n % 2] % m;
}
int per(int n, int m) {
    int fib[2];
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; ; ++i) {
        fib[i % 2] += fib[(i + 1) % 2];
        fib[i % 2] %= m;
        if (fib[i % 2] == 1 && fib[(i + 1) % 2] == 0) return i - 1;
    }
}
long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;
    return fibonacci_fast(n % per(n, m), m);
}

int main() {
    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge_naive(n, m) << '\n';
}
