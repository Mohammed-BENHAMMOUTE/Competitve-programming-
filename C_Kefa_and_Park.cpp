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
    int n, m; cin >> n >> m;
    vector<int> a(n+1);
    for(int i  = 1; i <= n ; i++) {
        cin >> a[i];
    }
    vector<vector<int>> adj(n+1);
    for(int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vector<int> visited(n+1, 0);
    int ans = 0;
    function<void(int, int, int)> dfs = [&](int u , int cnt , int parent) {
        visited[u] = 1;
        cnt = (a[u] == 1) ? cnt+1 : 0;
        if(cnt > m) return;
        if(adj[u].size() == 1 && u != 1) {
            ans++;
            return;
        }
        for(auto v : adj[u]) {
            if(v != parent && !visited[v]) {
                dfs(v, cnt, u);
            }
        }
    };
    dfs(1, 0, -1);
    cout << ans << endl;
}

int main()
{
    fastio();
    solve();
    return 0;
}