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
    deque<ll> a;
    for(int i = 0; i < n; i++){
        ll x; cin >> x;
        a.pb(x);
    };
    sort(a.begin(), a.end());
    vector<ll> b;
    for(int i = 0; i < n; i++){
        ll x; cin >> x;
        b.pb(x);
    };
    sort(b.begin(), b.end());
    int count = 0;
    for(int i = 0; i< n ; i++) {
        if(a[i]> b[i]){
            a.push_front(a[i]);
            a.pop_back();
            count++;
            sort(a.begin(), a.end());
        }
    };
    cout << count << endl;
    
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