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
    int n, k; cin >> n >> k;
    int v[1000000+1];
    for(int i = 1; i <= k; i++) 
    {
        int a,b; cin >> a >> b;
        a--; b--;
        v[a]++;
        v[b+1]--;
    };
    int ans = 0;
    int curr = 0;
    for(int i = 0; i < n; i++) 
    {  
        curr += v[i];
        v[i] = curr;
    };
    sort(v, v+n);
    cout << v[n/2] << endl;
    
}

int main()
{
    fastio();
    solve();

    return 0;
}