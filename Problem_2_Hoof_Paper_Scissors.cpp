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
    vector<vector<int>> v(n+1, {0,0,0});
    map<char, int> mp;
    mp['P'] = 0;
    mp['H'] = 1; 
    mp['S'] = 2;
    for(int i = 1; i <= n; i++)
    {
        char x; cin >> x;
        v[i] = v[i-1];
        v[i][mp[x]]++;
    };
    int ans = 0;
    for(int i = 1; i <= n ;i++) 
    {
        int bw = max(v[i][0],max(v[i][1], v[i][2]));
        int aw = max(v[n][0] - v[i][0],max(v[n][1] - v[i][1],v[n][2] - v[i][2]));
        ans = max(ans , bw+aw);
    };
    cout << ans << endl;
}

int main()
{
    fastio();
    solve();

    return 0;
}