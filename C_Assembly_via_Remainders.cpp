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
    int n ;cin >> n;
    vector<ll> x(n);
    x[0] = 0;
    for(int i = 1; i<n; i++){
        cin >> x[i];
    };
    vector<ll> a(n);
    a[n-1] = 1e9;
    for(int i = n-2; i >= 0; i--){
        a[i] = a[i+1] - x[i+1];
    };
    for(int i = 0; i<n; i++){
        cout << a[i] << " ";
    };
    cout << endl;
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