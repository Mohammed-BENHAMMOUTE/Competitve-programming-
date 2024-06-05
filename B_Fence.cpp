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
    vector<int> v(n+1);
    for(int i =1; i < n+1; i++) 
    {
        cin >> v[i];
    };
    for(int i = 1; i <=n; i++) 
    {
        v[i]+=v[i-1];
    };
    int start = 0;
    int end = k;
    int mn = INT_MAX;
    int ans = 0;
    while(end <v.size()) 
    {
        if(mn > (v[end] - v[start])){
            ans = start;
            mn =(v[end] - v[start]);
        };
        end++;start++;
        
    };
    cout << ans+1 << endl;
};

int main()
{
    fastio();
    solve();

    return 0;
}