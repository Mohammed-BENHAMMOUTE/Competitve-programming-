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
bool fits(vector<ll> &a, int start, int end, ll x)
{
    for(int i = start; i<= end; i++) {
        if((a[i-1] & x) == x) {
            return true;
        }
    }
    return false;
}
void solve()
{
    int n; cin >> n;
    vector<ll> a;
    vector<ll> prefixe(n+1, 0); 
    for(int i = 1; i<= n; i++) {
        ll x; cin >> x;
        a.pb(x);
        prefixe[i] = (prefixe[i-1]|x);
        // cout << prefixe[i] << " ";
    };
    // cout << endl;
    //  binary search to find the minimum length of the subarray such that all the subarrays of the same length have the same | value
    int start = 1, end = n;
    while(start < end) {
        int mid = (start + end) / 2;
        bool found = false;
        for(int i = 0; i + mid <= n; i++) {
            if(!fits(a, i, i+mid-1, prefixe[n] ^ prefixe[i] )) {
                found = true;
                break;
            }
        }
        if(found) {
            start = mid + 1;
        } else {
            end = mid;
        }
    };
    cout << start << endl;
}

int main()
{
    fastio();
    ll t;
    cin >> t;
    for (ll i = 1; i <= t; i++)
    {
        solve();
    };
    return 0;
}