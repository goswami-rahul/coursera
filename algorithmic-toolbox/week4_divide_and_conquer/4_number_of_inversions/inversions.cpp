#include <iostream>
#include <vector>

using std::vector;

long long get_number_of_inversions(vector<int> &a, vector<int> &b, size_t left, size_t right) {
    long long number_of_inversions = 0;
    if (right == left + 1) {
        b[left] = a[left];
        return number_of_inversions;
    }
    size_t ave = left + (right - left) / 2;
    number_of_inversions += get_number_of_inversions(a, b, left, ave);
    number_of_inversions += get_number_of_inversions(a, b, ave, right);
    vector<int> temp(right - left);
    for (size_t i = left, j = ave, p = 0;;) {
        while (i < ave && b[i] < b[j]) {
            temp[p++] = b[i++];
        }
        number_of_inversions += ave - i;
        temp[p++] = b[j++];
        if (j == right) {
            while (i < ave) {
                temp[p++] = b[i++];
            }
            break;
        }
    }
    for (size_t i = left; i < right; ++i) b[i] = temp[i - left];
    //write your code here
    return number_of_inversions;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  vector<int> b(a.size());
  std::cout << get_number_of_inversions(a, b, 0, a.size()) << '\n';
}
