#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define pb push_back
#define mp make_pair
const ll MOD = 1e9 + 7;

void fastio()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
};

ll solve(int n , int k)
{
    ll res = 1;
    for (ll i = 1; i <= k; ++i)
    {
        res = res*(n-k+i)/i;
    }
    return (int) (res+0.01);
}

int main()
{
    fastio();
    int n,m;
    while(cin >> n && n != 0)
    {
        cin >> m;
        cout << n << " things taken " << m  << " at a time is " << solve(n,m) << " exactly."<<endl;
    };
    return 0;
}