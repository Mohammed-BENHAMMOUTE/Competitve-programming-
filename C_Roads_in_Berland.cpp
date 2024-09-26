//#pragma once

/******************************Mohammed BENHAMMOUTE******************************/

/*** begin includes ***/
#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<vpi> vvpi;
typedef vector<vpl> vvpl;
typedef set<int> si;
typedef multiset<int> msi;
typedef set<ll> sl;
typedef multiset<ll> msl;
typedef long double ld;
template<class T> using func = function<T>;

/*** begin #defines ***/
#define clrcin cin.ignore(numeric_limits<streamsize>::max(),'\n');
#define GOGOGO ios::sync_with_stdio(false); cin.tie(nullptr);
#define BYEBYE return 0;

#define all(cn) (cn).begin(), (cn).end()
#define rep(i, n) for (int i = 0; i < n; ++i)
#define csz(c) ((int)c.size())
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define fi first
#define se second

#define popcnt __builtin_popcount
#define popcntll __builtin_popcount_ll

#define what(x) cout << #x << " = " << x << '\n'
#define cinarr(v) for (auto &x : v) cin >> x
#define coutarr(v) for (const auto &x : v) cout << x << ' '; cout << '\n'
#define coutarrp(v) for (const auto &x : v) cout << '(' << x.fi << ',' << x.se << ')'; cout << '\n'
#define coutarrP(v) for (const auto &x : v) cout << '(' << x.fi << ',' << x.se << ')'; cout << '\n'
#define coutarrnl(v) for (const auto &x : v) cout << x << '\n'
/*** end #defines ***/

 // utililty functions
template<class T> T gcd(T a, T b) { return b == 0 ? a : gcd(b, a % b); }
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
template<class T> T mod(T a, T b) { return (a % b + b) % b; }
// modmul is used to avoid overflow in multiplication
template<class T> T modmul(T a, T b, T m) {
    T r = a * b - m * ll(ld(a) * ld(b) / ld(m));
    return r + m * (r < 0) - m * (r >= m);
}
template<class T> T modinv(T a, T m) {
    T m0 = m, t, q;
    T x0 = 0, x1 = 1;
    if (m == 1) return 0;
    while (a > 1) {
        q = a / m;
        t = m, m = a % m, a = t;
        t = x0, x0 = x1 - q * x0, x1 = t;
    }
    return mod(x1, m0);
}

// graph functions
template<class T> void dfs(const vector<vector<T>> &g, vector<bool> &vis, int u) {
    vis[u] = true;
    for (const auto &v : g[u]) {
        if (!vis[v]) {
            dfs(g, vis, v);
        }
    }
}

template<class T> void bfs(const vector<vector<T>> &g, vector<bool> &vis, int u) {
    queue<int> q;
    q.push(u);
    vis[u] = true;
    while (!q.empty()) {
        u = q.front(); q.pop();
        for (const auto &v : g[u]) {
            if (!vis[v]) {
                vis[v] = true;
                q.push(v);
            }
        }
    }
}

// binary couloring function
bool is_bipartite(const vector<vector<int>> &g, vector<int> &color, int u, int c) {
    color[u] = c;
    for (const auto &v : g[u]) {
        if (color[v] == c) return false;
        if (color[v] == -1 && !is_bipartite(g, color, v, 1 - c)) return false;
    }
    return true;
}

// prime sieve
vector<int> sieve(int n) {
    vector<int> primes;
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (int j = i * 2; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
    return primes;
}

// prime factorization
vector<pair<int, int>> prime_factorization(int n) {
    vector<pair<int, int>> factors;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            int cnt = 0;
            while (n % i == 0) {
                n /= i;
                ++cnt;
            }
            factors.emplace_back(i, cnt);
        }
    }
    if (n > 1) {
        factors.emplace_back(n, 1);
    }
    return factors;
}

// fast exponentiation
ll fastpow(ll a, ll b, ll m) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) {
            res = res * a % m;
        }
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

// dp functions
template<class T> T knapsack(const vector<T> &w, const vector<T> &v, T W) {
    int n = csz(w);
    vector<vector<T>> dp(n + 1, vector<T>(W + 1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= W; ++j) {
            dp[i][j] = dp[i - 1][j];
            if (j >= w[i - 1]) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i - 1]] + v[i - 1]);
            }
        }
    }
    return dp[n][W];
}

template<class T> T lcs(const vector<T> &a, const vector<T> &b) {
    int n = csz(a), m = csz(b);
    vector<vector<T>> dp(n + 1, vector<T>(m + 1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[n][m];
}

template<class T> T lis(const vector<T> &a) {
    int n = csz(a);
    vector<T> dp;
    for (const auto &x : a) {
        auto it = lower_bound(all(dp), x);
        if (it == dp.end()) {
            dp.pb(x);
        } else {
            *it = x;
        }
    }
    return csz(dp);
}

 // binary search lower bound upper bound for binary search on the answer
template<class T> T lower_bound(const vector<T> &a, T x) {
    int l = -1, r = csz(a);
    while (r - l > 1) {
        int m = (l + r) / 2;
        if (a[m] >= x) {
            r = m;
        } else {
            l = m;
        }
    }
    return r;
}

template<class T> T upper_bound(const vector<T> &a, T x) {
    int l = -1, r = csz(a);
    while (r - l > 1) {
        int m = (l + r) / 2;
        if (a[m] > x) {
            r = m;
        } else {
            l = m;
        }
    }
    return r;
}

const int INFI = 1e9 + 5;
const ll INFL = 1e18 + 5;
const ld EPS = 1e-9;
const ll MOD = 1e9 + 7;
const ld PI = 3.14159265358979323846;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
auto dist = uniform_int_distribution<int>(0, INFI);
auto distll = uniform_int_distribution<ll>(0, INFL);
int rnd() { return dist(rng); }
ll rndl() { return distll(rng); }

void solve() {
    int n; cin >> n;
    vvi dist(n, vi(n));
    ll totalsum =0 ;
    for(int i =0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> dist[i][j];
            // totalsum += dist[i][j];
        }
    };
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            totalsum += dist[i][j];
        }
    };
    // what(totalsum);

    int k; cin >> k;
    vl ans(k);
    for(int l =0 ; l <k ; l++) {
        int a , b, c;
        cin >> a >> b >> c;
        a--; b--;
        if(dist[a][b] >c){
            // dist[a][b] = c;
            // dist[b][a] = c;
            for(int i =0; i< n ; i++) {
                for(int j =0 ; j < n ; j++) {
                    int newDist = min(
                        dist[i][j],
                        min(dist[i][a]+ c + dist[b][j],
                        dist[i][b]+ c + dist[a][j])
                    );
                    // what(newDist);
                    // what(dist[i][j]);
                    // what(dist[i][j] - newDist);
                    totalsum -= (dist[i][j] - newDist);
                    // what(totalsum);
                    dist[i][j] = newDist;
                    dist[j][i] = newDist;
                };
            };
        };
        ans[l] = totalsum;
    };
    for(const auto &x : ans) {
        cout << x << ' ';
    };
    cout << '\n';
    return;
}

int main() {
    GOGOGO
    solve();
    BYEBYE
}