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
    int n;
    ll l;
    cin >> n >> l;
    vector<ll> v;
    bool first = false;
    bool last = false;
    for(int i = 0; i<n ;i++) {
        long double x;
        cin >> x;
        if(x == 0) {
            first = true;
        };
        if(x == l) {
            last = true;
        };
        v.pb(x);
    };
    sort(v.begin(), v.end());

    double maxDff = 0;
    for(int i =1; i<n; i++) {
        maxDff = max(maxDff, (double) (v[i] - v[i-1])/2);
    };
    cout << fixed << setprecision(10) << max(maxDff, (double) max(v[0], l-v[n-1])) << endl;
}

int main()
{
    fastio();
    solve();
    return 0;
}