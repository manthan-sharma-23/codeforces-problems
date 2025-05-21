#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<tuple<int, int>> students(n);
  for (int i = 0; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    students[i] = {a, b};
  }

  // Sort by (a - b) descending
  sort(students.begin(), students.end(), [](const auto &x, const auto &y) {
    return (get<0>(x) - get<1>(x)) > (get<0>(y) - get<1>(y));
  });

  ll total_dissatisfaction = 0;
  for (int pos = 0; pos < n; ++pos) {
    int a = get<0>(students[pos]);
    int b = get<1>(students[pos]);
    total_dissatisfaction += 1LL * a * pos + 1LL * b * (n - pos - 1);
  }

  cout << total_dissatisfaction << '\n';
  return 0;
}
