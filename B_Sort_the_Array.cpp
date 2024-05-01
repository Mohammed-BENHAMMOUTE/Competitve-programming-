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
    vector<ll> v;
    for(int i = 0; i < n; i++) {
        ll x; cin >> x;
        v.pb(x);
    };
    if(n == 2) {
        if(v[0] > v[1]) {
            cout << "yes" << endl;
            cout << 1 << " " << 2 << endl;
        } else {
            cout << "yes" << endl;
            cout << 1 << " " << 1 << endl;
        };
        return;
    };
    vector<ll> copy = v;
    sort(copy.begin(), copy.end());
    map<ll, int> mp;
    for(int i = 0; i < n; i++) {
        mp[copy[i]] = i;
    };
    int start = 0, end = 0;
    for(int i = 0; i < n; i++) {
        if(v[i] != copy[i]) {
            start = i;
            break;
        };
    };
    for(int i = n-1; i >= 0; i--) {
        if(v[i] != copy[i]) {
            end = i;
            break;
        };
    };
    reverse(v.begin() + start, v.begin() + end + 1);
    for(int i = 0; i < n; i++) {
        if(v[i] != copy[i]) {
            cout << "no" << endl;
            return;
        };
    };
    cout << "yes" << endl;
    cout << start + 1 << " " << end + 1 << endl;
    return;

}

int main()
{
    fastio();
    solve();

    return 0;
}