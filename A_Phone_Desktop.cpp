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
    int x, y; cin >> x >> y;
    if(x==0 && y==0)
    {
        cout << 0 << endl;
        return;
    }
    int max = 15;
    int a = x + 4*y;
    if(a<max)
    {
        cout << 1 << endl;
        return;
    }else{
        cout << ceil((double)a/max) << endl;
    };
};
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