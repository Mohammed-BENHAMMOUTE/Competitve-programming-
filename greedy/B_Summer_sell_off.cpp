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
    ll n; cin >> n;
    ll f ; cin >> f;// the number of days ain shop's plan, and the number o days that nora has to chooose
    vector<pair<ll, ll>> v;
    for(int i=1; i<=n;i++) {
        ll k,l; cin >> k >> l;// k the number of products on th eshelve and l is the number of clients that will come to the store
        v.pb(make_pair(k,l));
    };
    std::sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b){
        return (min(a.first*2, a.second)- min(a.first, a.second)) > (min(b.first*2, b.second)- min(b.first, b.second));
    });
    ll ans = 0;
    int count = f;
    for(int i =0; i< n ; i++ ){
        if(count >0 && v[i].first!= 0){
            ans += min(v[i].second, v[i].first*2);
            count--;
        } else {
            ans += min(v[i].first, v[i].second);
        }
    }
    cout << ans << endl;    
}

int main()
{
    fastio();
    solve();
    return 0;
}