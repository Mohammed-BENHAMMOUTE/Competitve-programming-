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
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void fastio()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
};
void solve()
{
    int n , m ,k ; cin >> n >> m >> k;
    vector<string> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int cntF = 0;
    pair<int,int> start = {-1,-1};
    vector<vector<int>> vis(n, vector<int>(m, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) {
            if(a[i][j] == '.') {
                start = (start.first == -1 ? mp(i , j) : start);
                cntF++;
            };
        }
    };
    function <bool(int,int)> isValid = [&](int x, int y) {
        return x >= 0 && x < n && y >= 0 && y < m;
    };
    function <void (int,int)> dfs = [&](int x, int y){
        vis[x][y]=1;
        for(int i = 0; i < 4 ; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(isValid(nx,ny) && a[nx][ny] == '.' && !vis[nx][ny]){
                dfs(nx,ny);
            }
        }
        if(k > 0){
            a[x][y] = 'X';
            k--;
        }
    };
    dfs(start.first, start.second);
    for(int i = 0; i < n; i++) {
        cout << a[i] << endl;
    }
    return;
}

int main()
{
    fastio();
    solve();
    return 0;
}
