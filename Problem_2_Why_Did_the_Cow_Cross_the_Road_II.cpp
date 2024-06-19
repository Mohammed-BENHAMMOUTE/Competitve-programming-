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
    int n,k,b; cin >> n >> k >> b;
    vector<int> v(n+1, 1);
    for(int i = 0; i < b; i++)
    {
        int x; cin >> x;
        v[x] = 0;
    };
    vector<int> pre(n+1, 0);
    for(int j =1; j <= n; j++) 
    {
        pre[j] = pre[j-1]+abs(v[j]-1);
    };
    int ans =  n+1;
    for(int i = k; i <= n; i++)
    {
        ans = min(ans, pre[i]-pre[i-k]);
    };
    cout << ans << endl;
}

int main()
{
    fastio();
    solve();
    return 0;
}