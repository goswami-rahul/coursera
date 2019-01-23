#include <iostream>

int get_change(int m) {
  //write your code here
  int n = 0;
  for (int i: {10, 5, 1}) {
      while (m >= i) {
          n++;
          m -= i;
      }
  }
  return n;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
