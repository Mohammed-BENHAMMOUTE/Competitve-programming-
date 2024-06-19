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
    int n;cin >> n;
    vector<ll> a(n+1);
    for (int i = 1; i <= n; ++i) {

        cin >> a[i];
        if(a[i]&1) a[i] = -1;
        else a[i] = 1;
    };
    map<ll, ll> m;
    m[0] = 1;
    ll ans = 0;
    for(int i = 1; i <= n; ++i) {
        a[i] += a[i-1];
        ans += m[a[i]];
        m[a[i]]++;
    }
    cout << ans << endl;
    
}

int main()
{
    fastio();
    solve();

    return 0;
}