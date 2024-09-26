#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define pb push_back
#define mp make_pair
const ll MOD = 1e9 + 7;
const int MAXN = 1000;

char grid[MAXN][MAXN];
int dist[MAXN][MAXN];
int visited[MAXN][MAXN];
const int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

void fastio() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

bool Valid(int x, int y, int n, int m) {
    return (x >= 0) && (x < n) && (y < m) && (y >= 0);
}

void solve() {
    int n, m;
    cin >> n >> m;
    int startx = -1, starty = -1, endx = -1, endy = -1;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if(grid[i][j] == 'S') {
                startx = i;
                starty = j;
            } else if(grid[i][j] == 'F') {
                endx = i;
                endy = j;
            }
            dist[i][j] = 0;
            visited[i][j] = 0;
        }
    }
    
    if(startx == -1 || endx == -1) {
        cout << -1 << endl;
        return;
    }
    
    queue<pair<int,int>> q;
    q.push({startx, starty});
    visited[startx][starty] = 255;
    
    while(!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        
        if(x == endx && y == endy) {
            cout << dist[x][y] << endl;
            return;
        }
        
        for(int dir = 0; dir < 8; dir++) {
            int nx = x, ny = y;
            while(true) {
                nx += dx[dir];
                ny += dy[dir];
                if(!Valid(nx, ny, n, m) || grid[nx][ny] == 'X' || (visited[nx][ny] & (1 << dir))) {
                    break;
                }
                if(!visited[nx][ny]) {
                    q.push({nx, ny});
                    dist[nx][ny] = dist[x][y] + 1;
                }
                visited[nx][ny] |= (1 << dir);
            }
        }
    }
    
    cout << -1 << endl;
}

int main() {
    fastio();
    ll t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}