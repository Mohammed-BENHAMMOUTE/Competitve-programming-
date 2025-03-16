/*
 * Author: Mohammed BENHAMMOUTE
 * Created: 2025-03-16 01:41:35
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
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        freopen("error.txt", "w", stderr);
    #endif
}
struct DSU {
    vector<int> parent, size;
    
    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for(int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if(parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    bool unite(int x, int y) {
        int root_x = find(x);
        int root_y = find(y);
        
        if(root_x == root_y)
            return false;
            
        // Merge smaller set into larger set
        if(size[root_x] < size[root_y])
            swap(root_x, root_y);
            
        parent[root_y] = root_x;
        size[root_x] += size[root_y];
        return true;
    }
    
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    
    int get_size(int x) {
        return size[find(x)];
    }
};

void solve() {
    int n, q; cin >> n >> q;
    vector<pair<int,pair<int,int>>> edges;
    unordered_map<int, vector<pair<int,int>>> divisor_to_edges; // Store edges by divisor
    int max_w = 0;
    
    // Read edges and organize by weight
    for(int i = 0; i < n-1; i++){
        int x, y, w; cin >> x >> y >> w;
        x--; y--;
        edges.push_back({w, {x, y}});
        max_w = max(max_w, w);
    }
    
    // Precompute divisors for each edge
    for(auto [w, p] : edges) {
        // Find all divisors of w
        for(int d = 1; d * d <= w; d++) {
            if(w % d == 0) {
                // d is a divisor
                divisor_to_edges[d].push_back(p);
                // w/d is also a divisor (if different from d)
                if(d != w/d) {
                    divisor_to_edges[w/d].push_back(p);
                }
            }
        }
    }
    
    unordered_map<int, ll> memo;
    for(int i = 0; i < q; i++) {
        int D; cin >> D;
        
        if(memo.find(D) != memo.end()) {
            cout << memo[D] << endl;
            continue;
        }
        
        if(D > max_w) {
            memo[D] = n * (n-1) / 2; // All paths are valid when D=1 or all edges divisible by D
            cout << memo[D] << endl;
            continue;
        }
        
        DSU dsu(n);
        // Only process edges that are divisible by D
        if(divisor_to_edges.find(D) != divisor_to_edges.end()) {
            for(auto [x, y] : divisor_to_edges[D]) {
                dsu.unite(x, y);
            }
        }
        
        ll ans = 0;
        vector<bool> visited(n, false);
        for(int j = 0; j < n; j++) {
            int root = dsu.find(j);
            if(!visited[root]){
                visited[root] = true;
                int size = dsu.get_size(root);
                ans += (ll)size * (size-1) / 2;
            }
        }
        
        memo[D] = ans;
        cout << ans << endl;
    }
}
int main() {
    fastIO();
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}