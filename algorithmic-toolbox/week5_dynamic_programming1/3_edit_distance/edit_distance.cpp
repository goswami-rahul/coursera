#include <bits/stdc++.h>
using namespace std;

int edit_distance(const string &a, const string &b) {
  //write your code here
  int n = (int) a.size(), m = (int) b.size();
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, 1e9));
  dp[0][0] = 0;
  for (int i = 1; i <= n; ++i) dp[i][0] = i;
  for (int i = 1; i <= m; ++i) dp[0][i] = i;
  for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
          if (a[i - 1] == b[j - 1]) {
              dp[i][j] = dp[i - 1][j - 1];
          } else {
              dp[i][j] = min({1 + dp[i - 1][j], 1 + dp[i][j - 1],
                  1 + dp[i - 1][j - 1]});
          }
      }
  }
  return dp[n][m];
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
