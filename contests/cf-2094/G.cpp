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

class QueryDS {
  int n = 0;
  bool active = true;
  list<int> arr;
  ll rizz = 0, revrizz = 0, sumN_2 = 0;

public:
  QueryDS() {
    arr = {};
    rizz = 0, revrizz = 0, sumN_2 = 0;
    n = 0, active = true;
  }

  void append(int val) {
    if (n == 0) {
      arr.push_back(val);
      n = 1;
      rizz = val;
      revrizz = val;
      return;
    }
    if (active) {
      int le = *arr.rbegin();
      if (n > 1) {
        sumN_2 += le;
      }
      n++;

      rizz = rizz + n * val;
      int tempSum = *arr.begin() + sumN_2 + val;
      revrizz = revrizz + tempSum;

      arr.push_back(val);

    } else {
      int tempSum = sumN_2 + *arr.rbegin() + *arr.begin();
      n++;

      sumN_2 += *arr.begin();
      revrizz += n * val;
      rizz += tempSum + val;

      arr.push_front(val);
    }
  }

  void cycle() {
    if (n <= 1)
      return;

    int lastEL = *arr.rbegin();
    int moreSum = *arr.begin() + sumN_2;

    rizz = (rizz - (n - 1) * lastEL) + moreSum;
    revrizz = (revrizz - moreSum) + (n - 1) * lastEL;

    arr.pop_back();
    sumN_2 -= *arr.rbegin();
    sumN_2 += *arr.begin();
    arr.push_front(lastEL);
  }

  void reverse() {
    if (n <= 1)
      return;
    active = !active;
    swap(rizz, revrizz);
  }

  ll rizziness() { return active ? rizz : revrizz; }
};

void solve() {
  QueryDS qds;

  int q;
  cin >> q;
  while (q--) {
    int type;
    cin >> type;
    if (type == 3) {
      int k;
      cin >> k;
      qds.append(k);
      cout << qds.rizziness() << '\n';
    } else if (type == 2) {
      qds.reverse();
      cout << qds.rizziness() << '\n';
    } else {
      qds.cycle();
      cout << qds.rizziness() << '\n';
    }
  }
}

int main() {
  fastIO();
  tc solve();
  return 0;
}
