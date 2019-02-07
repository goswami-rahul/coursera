#include <bits/stdc++.h>
using namespace std;

int dp[10005][301];
int optimal_weight(int W, const vector<int> &w) {
    int n = w.size();
    for (int u = 1; u <= W; ++u) {
        for (int i = 1; i <= n; ++i) {
            dp[u][i] = dp[u][i - 1];
            if (u >= w[i - 1])
                dp[u][i] = max(dp[u][i], w[i - 1] + dp[u - w[i - 1]][i - 1]);
        }
    }
    return dp[W][n];
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';
}
