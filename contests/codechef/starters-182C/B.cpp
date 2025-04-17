#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, k, D;
vector<int> times;

void incrementDay(vector<int> &garden) {
  for (int i = 1; i <= n; i++) {
    if (garden[i] < 0)
      garden[i]++;
  }
}

int pluckMostFlowers(vector<int> &garden, int k, vector<int> time) {
  int n = garden.size() - 1;
  vector<int> candidates;

  for (int i = 1; i <= n; i++) {
    if (garden[i] == 0) {
      candidates.push_back(i);
    }
  }

  int totalAvailable = candidates.size();
  int canPluck = totalAvailable - k;
  if (canPluck <= 0)
    return 0;

  sort(candidates.begin(), candidates.end(),
       [&](int a, int b) { return time[a] < time[b]; });

  for (int i = 0; i < canPluck; i++) {
    int idx = candidates[i];
    garden[idx] = -time[idx];
  }

  return canPluck;
}

void solve() {
  cin >> n >> k >> D;
  times.assign(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    cin >> times[i];
  }

  vector<int> garden(n + 1, 0);
  ll flowers = 0;
  for (int d = 1; d <= D; d++) {
    incrementDay(garden);
    int f = pluckMostFlowers(garden, k, times);
    flowers += f;
  }

  cout << flowers << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}