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
    ll n, k;
    cin >> n >> k;
    if(n == 1) {
        cout << n+k << endl;
        return;
    }
    deque<ll> a;
    for(int i = 0; i < n; i++){
        ll x; cin >> x;
        a.pb(x);
    
    };
    sort(a.begin(), a.end());
    while(k>0 && a.size()>1){
        if(k>=a[1]-a[0]){
            cout <<"here";
            cout << a[1]- a[0]<<endl;
            k-=a[1]-a[0];
            a.pop_front();
        } else {
            a[0]+=k;
            k = 0;
        }
    };
    sort(a.begin(), a.end());
    int min = a.front();
    cout << min<<endl;
    cout << min + (min -1)*(n-1) << endl;
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