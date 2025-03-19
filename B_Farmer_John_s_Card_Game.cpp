/*
 * Author: Mohammed BENHAMMOUTE
 * Created: 2025-03-19 20:13:36
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

void solve() {
    int n ,m ; cin >> n >>m;
    // we need the first row where all its elements are less than other rows ?
    // how can i check for that  ? 
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    // Create a vector of indices for the rows
    vector<int> row_indices(n);
    for (int i = 0; i < n; i++) {
        row_indices[i] = i;
    }

    // Sort rows by comparing their maximum elements
    sort(all(row_indices), [&](int a, int b) {
        int max_a = *min_element(all(grid[a]));
        int max_b = *min_element(all(grid[b]));
        return max_a < max_b;
    });
    // we have to check here if all elements of row is less than the elements of row +1 after sorting
    for(int i = 0 ; i < n-1 ; i++){
        int current = row_indices[i];
        int next = row_indices[i+1];
        bool valid = true;
        
        for(int j = 0; j < m; j++) {
            if(grid[current][j] >= grid[next][j]) {
                valid = false;
                break;
            }
        }
        
        if(!valid) {
            cout << -1 << endl;
            return;
        }
    }


    // The first row with all elements less than other rows would be the first in sorted order
    for(int i =0 ; i < n ; i++) {
        cout << row_indices[i] +1 << " ";
    }
    cout << endl;
}

int main() {
    fastIO();
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}