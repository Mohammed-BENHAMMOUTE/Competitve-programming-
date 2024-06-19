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
    int n; cin >> n;
    vector<ll> v(n);
    int maxIndx = 0;
    ll maxVal = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
        if(v[i] >= maxVal)
        {
            maxVal = v[i];
            maxIndx = i;
        }
    };
    ll ans = v[n-1];
    auto it = max_element(v.begin(), v.begin()+n-1);
    ans+= *it;
    cout << ans << endl;
    return;
}

int main()
{
    fastio();
    tc
    {
        solve();
    }

    return 0;
}
