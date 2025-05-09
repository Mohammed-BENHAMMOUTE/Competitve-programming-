/*
 * Author: Mohammed BENHAMMOUTE
 * Created: 2025-02-18 17:27:14
 */
#include <bits/stdc++.h>
using namespace std;

// Debug macros
#define debug(x) cerr << #x << " = " << x << endl
#define debugv(v) cerr<<#v<<" = ";for(auto e:v)cerr<<e<<" ";cerr<<endl
#define debugm(m) cerr<<#m<<endl;for(auto e:m)cerr<<e.first<<" "<<e.second<<endl
#define debuga(a,n) cerr<<#a<<" = ";for(int i=0;i<n;i++)cerr<<a[i]<<" ";cerr<<endl
#define debugma(a,n,m) cerr<<#a<<":\n";for(int i=0;i<n;i++){for(int j=0;j<m;j++)cerr<<a[i][j]<<" ";cerr<<endl;}

// Type definitions
#define ll long long
#define ld long double
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vi vector<int>
#define vl vector<ll>
#define vvi vector<vi>
#define vvl vector<vl>
#define vpii vector<pii>
#define vpll vector<pll>

// Shortcuts
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define sz(x) (int)x.size()
#define rep(i,a,b) for(int i=a;i<b;i++)
#define per(i,a,b) for(int i=b-1;i>=a;i--)

// Constants
const int MOD = 1e9+7;
const ll INF = 1e18;
const ld PI = acos(-1.0);
const int dx[8] = {1,-1,0,0,1,1,-1,-1};
const int dy[8] = {0,0,1,-1,1,-1,1,-1};

// Utility functions
template<typename T> inline T gcd(T a, T b) {return b ? gcd(b, a%b) : a;}
template<typename T> inline T lcm(T a, T b) {return a * (b/gcd(a,b));}
template<typename T> inline T mod(T a, T b) {return (a%b + b)%b;}
template<typename T> inline T modpow(T a, T b, T m) {T r=1; while(b) {if(b&1) r=r*a%m; a=a*a%m; b>>=1;} return r;}

// Vector operations
template<typename T> void amax(T &a, T b) {if(b > a) a = b;}
template<typename T> void amin(T &a, T b) {if(b < a) a = b;}
template<typename T> void print(vector<T> &v) {for(auto x:v) cout<<x<<" "; cout<<endl;}
template<typename T> void print2d(vector<vector<T>> &v) {for(auto x:v) {for(auto y:x) cout<<y<<" "; cout<<endl;}}

// Fast I/O
void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << fixed << setprecision(10);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    //     freopen("error.txt", "w", stderr);
    // #endif
}
void solve() {
    int x1, y1, x2, y2;
    x1 = min(x1 ,x2); x2 = max(x1, x2);
    y1 = min(y1, y2); y2 = max(y1 ,y2);
    cin >> x1 >> y1 >> x2 >> y2;
    
    // Normalize coordinates to ensure x1 <= x2 and y1 <= y2
    if (x1 > x2) swap(x1, x2);
    if (y1 > y2) swap(y1, y2);
    
    int n; cin >> n;
    vector<tuple<int, int, int>> heaters(n);
    for (int i = 0; i < n; i++) {
        int x, y, r;
        cin >> x >> y >> r;
        heaters[i] = {x, y, r};
    }
    
    int count = 0;
    
    // Check bottom edge (y=y1)
    for (int i = x1; i <= x2; ++i) {
        bool cold = true;
        for (auto [x, y, r] : heaters) {
            long long dist = (x - i) * 1LL * (x - i) + (y - y1) * 1LL * (y - y1);
            if (dist <= r * 1LL * r) {
                cold = false;
                break;
            }
        }
        if (cold) count++;
    }
    
    // Check top edge (y=y2)
    for (int i = x1; i <= x2; ++i) {
        bool cold = true;
        for (auto [x, y, r] : heaters) {
            long long dist = (x - i) * 1LL * (x - i) + (y - y2) * 1LL * (y - y2);
            if (dist <= r * 1LL * r) {
                cold = false;
                break;
            }
        }
        if (cold) count++;
    }
    
    // Check left edge (x=x1), excluding corners
    for (int i = y1 + 1; i < y2; ++i) {
        bool cold = true;
        for (auto [x, y, r] : heaters) {
            long long dist = (x - x1) * 1LL * (x - x1) + (y - i) * 1LL * (y - i);
            if (dist <= r * 1LL * r) {
                cold = false;
                break;
            }
        }
        if (cold) count++;
    }
    
    // Check right edge (x=x2), excluding corners
    for (int i = y1 + 1; i < y2; ++i) {
        bool cold = true;
        for (auto [x, y, r] : heaters) {
            long long dist = (x - x2) * 1LL * (x - x2) + (y - i) * 1LL * (y - i);
            if (dist <= r * 1LL * r) {
                cold = false;
                break;
            }
        }
        if (cold) count++;
    }
    cout << count << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}