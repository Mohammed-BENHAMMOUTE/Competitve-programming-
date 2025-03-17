/*
 * Author: Mohammed BENHAMMOUTE
 * Created: 2025-03-16 12:42:22
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
// Fast I/O
void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // cout << fixed << setprecision(10);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    //     freopen("error.txt", "w", stderr);
    // #endif
}

void solve() {
    string s;cin>>s;
    int ans  = INT_MAX;
    int n = s.size();
    for(int i = 0; i<n;i++){
        int BL=0, BR=0,RL=0,RR=0;
        for(int j = 0; j<i;j++){

            if(s[j] == 'R'){
                RL++;
            }
            else{
                BL++;
            }
        }
        for(int j = i; j<n;j++){
            if(s[j] == 'R'){
                RR++;
            }
            else{
                BR++;
            }
        }
        ans = min(ans, min(BL+RR, RL+BR));
    }
    cout<<ans<<"\n";
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