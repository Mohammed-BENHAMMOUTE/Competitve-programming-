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
    vector<ll> v(n+1);
    for(int i =1; i <= n ;i ++) {
        cin >> v[i];
    };
    vector<ll> copy = v;
    sort(copy.begin(), copy.end());
    for(int i = 1; i<=n; i++) {
        v[i]+= v[i-1];
        copy[i]+=copy[i-1];
    };
    int q; cin >>q;

    for(int i = 0; i < q; i++) 
    {
        int type; cin >> type;
        int l; cin >> l;
        int r; cin >> r;
        if(type == 1) {
            cout << v[r]-v[l-1] <<endl;
        }else{
            cout << copy[r]-copy[l-1]<<endl;
        };
    }
    return;
}

int main()
{
    fastio();
    solve();
    return 0;
}