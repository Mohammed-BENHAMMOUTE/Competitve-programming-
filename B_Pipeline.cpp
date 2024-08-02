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

static long long eSUM(ll n) {
    cout << n*(n+1)/2 << endl;
    return (n*(n+1))/2;
};
static long long SumIndex(ll n, ll i) {
    return eSUM(n) - eSUM(i);
};
static long long minimumSpliter(ll n, ll k) {
    ll low =1;
    ll high = k;
    ll mid;
    while(low<high) {
        mid = low +(high - low)/2;
        if(SumIndex(k,mid) == n) {
            return k - mid;
        };
        if(SumIndex(k, mid) > n) {
            low = mid +1;
        }else{
            high = mid;
        };
    };
    return k - low +1;
};
void solve()
{
    ll n,k;
    cin >> n >> k;
    --n;
    --k;
    if (n == 0) {
        cout << 0 << endl;
        return;
    }else if(n <= k ) {
        cout << 1 << endl;
        return;
    }else if(eSUM(k) < n) {
        cout << -1 << endl;
        return;
    }
    else  {
        ll count = minimumSpliter(n,k);
        cout << count << endl;
        return;
    };

};
int main()
{
    fastio();
    solve();
    return 0;
};