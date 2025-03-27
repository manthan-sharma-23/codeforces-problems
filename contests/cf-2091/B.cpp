#include <climits>
#include <iostream>
#include <queue>

using namespace std;

typedef long long ll;

void fastIO() {
  ios::sync_with_stdio(0);
  cin.tie(0);
}

void solve() {

  int n, x;

  cin >> n >> x;

  priority_queue<int> pq;

  int count = 0;

  for (int i = 0; i < n; i++) {
    int m;
    cin >> m;
    if (m >= x) {
      count++;
    } else {
      pq.push(m);
    }
  }

  int currMin = INT_MAX, currSize = 0;

  while (!pq.empty()) {
    int m = pq.top();
    pq.pop();

    currMin = min(currMin, m);
    currSize++;

    if (currSize * currMin >= x) {
      count++;
      currMin = INT_MAX;
      currSize = 0;
    }
  }

  cout << count << endl;
  return;
}

int main() {
  fastIO();
  int t;
  cin >> t;

  while (t--)
    solve();

  return 0;
}