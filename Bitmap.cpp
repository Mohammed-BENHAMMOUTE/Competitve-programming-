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
int dx[] = {1, -1, 0 , 0};
int dy[] = {0,0,1,-1};

void fastio()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

void solve()
{
    int n,m; cin >> n >> m;
    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
    queue<pair<int, int>> q;

    for(int i= 0; i < n; i++){
        string s; cin >> s;
        for(int j = 0; j < m; j++){
            if( s[j]== '1'){
                q.push(mp(i,j));
                dist[i][j] = 0;
            };
        };
    };
    while(!q.empty()){
        pair<int,int> p = q.front();
        int x = p.first;
        int y = p.second;
        q.pop();
        for(int i = 0; i < 4; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if(xx >= 0 && xx < n && yy >= 0 && yy < m && dist[xx][yy] > dist[x][y] + 1){
                dist[xx][yy] = dist[x][y]+1;
                q.push(mp(xx,yy));
            };
        };
    };
    for(int i =0 ;i < n ;i++) {
        for(int j = 0; j < m ;j++) {
            cout << dist[i][j] << " ";
        };
        cout<<endl;
    }
}

int main()
{
    fastio();
    ll t;
    cin >> t;
    for (ll i = 1; i <= t; i++)
    {
        solve();
    }

    return 0;
}