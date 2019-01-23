#include <bits/stdc++.h>
using namespace std;

struct Segment {
  int start, end;
  bool operator < (const Segment& other) {
      return end < other.end;
  }
};

vector<int> optimal_points(vector<Segment> &segments) {
    sort(segments.begin(), segments.end());
    vector<int> points;
    //write your code here
    points = {segments[0].end};
    for (size_t i = 1; i < segments.size(); ++i) {
        int p = points.back();
        if (p < segments[i].start)
            points.push_back(segments[i].end);
    }
    return points;
}

int main() {
    int n;
    std::cin >> n;
    vector<Segment> segments(n);
    for (size_t i = 0; i < segments.size(); ++i) {
        std::cin >> segments[i].start >> segments[i].end;
    }
    vector<int> points = optimal_points(segments);
    std::cout << points.size() << "\n";
    for (size_t i = 0; i < points.size(); ++i) {
        std::cout << points[i] << " ";
    }
}
