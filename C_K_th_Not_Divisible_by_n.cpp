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
ll sipKthNotDivisibleByN(ll mid, ll k , ll n) {
    ll count  = (mid / n)*(n-1)+mid % n;
    return count >= k;
};

ll binary_search(ll n , ll k) {
    ll low = 0;
    ll high = 1e19;
    while(low <= high) {
        ll mid = low + (high - low)/2;
        if(sipKthNotDivisibleByN(mid,k,n)) {
            high = mid - 1;
        }else{
            low = mid +1 ;
        }
    }
    return low;
}

void solve()
{
    ll n,k;
    cin >> n >> k;
    if( k < n) {
        cout << k << endl;
        return;
    };
    if(k == 1) {
        cout << 1 << endl;
        return;
    }
    cout << binary_search(n,k) << endl;
    
    
};


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