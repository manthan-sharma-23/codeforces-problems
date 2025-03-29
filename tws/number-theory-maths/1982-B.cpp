#include <iostream>
using namespace std;

typedef long long ll;

ll collatz_variant(ll x, ll y, ll k) {
    while (k > 0 && x != 1) {
        ll step = min(k, (x / y + 1) * y - x);
        x += max(1LL, step);
        while (x % y == 0) x /= y;
        k -= step;
    }
    return x + k % (y - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        ll x, y, k;
        cin >> x >> y >> k;
        cout << collatz_variant(x, y, k) << "\n";
    }
    
    return 0;
}
