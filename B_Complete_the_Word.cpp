/*
 * Author: Mohammed BENHAMMOUTE
 * Created: 2025-02-28 09:28:06
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
    string s; cin >> s;
    int n = s.size();
    
    // If string length is less than 26, it can't have a valid substring
    if(n < 26) {
        cout << -1 << endl;
        return;
    }
    
    // Check each possible substring of length 26
    for(int start = 0; start <= n - 26; start++) {
        vector<int> charCount(26, 0);
        vector<int> missingPos;
        
        // Count characters in this substring
        for(int i = 0; i < 26; i++) {
            int pos = start + i;
            if(s[pos] == '?') {
                missingPos.push_back(pos);
            } else {
                charCount[s[pos] - 'A']++;
            }
        }
        
        // Check if we can form a valid substring
        bool possible = true;
        vector<char> charsToFill;
        
        for(int i = 0; i < 26; i++) {
            if(charCount[i] > 1) {
                possible = false;
                break;
            } else if(charCount[i] == 0) {
                charsToFill.push_back('A' + i);
            }
        }
        
        // If possible, fill in the missing characters
        if(possible && charsToFill.size() == missingPos.size()) {
            for(int i = 0; i < missingPos.size(); i++) {
                s[missingPos[i]] = charsToFill[i];
            }
            
            // Fill any remaining '?' with 'A'
            for(int i = 0; i < n; i++) {
                if(s[i] == '?') {
                    s[i] = 'A';
                }
            }
            
            cout << s << endl;
            return;
        }
    }
    
    cout << -1 << endl;
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