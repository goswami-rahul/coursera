#include <iostream>

int get_change(int m) {
    if (m % 4 == 2) {
        if (m == 2) return 2;
        return 2 + (m - 6) / 4;
    }
    return m / 4 + (m % 4 > 0);
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
