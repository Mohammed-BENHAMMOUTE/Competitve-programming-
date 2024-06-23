#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    map<tuple<ll,ll,ll>, int> cnt;
    ll ans = 0;
    for(int i =0; i < n-2; i++) 
    {
        tuple<ll, ll,ll> z = {a[i], a[i+1], a[i+2]};
        tuple<ll ,ll ,ll> k[3];
        k[0] = make_tuple(0, a[i+1], a[i+2]);
        k[1] = make_tuple(a[i], 0, a[i+2]);
        k[2] = make_tuple(a[i], a[i+1], 0);
        for(int j =0; j < 3; j++){
            ans+=cnt[k[j]]- cnt[z];
            cnt[k[j]]++;
        };
        cnt[z]++;
    };
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}