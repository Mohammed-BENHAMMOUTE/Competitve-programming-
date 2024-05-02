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

void solve()
{
    int L; cin >> L;
    int P; cin >>P;
    string ans = "";
    ans+="[";
    if(P == 0) {
        for(int i = 0; i<L; i++) {
            ans+="-";
        };
        ans+="]";
        cout << ans << endl;
        return;
    };
    double c = (double)P/100;
    int x = x = floor((double)L*c);
    // cout << x << endl;
    for(int i = 0; i<x; i++) {
        if(i == 0){
            ans+="A";
            continue;
        };
        if(i == 1) {
            ans+="z";
            continue;
        }
        if(i == L-1){
            ans+="z";
            continue;
        }
        ans+="u";
    };
    for(int i = x; i<L; i++) {
        ans+="-";
    };
    ans+="]";
    cout << ans << endl;

}

int main()
{
    fastio();
    ll t;
    cin >> t;
    for (ll i = 1; i <= t; i++)
    {
        solve();
    }

    return 0;
}