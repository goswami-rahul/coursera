#include <bits/stdc++.h>
using namespace std;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
    double value = 0.0;
    vector<pair<double,int>> a;
    int n = (int) values.size();
    for (int i = 0; i < n; ++i) {
        a.emplace_back((double) values[i] / weights[i], weights[i]);
    }
    std::sort(a.begin(), a.end());
    for (int i = n - 1; i >= 0; --i) {
        if (capacity > a[i].second) {
            capacity -= a[i].second;
            value += a[i].second * a[i].first;
        } else {
            value += a[i].first * capacity;
            capacity = 0;
        }
    }
    // write your code here

    return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
