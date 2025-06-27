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

const int MAX_SIEVE = 200;
vector<bool> isPrime(MAX_SIEVE + 1, 1);
void sieve() {
  isPrime[0] = isPrime[1] = 0;
  for (int i = 2; i * i <= MAX_SIEVE; i++) {
    if (isPrime[i]) {
      for (int j = i * i; j <= MAX_SIEVE; j += i) {
        isPrime[j] = 0;
      }
    }
  }
}

ll dp[20][2][200];

ll f(int idx, bool tight, int sum, const string &s) {
  if (idx == s.length())
    return isPrime[sum];

  if (dp[idx][tight][sum] != -1)
    return dp[idx][tight][sum];

  int limit = tight ? s[idx] - '0' : 9;

  ll ans = 0;

  for (int d = 0; d <= limit; d++) {
    ans += f(idx + 1, (tight & (d == limit)), sum + d, s);
  }

  return dp[idx][tight][sum] = ans;
}

void solve() {
  ll l, r;
  cin >> l >> r;
  string li = to_string(l - 1), ri = to_string(r);

  memset(dp, -1LL, sizeof(dp));
  ll ra = f(0, 1, 0, ri);
  memset(dp, -1LL, sizeof(dp));
  ll la = f(0, 1, 0, li);

  cout << ra - la << endl;
}

int main() {
  sieve();
  // usaco();
  FIO tc solve();

  return 0;
}
