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
    ll a, b;cin >> a >> b;
    int n;cin >> n;
    vector<ll> divisors;
    ll gcd = __gcd(a,b);
    divisors.pb(1);
    for(ll i = 2; i * i <= gcd ; i++){
        if(gcd % i == 0) {
            divisors.pb(i);
            if(i != gcd/i) {
                divisors.pb(gcd/i);
            }
        }
    }
    sort(divisors.begin(), divisors.end());
    divisors.pb(gcd);
    for(int i =0; i< n; i++) {
        ll low , high;
        cin >> low >> high;
        if (low > gcd) {
            cout << -1 << endl;
            continue;
        }
        auto y = upper_bound(divisors.begin(), divisors.end(), low);
        int index = y - divisors.begin();
        ll end = high;
        ll l = index-1, r = divisors.size() - 1;
        ll mid = 0;
        ll ans=-1;
        while(l <= r) {
            mid = l + (r-l)/2;
            if(divisors[mid] <= end) {
                ans = divisors[mid];
                l = mid + 1;
            } else {
                r = mid-1;
            }
        };
        if(ans<low) cout << -1 << endl;
        else cout << ans << endl;
    }
}

int main()
{
    fastio();
    solve();
    return 0;
}
//  we need all devisros between low and min(high, b) and then we need to find the greatest common divisor of all of them.