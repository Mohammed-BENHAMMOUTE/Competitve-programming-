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
vector<ll> dx = {1, 1, 1, 0, 0, -1, -1, -1};
vector<ll> dy = {1, 0, -1, 1, -1, 1, 0, -1};

void fastio()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
};
map<ll, vector<ll>> BuildAdj(map<ll,int> &m){
    map<ll, vector<ll>> adj;
    for(auto x : m){
        ll x1 = x.first/(1e9);
        ll y1 = x.first%((ll)1e9);
        for(int i = 0; i < 8; i++)
        {
            ll x2 = x1 + dx[i];
            ll y2 = y1 + dy[i];
            if(m.find(x2*(1e9)+y2) != m.end())
            {
                adj[x.first].pb(x2*(1e9)+y2);
            };
        };
    };
    return adj;
};
void  ssspBFS(ll s, ll d, map<ll, vector<ll>> &adj)
{
    map<ll, bool> visited;
    map<ll,ll> dist;
    queue<ll> q; q.push(s);
    ll dep  = 0, prev = -1, sz = 1;
    bool ok = true;
    for(;!q.empty() && ok; dep++, sz = q.size())
    {
        while(sz--){
            ll cur = q.front();q.pop();
            for(ll y: adj[cur]) if(visited[y] == false)
            {
                visited[y] = true;
                dist[y] = dep +1;
                q.push(y);
                if(y == d)
                {
                    cout << dist[d] << endl;
                    return;
                }
            }
        }
        
    };
    cout << -1 << endl;
    return;
}
void solve()
{
    map<ll, int> m;
    ll x0,y0,x1,y1;
    cin >> x0 >> y0 >> x1 >> y1;
    ll n; cin >> n;
    for(int i = 1;i <=n ; i++)
    {
        ll r,a,b;
        cin >> r >> a >> b;
        for(int j = a; j <= b; j++)
        {
            m[r*(1e9)+j] = 1;
        }
    };
    ll start= x0*(1e9)+y0;
    ll end = x1*(1e9)+y1;   
    map<ll, vector<ll>> adj = BuildAdj(m);
    ssspBFS(start, end, adj);
};
int main()
{
    fastio();
    solve();

    return 0;
}