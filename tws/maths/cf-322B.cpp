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
  int r, g, bl;
  cin >> r >> g >> bl;

  int maxB = 0;

  for (int i = 0; i <= 2; i++) {
    for (int j = 0; j <= 2; j++) {
      for (int k = 0; k <= 2; k++) {
        int a = r - i, b = g - j, c = bl - k;

        int rema = a % 3, remb = b % 3, remc = c % 3;

        int ways = a / 3 + b / 3 + c / 3;

        ways += min({rema, remb, remc});

        maxB = max(maxB, ways);
      }
    }
  }

  cout << maxB << endl;
}

int main() {
  // usaco();
  FIO solve();

  return 0;
}
