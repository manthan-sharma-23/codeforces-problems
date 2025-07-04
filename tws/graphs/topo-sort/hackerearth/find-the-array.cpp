#include <bits/stdc++.h>
using namespace std;
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); --i)
#define FORall(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define sz(a) int((a).size())
#define present(t, x) (t.find(x) != t.end())
#define all(a) (a).begin(), (a).end()
#define uni(a) (a).erase(unique(all(a)), (a).end())
#define pb push_back
#define pf push_front
#define mp make_pair
#define fi first
#define se second
#define prec(n) fixed<<setprecision(n)
#define bit(n, i) (((n) >> (i)) & 1)
#define bitcount(n) __builtin_popcountll(n)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
const int MOD = (int) 1e9 + 7;
const int FFTMOD = 119 << 23 | 1;
const int INF = (int) 1e9 + 23111992;
const ll LINF = (ll) 1e18 + 23111992;
const ld PI = acos((ld) -1);
const ld EPS = 1e-9;
inline ll gcd(ll a, ll b) {ll r; while (b) {r = a % b; a = b; b = r;} return a;}
inline ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
inline ll fpow(ll n, ll k, int p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
template<class T> inline int chkmin(T& a, const T& val) {return val < a ? a = val, 1 : 0;}
template<class T> inline int chkmax(T& a, const T& val) {return a < val ? a = val, 1 : 0;}
inline ull isqrt(ull k) {ull r = sqrt(k) + 1; while (r * r > k) r--; return r;}
inline ll icbrt(ll k) {ll r = cbrt(k) + 1; while (r * r * r > k) r--; return r;}
inline void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
inline void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
inline int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
inline int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}
inline int sign(ld x) {return x < -EPS ? -1 : x > +EPS;}
inline int sign(ld x, ld y) {return sign(x - y);}
mt19937 mt(chrono::high_resolution_clock::now().time_since_epoch().count());
inline int myrand() {return abs((int) mt());}
#define db(x) cerr << #x << " = " << (x) << " ";
#define endln cerr << "\n";

const int maxn = 1e5 + 5;
int n, m;
int a[maxn];
int b[maxn];
vi adj[maxn];
vi radj[maxn];

vi ver;
int vis[maxn];
int f[maxn];
void dfs(int u) {
    vis[u] = 1;
    for (int v : adj[u]) {
        if (!vis[v]) {
            dfs(v);
        }
    }
    f[u] = sz(ver);
    ver.pb(u);
}

int check(int mi) {
    reverse(all(ver));
    for (int u : ver) {
        int mx = INF + INF;
        for (int v : radj[u]) {
            chkmin(mx, a[v] - 1);
        }
        if (u < mi) {
            if (b[u] > mx) {
                reverse(all(ver));
                return 0;
            }
            a[u] = b[u];
        }
        else {
            a[u] = mx;
        }
        if (a[u] <= 0) {
            reverse(all(ver));
            return 0;
        }
    }
    reverse(all(ver));

    FOR(u, 0, n) {
        if (a[u] > b[u]) {
            return 1;
        }
        if (a[u] < b[u]) {
            return 0;
        }
    }
    return 0;
}

int finish(int mi) {
    for (int u : ver) {
        int mx = 1;
        for (int v : adj[u]) {
            chkmax(mx, a[v] + 1);
        }
        if (u < mi) {
            if (b[u] < mx) {
                return 0;
            }
            a[u] = b[u];
        }
        else if (u == mi) {
            a[u] = max(b[u] + 1, mx);
        }
        else {
            a[u] = mx;
        }
    }
    return 1;
}

void eof() {
    string s; assert(!(cin >> s));
}

void chemthan() {
    int test; assert(cin >> test);
    assert(1 <= test && test <= 5);
    while (test--) {
        assert(cin >> n >> m);
        assert(1 <= n && n <= 1e5);
        assert(0 <= m && m <= 1e5);
        FOR(i, 0, n) adj[i].clear(), radj[i].clear(), vis[i] = 0;
        FOR(i, 0, n) {
            assert(cin >> b[i]);
            assert(1 <= b[i] && b[i] <= 1e9);
        }
        FOR(i, 0, m) {
            int u, v; string sign; assert(cin >> u >> sign >> v); u--, v--;
            assert(0 <= u && u < n);
            assert(0 <= v && v < n);
            assert(sign == "<" || sign == ">");
            if (sign == "<") swap(u, v);
            adj[u].pb(v), radj[v].pb(u);
        }
        ver.clear();
        FOR(u, 0, n) if (!vis[u]) {
            dfs(u);
        }
        int found = 0;
        FOR(u, 0, n) {
            for (int v : adj[u]) {
                if (f[u] < f[v]) {
                    found = 1;
                }
            }
        }
        if (found) {
            cout << "NO\n";
            continue;
        }
        int lo = 0, hi = n - 1;
        while (lo < hi) {
            int mi = lo + hi + 1 >> 1;
            if (check(mi)) {
                lo = mi;
            }
            else {
                hi = mi - 1;
            }
        }
        assert(check(lo + hi >> 1));
        assert(finish(lo + hi >> 1));
        cout << "YES\n";
        FOR(i, 0, n) cout << a[i] << " \n"[i == n - 1];
    }
    eof();
}

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(0), cin.tie(0);
    if (argc > 1) {
        assert(freopen(argv[1], "r", stdin));
    }
    if (argc > 2) {
        assert(freopen(argv[2], "wb", stdout));
    }
    chemthan();
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}