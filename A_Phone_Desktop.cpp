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
    int x,y; cin >> x >> y;
    int ans = 0;
    if(x == 0 && y ==0){
        cout << 0 << endl;
        return;
    }
    while(x != 0 || y != 0)
    {
        int page = 15;
        int min_y = min(2, y);
        page -= 4*min_y;
        y -= min_y;
        int min_x = min(x, page);
        page -= min_x;
        x -= min_x;
        ans++;
    }
    cout << ans <<endl;
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