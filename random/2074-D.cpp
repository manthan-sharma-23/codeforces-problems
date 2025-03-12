#include <algorithm>
#include <cmath>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;

void fastIO() {
  ios::sync_with_stdio(0);
  cin.tie(0);
}

int maxY(int x, int r, int c) {
  int y = floor<ll>((ll)(r * r) - (ll)pow((x - c), 2));

  return 2 * y + 1;
}

void solve() {
  int n, m;

  cin >> n >> m;

  vector<pair<int, int>> circles(n);

  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;

    circles[i].first = t;
  }
  for (int i = 0; i < n; i++) {
    int r;
    cin >> r;
    circles[i].second = r;
  }

  int largestX = 0;
  for (auto it : circles) {
    largestX = max(largestX, it.first + it.second);
  }

  sort(circles.begin(), circles.end(),
       [](pair<int, int> &a, pair<int, int> &b) {
         return a.first - a.second < b.first - b.second;
       });

  int start = 0;
  int ans = 0;

  for (int point = (circles[0].first - circles[0].second); point <= largestX;
       point++) {
    int ymax = 0;
    for (int j = 0; j < circles.size(); j++) {
      auto circle = circles[j];
      int centre = circle.first;
      int radius = circle.second;
      int s = centre - radius, e = centre + radius;

      if (s > point) {
        break;
      }
      if (e < point) {
        start = j;
      }
      if (point >= s && point <= e)
        ymax = max(ymax, maxY(point, radius, centre));
    }

    ans += ymax;
  }

  cout << ans << endl;
}

int main() {

  int t;
  cin >> t;

  while (t--)
    solve();

  return 0;
}