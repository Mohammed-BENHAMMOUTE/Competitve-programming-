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
    map<ll, int> m;
    for(int i = 1; i <=n; i++) {
        cin >> v[i];
        m[v[i]] = i;
    };
    vector<ll> copy = v;
    sort(copy.begin(), copy.end());
    pair<int, int> p;
    p.first =1;
    p.second = 1;
    for(int i = 1; i <= n ; i++) {
        if(v[i] != copy[i]) {
            reverse(v.begin()+i, v.begin()+m[copy[i]]+1);
            p.first = i;
            p.second = m[copy[i]];
            break;
        }
    };
    for(int i = 1; i <= n; i++) {
        if(v[i] != copy[i]) {
            cout << "no" << endl;
            return;
        };
    };
    cout << "yes" << endl;
    cout << p.first << " " << p.second << endl;
    
}

int main()
{
    fastio();
    solve();

    return 0;
}