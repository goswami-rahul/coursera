#include <bits/stdc++.h>
using namespace std;

string largest_number(vector<string> a) {
  //write your code here
    sort(a.begin(), a.end(), [] (string x, string y) {
        return x + y > y + x;
    });
    string result;
    for (string t: a) result += t;
    return result;
}

int main() {
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::cout << largest_number(a);
}
