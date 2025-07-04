#include <bits/stdc++.h>
#include <cstring>
// manthan's code
using namespace std;
#define tc                                                                     \
  int t;                                                                       \
  cin >> t;                                                                    \
  while (t--)
#define FIO                                                                    \
  ios::sync_with_stdio(0);                                                     \
  cin.tie(0);
#define each(x, v) for (auto &x : v)
#define min_heap(T) priority_queue<T, vector<T>, greater<T>>
#define max_heap(T) priority_queue<T>
#define hash_map(T1, T2) unordered_map<T1, T2>
#define hash_set(T) unordered_set<T>
#define loop(i, a, b, step) for (int i = (a); i < (b); i += step)
#define asc(v) sort((v).begin(), (v).end())
#define dsc(v) sort((v).rbegin(), (v).rend())
#define MOD 1000000007
#define ll long long
#define ii pair<int, int>
#define vii vector<ii>
#define vll vector<ll>
#define vi vector<int>

void solve() {
  int n;
  cin >> n;

  int C;
  cin >> C;
  min_heap(ii) heap;

  vi w(n), t(n);

  each(it, w) cin >> it;
  each(it, t) cin >> it;

  int capacity = C;

  int day = 1;
  for (int i = 0; i < n; i++) {
    capacity -= w[i];
    heap.push({day + t[i], i});
  }

  while (capacity > 0) {
    ii sp = heap.top();
    heap.pop();
    day = max(day, sp.first);
    capacity -= w[sp.second];
    heap.push({day + t[sp.second], sp.second});

    while (heap.top().first <= day) {
      ii sprinkl = heap.top();
      heap.pop();
      capacity -= w[sprinkl.second];
      heap.push({day + t[sprinkl.second], sprinkl.second});
    }
  }

  cout << day << endl;
}

int main() {
  // usaco();
  FIO solve();

  return 0;
}
