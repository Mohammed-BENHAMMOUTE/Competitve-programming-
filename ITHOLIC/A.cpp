/*
 * Author: Mohammed BENHAMMOUTE
 * Created: 2025-03-16 13:00:34
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
    cout << fixed << setprecision(10);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    //     freopen("error.txt", "w", stderr);
    // #endif
}

void solve() {
    string s; cin >> s;
    bitset<5> bits(0);
    int n = s.size(); 
    ll sum = 0;
    for(int i = n-1; i >= 0 ; i--) {
        int indx = s[i] - 'A';
        bool flag = false;
        for(int j = 4 ; j > indx ; j--){
            if(bits[j] == 1){
                sum -= pow(10 , indx);
                flag = true;
                break;
            }
        }
        if(!flag){
            sum += pow(10, indx);
        }
        bits[indx] = 1;
    }
    bitset<5> elements(0);
    ll minel = 0;
    for(int i = n-1; i >= 0 ; i--) {
        int indx = s[i] - 'A';
        ll num = 0;
        bool flag = false;
        for(int j = 4 ; j > indx ; j--){
            if(elements[j] == 1){
                num = -pow(10 , indx);
                flag = true;
                break;
            }
        }
        if(!flag){
            num = pow(10, indx);
        }
        elements[indx] = 1;
        minel = min(minel , num);
    }
    // cout << minel << endl;
    sum -= minel ;
    if(minel != 0) {
        sum += pow(10 ,4);
    }else{
        ll temp = 0 ;
        ll clone = sum ; 
        for( int i=0 ; i<n ; ++i ){
            if( s[i] != 'E' ){
                // cout << "test " << temp << "  " << sum ; 
                ll num = pow( 10 , 4 ) - pow( 10 , s[i] - 'A')  ; 
                sum = max( sum , (clone  + num - temp) ) ;   
                temp += pow( 10 , s[i] - 'A' ) ; 
            }
        }
       
     }
    cout<< sum << endl;
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