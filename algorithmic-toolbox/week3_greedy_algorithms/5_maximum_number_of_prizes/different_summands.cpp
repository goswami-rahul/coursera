#include <bits/stdc++.h>
using namespace std;

vector<int> optimal_summands(int n) {
    vector<int> summands;
    int sum = 0;
    for (int i = 1; ; ++i) {
        if (sum + i > n) break;
        sum += i;
        summands.push_back(i);
    }
    while (true) {
        int p = summands.empty() ? 0 : summands.back();
        if (n - sum > p) {
            summands.push_back(n - sum);
            break;
        } else {
            sum -= p;
            summands.pop_back();
        }
    }
    return summands;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}
