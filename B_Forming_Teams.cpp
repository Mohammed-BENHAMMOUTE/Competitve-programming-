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

int dfs(int u , vector<vector<int>> &adj , vector<int> &colors , int color) {
    colors[u] = color;
    int ans = 0;
    for(auto v : adj[u]) {
        if(colors[v] == -1){
            colors[v] = 1 - color;
            ans += dfs(v, adj, colors, 1 - color);
        }else{
            if(colors[v] == color) ans++;
        }
    }
    return ans;
}


void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n+1);
    vector<int> colors(n+1, -1);
    for(int i =0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        if(colors[i] == -1) {
            ans += dfs(i, adj, colors, 0);
        }
    }
    ans = ans/2;
    int left = n - ans;
    if(left % 2 == 0) {
        cout << ans << endl;
    }else{
        cout << ans + 1 << endl;
    }
}

int main()
{
    fastio();
    solve();

    return 0;
}