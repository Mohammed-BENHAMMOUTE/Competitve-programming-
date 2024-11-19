#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define tc     \
    ll tc;     \
    cin >> tc; \
    while (tc--)
#define pb push_back
#define mp make_pair
const ll MOD = 1e9 + 7;

void fastio()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

void solve() {
    string s; cin >> s;
    int n = s.size();
    long long ans = 0;
    
    // For each starting position l
    for(int l = 0; l < n; l++) {
        // For each possible ending r, looking for first "bear"
        for(int r = l+3; r < n; r++) {
            int start = max(l, r-3);
            if(r-start >= 3 && s[start] == 'b' && s[start+1] == 'e' && 
               s[start+2] == 'a' && s[start+3] == 'r') {
                ans += n-r;
                break;  
            }
        }
    }
    
    cout << ans << endl;
}
int main()
{
    solve();
    return 0;
}