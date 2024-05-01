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
    int n,k ;
    cin >> n >> k;
    vector<int> v(n);
    vector<pair<int, int>> ops;
    for(int i = 0; i< n ; i++){
        int x; cin >> x;
        v[i] = x;
    };
    int i =0;
    for(i = 0 ; i<k ; i++) {
        auto small = distance(v.begin(), min_element(v.begin(), v.end()));
        auto large = distance(v.begin(), max_element(v.begin(), v.end()));
        if(v[large] - v[small] <= 1) break;
        v[large]--;
        v[small]++;
        ops.pb(make_pair(large+1, small+1));
    };
    cout << *max_element(v.begin(), v.end()) - *min_element(v.begin(), v.end()) << " " << ops.size() << endl;
    for(auto x: ops) {
        cout << x.first << " " << x.second << endl;
    };
    return;
}

int main()
{
    fastio();
    solve();

    return 0;
}