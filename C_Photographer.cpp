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
    ll n,d; cin >> n >> d;// n = number of clients and  d = the camera memory size.
    
    int a,b; cin >> a >> b;// a=the size of the low quality pic // b = the size of the high quality pic
    vector<pair<ll, ll>> v;
    for(int i = 1; i<=n ; i++) {
        ll x, y; cin >> x >> y;
        v.pb(mp(x*a + y*b, i));
    };
    sort(v.begin(), v.end());
    vector<int> ans;
    for(pair x : v) {
        if(d- x.first >= 0) {
            d -= x.first;
            ans.pb(x.second);
        } else {
            break;
        };
    };
    cout << ans.size() << endl;
        for(int x : ans) {
            cout << x << " ";
        }

    
    return;

};

int main()
{
    fastio();
    solve();

    return 0;
}