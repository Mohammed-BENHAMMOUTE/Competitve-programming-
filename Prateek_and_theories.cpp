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
    vector<ll> start(n), end(n);
    for(int i = 0; i < n; i++){
        cin >> start[i] >> end[i];
    }
    sort(start.begin(), start.end());
    sort(end.begin(), end.end());

    int i =0, j=0; ll ans= 0; ll mx =0;
    while(i < n && j < n){
        if(start[i] < end[j]) {
            i++;
            ans++;
        }else{
            ans--;
            j++;
        }
        mx = max(mx, ans);
    };
    cout << mx <<endl;
    return;
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