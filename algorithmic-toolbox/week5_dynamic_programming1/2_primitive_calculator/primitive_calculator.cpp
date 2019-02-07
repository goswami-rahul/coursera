#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

vector<int> optimal_sequence(int n) {
    std::vector<int> sequence;
    vector<int> dp(3 * n + 1, 1e9), link(3 * n + 1, -1);
    dp[1] = 0;
    for (int i = 1; i < n; ++i) {
        if (dp[i + 1] > 1 + dp[i]) {
            dp[i + 1] = 1 + dp[i];
            link[i + 1] = i;
        }
        if (dp[i * 2] > 1 + dp[i]) {
            dp[i * 2] = 1 + dp[i];
            link[i * 2] = i;
        }
        if (dp[i * 3] > 1 + dp[i]) {
            dp[i * 3] = 1 + dp[i];
            link[i * 3] = i;
        }
    }
    sequence.push_back(n);
    while (n != 1) {
        n = link[n];
        sequence.push_back(n);
    }
    reverse(sequence.begin(), sequence.end());
    return sequence;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> sequence = optimal_sequence(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
}
