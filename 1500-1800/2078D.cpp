#include <bits/stdc++.h>
// manthan's code

#define tc                                                                     \
  int t;                                                                       \
  cin >> t;                                                                    \
  while (t--)
#define each(x, v) for (auto &x : v)
#define min_heap(T) priority_queue<T, vector<T>, greater<T>>
#define max_heap(T) priority_queue<T>
#define hash_map(T1, T2) unordered_map<T1, T2>
#define hash_set(T) unordered_set<T>

using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;
void fastIO() {
  ios::sync_with_stdio(0);
  cin.tie(0);
}
const int MAX_FACTORIAL = 500001;
vector<ll> fact(MAX_FACTORIAL + 1);
void compute_factorials() {
  fact[0] = 1;
  for (int i = 1; i <= MAX_FACTORIAL; i++) {
    fact[i] = (fact[i - 1] * i) % MOD;
  }
}

const int MAX_SIEVE = 1e6;
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

ll mod_expo(ll base, ll exp, ll mod) {
  ll result = 1;
  while (exp > 0) {
    if (exp % 2 == 1) {
      result = (result * base) % mod;
    }
    base = (base * base) % mod;
    exp /= 2;
  }
  return result;
}
ll mod_inv(ll a, ll mod) { return mod_expo(a, mod - 2, mod); }

ll _sqrt(ll n) {
  if (n == 0 || n == 1)
    return n;

  ll low = 1, high = n, ans = 0;
  while (low <= high) {
    ll mid = low + (high - low) / 2;
    if (mid * mid == n)
      return mid;
    else if (mid * mid < n) {
      ans = mid;
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return ans;
}

ll nCrMod(int n, int r) {
  if (r > n)
    return 0;
  return (fact[n] * mod_inv(fact[r], MOD) % MOD) * mod_inv(fact[n - r], MOD) %
         MOD;
}

ll nCr(int n, int r) {
  if (r > n)
    return 0;
  return fact[n] / (fact[r] * fact[n - r]);
}

const int type1 = 0, type2 = 1, type3 = 2, type4 = 3;

typedef pair<int, pair<int, int>> Q;
int n;
hash_map(int, ll) memo;

ll f(int i, ll l, ll r, const vector<Q> queries) {
  if (i == n) {
    return l + r;
  }

  if (memo.find(i) != memo.end()) {
    return memo[i];
  }

  const Q &query = queries[i];

  ll maxR = 0;
  if (query.first == type1) {
    maxR = max<ll>(
        f(i + 1, l, r + query.second.first + query.second.second, queries),
        f(i + 1, l + query.second.first + query.second.second, r, queries));
  } else if (query.first == type2) {
    maxR = f(i + 1, l + query.second.first, r * query.second.second, queries);
  } else if (query.first == type3) {
    maxR = f(i + 1, l * query.second.first, r * query.second.second, queries);
  } else {
    maxR = f(i + 1, l * query.second.first, r + query.second.second, queries);
  }

  return memo[i] = max(memo[i], maxR);
}

void solve() {
  cin >> n;

  vector<Q> queries;

  for (int i = 0; i < n; i++) {
    string a, b, c, d;
    cin >> a >> b >> c >> d;

    int e1 = stoi(b), e2 = stoi(d);

    if (a == "x" && c == "x") {
      queries.push_back({type3, {e1, e2}});
    } else if (a == "+" && c == "+") {
      if (queries[queries.size() - 1].first == type1) {
        queries[queries.size() - 1].second.first += e1;
        queries[queries.size() - 1].second.second += e2;
      } else
        queries.push_back({type1, {e1, e2}});
    } else {
      if (a == "x")
        queries.push_back({type4, {e1, e2}});
      else
        queries.push_back({type2, {e1, e2}});
    }
  }

  cout << f(0, 0, 0, queries) << endl;
}

int main() {
  fastIO();

  tc solve();

  return 0;
}
