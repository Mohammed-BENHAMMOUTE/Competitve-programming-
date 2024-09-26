#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define tc \
    ll tc; \
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

const int MAXN = 2005;

vector<vector<int>> adj(MAXN);
vector<int> vis(MAXN, 0);
vector<int> maxDepth(MAXN, 0);

void dfs(int v) {
    vis[v] = 1;
    maxDepth[v] = 1;
    for(auto u : adj[v]) {
        if(vis[u] == 0) {
            dfs(u);
        }
        maxDepth[v] = max(maxDepth[v], maxDepth[u] + 1);
    }
}

void solve()
{
    int n;
    cin >> n;
    adj.resize(n+1);
    vis.assign(n+1, 0);
    maxDepth.assign(n+1, 0);

    for(int i = 1; i <= n; i++)
    {
        int x; cin >> x;
        if(x != -1) {
            adj[x].pb(i);
        }
    }

    int result = 0;
    for(int i = 1; i <= n; i++) {
        if(vis[i] == 0) {
            dfs(i);
            result = max(result, maxDepth[i]);
        }
    }
    cout << result << endl;
}

int main()
{
    fastio();
    solve();
    return 0;
}