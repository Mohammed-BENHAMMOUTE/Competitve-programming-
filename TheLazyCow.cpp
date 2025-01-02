/*
 * Author: Mohammed BENHAMMOUTE
 * Created: 2024-12-29 15:09:57
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
int arr[101][101];
void solve() {
    int n, k; cin >> n >> k;
    // rep(i , 0, n){
    //     rep(j, 0 , n){
    //         cin >> arr[i][j];
    //     }
    // }
    // to do prefixe sum i need to rotate the matrix 45 degress, and insert 0s in the appropriate places
    int nn = 2*n -1;
    vector<vector<int>> field(nn, vector<int>(nn,-1));
    rep(i, 0, n){
        rep(j , 0, n) {
            cin >> field[i+j][n-i+j-1];
        }
    }
    vector<vector<int>> prefix(nn+1, vector<int>(nn+1));
    rep(i, 0,nn){
        rep(j, 0, nn){
            int val = max(field[i][j], 0);
            prefix[i+1][j+1] = val + prefix[i][j+1] + prefix[i+1][j] - prefix[i][j];
        }
    }

    int most_grass = 0;
    rep(i,k, nn-k){
        rep(j , k, nn-k) {
            if(field[i][j] == -1) {
                continue;
            }
        

            most_grass = max(most_grass, prefix[i+k+1][j+k+1] - prefix[i+k+1][j-k] - prefix[i-k][j+k+1] + prefix[i-k][j-k]);
        }
    }
    if(k>= n){
        most_grass = prefix[nn][nn];
    }
    cout << most_grass << endl;
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