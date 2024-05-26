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
    int n; cin >>n;
    vector<int> v(n);
    unordered_map<int, int> pos;
    for(int i = 0; i < n ; i++) {
        cin >> v[i];
        pos[v[i]] = i + 1; 
    }
    int m; cin >> m;
    long long vesya = 0, petya = 0;
    for(int j = 0 ; j< m ; j++){
        int x; cin >> x;
        vesya += pos[x];
        petya += n - pos[x] + 1;
    }
    cout << vesya << " " << petya << endl;
    return;
}

int main()
{
    fastio();
    solve();

    return 0;
}