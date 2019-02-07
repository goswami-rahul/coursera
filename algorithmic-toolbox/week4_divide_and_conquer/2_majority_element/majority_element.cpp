#include <bits/stdc++.h>
using namespace std;

int get_majority_element(vector<int> &a, int left, int right) {
    if (left == right) return -1;
    if (left + 1 == right) return a[left];
    int mid = (left + right) / 2, x, n = right - left;
    x = get_majority_element(a, left, mid);
    if (x != -1) {
        int cnt = 0;
        for (int i = left; i < right; ++i)
            if (a[i] == x) cnt++;
        if (cnt > n / 2) return x;
    }
    x = get_majority_element(a, mid, right);
    if (x != -1) {
        int cnt = 0;
        for (int i = left; i < right; ++i)
            if (a[i] == x) cnt++;
        if (cnt > n / 2) return x;
    }
    //write your code here
    return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}
