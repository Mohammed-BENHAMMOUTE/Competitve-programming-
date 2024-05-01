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
};

void solve()
{
    string s; cin >> s;
    int n = s.size();
    if(n<=2) {
        cout << s << endl;
        return;
    }
    string ans;
    for(int i = 0; i< n-1; i++) {
        if(s[i] != s[i+1]){
            ans.pb(s[i]);
        };
        int j = i;
        while(s[j+1] == s[i]) {
            j++;
        };
        int dist = j -i;
        if(dist>= 3){
            ans.pb(s[i]);
            ans.pb(s[i+1]);
            i = j;
            continue;
        }
        if(dist == 2){
            if(j+2<n){
                
            }
        }
    };
    cout << ans << endl;

}

int main()
{
    fastio();
    solve();
    return 0;
}