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
    int n;cin >> n;
    vector<ll> a(n+1);
    ll ans = 0; 
    int minDiff = INT_MAX;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    };
    vector<ll> b(n+1);
    for(int i = 0; i <= n; i++){
        cin >> b[i];
    };
    for(int i = 0; i < n; i++){
        if(abs(a[i] - b[n])< minDiff){
            minDiff = abs(a[i] - b[n]);
            ans = a[i];
        }
        if(abs(b[i] - b[n])< minDiff){
            minDiff = abs(b[i] - b[n]);
            ans = b[i];
        };
    };
    ll last = b[n];

    
    ll count = 0;
    bool flag = true;
    for(int i = 0; i < n ; i++) 
    {
        count += abs(a[i] - b[i]);
        if(last <= max(a[i], b[i]) && last >= min(a[i], b[i])&& flag){
            count += 1;
            a[n] = b[n];
            flag = false;
        };
    };
    if(a[n] == b[n]){
        cout << count << endl;
    }else{
        a[n]= ans;
        count += abs(a[n] - b[n])+1;
        cout << count << endl;
    };
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