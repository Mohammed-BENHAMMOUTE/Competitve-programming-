/*
 * Author: Mohammed BENHAMMOUTE
 * Created: 2025-09-07 00:11:45
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
vector<int> parent;
vector<int> cycle_path;

bool dfs(int u, int p, vector<bool>& visited, vector<vector<int>>& adj) {
    visited[u] = true;
    parent[u] = p;
    
    for (int v : adj[u]) {
        if (v == p) continue; // Skip parent to avoid immediate back-tracking
        
        if (!visited[v]) {
            // Continue DFS on unvisited neighbor
            if (dfs(v, u, visited, adj)) {
                return true;
            }
        } else {
            // Found a back edge - this creates a cycle
            cycle_path.clear();
            
            // Reconstruct the cycle path from u back to v
            int curr = u;
            while (curr != v) {
                cycle_path.push_back(curr);
                curr = parent[curr];
            }
            cycle_path.push_back(v);
            cycle_path.push_back(u); // Complete the cycle
            
            return true;
        }
    }
    
    return false;
}


void solve() {
    int n, m; 
    cin >> n >> m;
    
    // Initialize data structures
    parent.assign(n + 1, -1);
    vector<vector<int>> adj(n + 1);
    vector<bool> visited(n + 1, false);
    
    // Read edges and build adjacency list
    for (int i = 0; i < m; i++) {
        int a, b; 
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // Try to find a cycle starting from each unvisited node
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, visited, adj)) {
                // Cycle found - output the result
                cout << cycle_path.size() << "\n";
                for (int node : cycle_path) {
                    cout << node << " ";
                }
                cout << "\n";
                return;
            }
        }
    }
    
    // No cycle found
    cout << "IMPOSSIBLE\n";
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