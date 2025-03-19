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
}

void solve() {
    string s; cin >> s;
    int n = s.size();
    
    vector<ll> powers = {1, 10, 100, 1000, 10000};

    ll original_score = 0;
    vector<bool> seen(5, false);
    
    for (int i = n-1; i >= 0; i--) {
        int digit = s[i] - 'A';
        bool negative = false;
        
        for (int j = 4; j > digit; j--) {
            if (seen[j]) {
                negative = true;
                break;
            }
        }
        
        if (negative) {
            original_score -= powers[digit];
        } else {
            original_score += powers[digit];
        }
        
        seen[digit] = true;
    }
    
    ll max_score = original_score;
    
    for (int i = 0; i < n; i++) {
        int original_digit = s[i] - 'A';
        
        for (int new_digit = 0; new_digit < 5; new_digit++) {
            if (new_digit == original_digit) continue;
            
            string modified = s;
            modified[i] = 'A' + new_digit;
            
            ll score = 0;
            vector<bool> seen(5, false);
            
            for (int j = n-1; j >= 0; j--) {
                int digit = modified[j] - 'A';
                bool negative = false;
                
                for (int k = 4; k > digit; k--) {
                    if (seen[k]) {
                        negative = true;
                        break;
                    }
                }
                
                if (negative) {
                    score -= powers[digit];
                } else {
                    score += powers[digit];
                }
                
                seen[digit] = true;
            }
            
            max_score = max(max_score, score);
        }
    }
    cout << max_score << endl;
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