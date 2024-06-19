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
};
bool valid(vector<ll> &a, ll n) 
{
    ll k = __gcd(a[0], a[1]);
    for(int i =1; i <n-1; i++)
    {
        ll t = __gcd(a[i+1], a[i]);
        if(t < k) return false;
        k = t;
    };
    return true;
}

void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(int i =0; i < n; i++) cin >> a[i];
    if(valid(a, n)) 
    {
        cout << "YES" << endl;
        return;
    }
    ll y = __gcd(a[0], a[1]);
    int ind = 0;
    for(int i =1; i < n-1 ; i++)
    {
        ll x = __gcd(a[i], a[i+1]);
        if(x < y) 
        {
            ind = i;
            break;
        };
        y = x;
    };
    vector<ll> b0 = a, b1 = a, b2 = a;
    b0.erase(b0.begin() + ind);
    b1.erase(b1.begin() + ind + 1);
    b2.erase(b2.begin() + ind - 1);
    if(valid(b0, n-1) || valid(b1, n-1) || valid(b2, n-1)) 
    {
        cout << "YES" << endl;
        return;
    }else{
        cout << "NO" << endl;
        return;
    }

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