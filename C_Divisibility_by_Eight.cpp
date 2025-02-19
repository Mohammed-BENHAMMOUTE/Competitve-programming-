/*
 * Author: Mohammed BENHAMMOUTE
 * Created: 2025-02-19 11:54:33
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
    string s; cin >>s;
    int n = s.size();
    for(int i = 0 ; i < n ;i++) {
        if(s[i] == '0' || s[i] == '8'){
            cout << "YES" << endl;
            cout << s[i] << endl;
            return;
        }
        for(int j = i+1 ; j < n ;j++){
            if(s[j] == '0' || s[j] == '8'){
                cout << "YES" << endl;
                cout << s[j] << endl;
                return;
            }
            int temp = (s[i] - '0')* 10+ (s[j] - '0');
            // cout << temp << endl;
            if(temp%8 == 0){
                cout << "YES" << endl;
                cout << temp << endl;
                return;
            }
            for(int k = j +1 ; k < n; k++){
                if(s[k] == '0' || s[k] == '8'){
                    cout << "YES" << endl;
                    cout << s[k] << endl;
                    return;
                }
                int temp2 = (s[i] - '0')* 100 + (s[j] - '0') * 10 + (s[k] - '0');
                if(temp2 %8 == 0){
                    cout << "YES" <<endl;
                    cout << temp2 <<endl;
                    return;
                }
            }
        };
       
    }
    cout << "NO" <<endl;
    return;
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