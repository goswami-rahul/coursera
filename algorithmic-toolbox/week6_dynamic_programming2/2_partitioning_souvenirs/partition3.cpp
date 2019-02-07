#include <bits/stdc++.h>
using namespace std;

using std::vector;

int partition3(vector<int> &A) {
    int n = A.size();
    int sum = accumulate(A.begin(), A.end(), 0);
    if (sum % 3) return 0;
    sum /= 3;
    vector<int> nums;
    for (int i = 0; i < (1 << n); ++i) {
        int cur = 0;
        for (int j = 0; j < n; ++j) {
            if (i >> j & 1) cur += A[j];
        }
        if (cur == sum) nums.push_back(i);
    }
    int x = nums.size();
    for (int i = 0; i < x; ++i) {
        for (int j = i + 1; j < x; ++j) {
            if (nums[i] & nums[j]) continue;
            for (int k = j + 1; k < x; ++k) {
                if (nums[i] & nums[k]) continue;
                if (nums[j] & nums[k]) continue;
                return 1;
            }
        }
    }
    return 0;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> A(n);
  for (size_t i = 0; i < A.size(); ++i) {
    std::cin >> A[i];
  }
  std::cout << partition3(A) << '\n';
}
