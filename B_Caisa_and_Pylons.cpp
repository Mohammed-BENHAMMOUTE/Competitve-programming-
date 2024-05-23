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
    ll n; cin >>n;
    int y,x;
    x = 0;
    ll e = 0;
    ll b = 0;
    for(int i = 1; i <= n; i++) {
        cin >> y;
        e+=(x-y);
        if( e< 0){
            b+=-e;
            e = 0;
        };
        x =y;
    };
    cout << b<< endl;
    return;
};
int main()
{
    fastio();
    solve();
    return 0;
};