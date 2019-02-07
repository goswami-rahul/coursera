#include <bits/stdc++.h>
using namespace std;

long long eval(long long a, long long b, char op) {
  if (op == '*') {
    return a * b;
  } else if (op == '+') {
    return a + b;
  } else if (op == '-') {
    return a - b;
  } else {
    assert(0);
  }
}
long long maxd[50][50], mind[50][50];
long long mini(const string&, int, int);
long long maxi(const string &s, int x, int y) {
    assert(x <= y);
    long long &r = maxd[x][y];
    if (r != 1e18) return r;
    r = -1e18;
    for (int i = x + 1; i < y; i += 2) {
        if (s[i] == '+') {
            r = max(r, maxi(s, x, i - 1) + maxi(s, i + 1, y));
        } else if (s[i] == '-') {
            r = max(r, maxi(s, x, i - 1) - mini(s, i + 1, y));
        } else if (s[i] == '*') {
            r = max(r, maxi(s, x, i - 1) * maxi(s, i + 1, y));
            r = max(r, mini(s, x, i - 1) * mini(s, i + 1, y));
        } else {
            assert(false);
        }
    }
    if (x == y) r = s[x] - '0';
    return r;
}
long long mini(const string &s, int x, int y) {
    assert(x <= y);
    long long &r = mind[x][y];
    if (r != 1e18) return r;
    for (int i = x + 1; i < y; i += 2) {
        if (s[i] == '+') {
            r = min(r, mini(s, x, i - 1) + mini(s, i + 1, y));
        } else if (s[i] == '-') {
            r = min(r, mini(s, x, i - 1) - maxi(s, i + 1, y));
        } else if (s[i] == '*') {
            r = min(r, mini(s, x, i - 1) * maxi(s, i + 1, y));
            r = min(r, maxi(s, x, i - 1) * mini(s, i + 1, y));
        } else {
            assert(false);
        }
    }
    if (x == y) r = s[x] - '0';
    return r;
}
long long get_maximum_value(const string &exp) {
    int n = exp.size();
    return maxi(exp, 0, n - 1);
}

int main() {
  for (int i = 0; i < 50; ++i) for (int j = 0; j < 50; ++j) {
      mind[i][j] = maxd[i][j] = 1e18;
  }
  string s;
  std::cin >> s;
  std::cout << get_maximum_value(s) << '\n';
}
