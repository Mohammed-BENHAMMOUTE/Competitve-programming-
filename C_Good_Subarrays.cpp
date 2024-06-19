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
    string s; cin >> s;
    map<ll, ll> a;
    a[0] = 1;
    ll sum = 0;
    ll ans = 0;
    for(int i =0; i <n ;i++)
    {
        sum += s[i] - '0';
        ans+= a[(sum-i-1)];
        a[(sum-i-1)]++; 
    };
    cout << ans << endl;

}

int main()
{
    fastio();
    tc{
        solve();
    };

    return 0;
}