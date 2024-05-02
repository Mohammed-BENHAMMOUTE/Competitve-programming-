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
    };
    string ans = "";
    ans += s[0];
    for(int i=1; i< n-1; i++){
        if(s[i] == s[i-1] && s[i] == s[i+1]){
            continue;
        };
        ans+=s[i];
    };
    ans += s[n-1];
    for(int i=0; i<ans.size(); i++){
        if(i +3< ans.size() && ans[i] == ans[i+1] && ans[i+2] == ans[i+3]){
            ans.erase(ans.begin() +i+2);
        };
    };
    cout << ans<<endl;
}

int main()
{
    fastio();
    solve();
    return 0;
}