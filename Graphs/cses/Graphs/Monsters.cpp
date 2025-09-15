/*
 * Author: Mohammed BENHAMMOUTE
 * Created: 2025-09-07 07:07:08
 */
#include <bits/stdc++.h>
using namespace std;

// Debug macros
#define debug(x) cerr << #x << " = " << x << endl
#define debugv(v) cerr<<#v<<" = ";for(auto e:v)cerr<<e<<" ";cerr<<endl
#define debugm(m) cerr<<#m<<endl;for(auto e:m)cerr<<e.first<<" "<<e.second<<endl
#define debuga(a,n) cerr<<#a<<" = ";for(int i=0;i<n;i++)cerr<<a[i]<<" ";cerr<<endl
#define debugma(a,n,m) cerr<<#a<<":\n";for(int i=0;i<n;i++){for(int j=0;j<m;j++)cerr<<a[i][j]<<" ";cerr<<endl;}

// Type definitions
#define ll long long
#define ld long double
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vi vector<int>
#define vl vector<ll>
#define vvi vector<vi>
#define vvl vector<vl>
#define vpii vector<pii>
#define vpll vector<pll>

// Shortcuts
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define sz(x) (int)x.size()
#define rep(i,a,b) for(int i=a;i<b;i++)
#define per(i,a,b) for(int i=b-1;i>=a;i--)

// Constants
const int MOD = 1e9+7;
const ll INF = 1e18;
const ld PI = acos(-1.0);
const int dx[8] = {1,-1,0,0,1,1,-1,-1};
const int dy[8] = {0,0,1,-1,1,-1,1,-1};

// Utility functions
template<typename T> inline T gcd(T a, T b) {return b ? gcd(b, a%b) : a;}
template<typename T> inline T lcm(T a, T b) {return a * (b/gcd(a,b));}
template<typename T> inline T mod(T a, T b) {return (a%b + b)%b;}
template<typename T> inline T modpow(T a, T b, T m) {T r=1; while(b) {if(b&1) r=r*a%m; a=a*a%m; b>>=1;} return r;}

// Vector operations
template<typename T> void amax(T &a, T b) {if(b > a) a = b;}
template<typename T> void amin(T &a, T b) {if(b < a) a = b;}
template<typename T> void print(vector<T> &v) {for(auto x:v) cout<<x<<" "; cout<<endl;}
template<typename T> void print2d(vector<vector<T>> &v) {for(auto x:v) {for(auto y:x) cout<<y<<" "; cout<<endl;}}

// Fast I/O
void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << fixed << setprecision(10);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        freopen("error.txt", "w", stderr);
    #endif
}

// Direction vectors and characters for movement
const int dr[] = {1, -1, 0, 0};
const int dc[] = {0, 0, -1, 1};
const char dir_char[] = {'D', 'U', 'L', 'R'};

struct Position {
    int r, c;
    Position(int row = 0, int col = 0) : r(row), c(col) {}
};

// Helper functions
bool isValid(int r, int c, int n, int m) {
    return r >= 0 && r < n && c >= 0 && c < m;
}

bool isBoundary(int r, int c, int n, int m) {
    return r == 0 || r == n - 1 || c == 0 || c == m - 1;
}

// Calculate minimum time for monsters to reach each cell using multi-source BFS
vector<vector<int>> calculateMonsterTimes(const vector<string>& grid, 
                                        const vector<Position>& monsters, 
                                        int n, int m) {
    vector<vector<int>> monster_time(n, vector<int>(m, INT_MAX));
    queue<Position> q;
    
    // Initialize all monster positions with time 0
    for (const auto& monster : monsters) {
        monster_time[monster.r][monster.c] = 0;
        q.push(monster);
    }
    
    // Multi-source BFS to calculate minimum arrival times
    while (!q.empty()) {
        Position curr = q.front();
        q.pop();
        
        for (int dir = 0; dir < 4; dir++) {
            int nr = curr.r + dr[dir];
            int nc = curr.c + dc[dir];
            
            if (isValid(nr, nc, n, m) && grid[nr][nc] != '#') {
                int new_time = monster_time[curr.r][curr.c] + 1;
                if (new_time < monster_time[nr][nc]) {
                    monster_time[nr][nc] = new_time;
                    q.push(Position(nr, nc));
                }
            }
        }
    }
    
    return monster_time;
}

// Parse grid and extract positions
void parseGrid(const vector<string>& grid, int n, int m, 
               Position& start, vector<Position>& monsters) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'A') {
                start = Position(i, j);
            } else if (grid[i][j] == 'M') {
                monsters.push_back(Position(i, j));
            }
        }
    }
}

// Reconstruct and output the path from start to boundary
void outputPath(const vector<vector<int>>& parent_dir, Position start, Position end) {
    vector<int> path;
    Position curr = end;
    
    // Trace back the path using parent directions
    while (parent_dir[curr.r][curr.c] != -1) {
        path.push_back(parent_dir[curr.r][curr.c]);
        int prev_dir = parent_dir[curr.r][curr.c];
        // Move to parent position (reverse direction)
        curr.r -= dr[prev_dir];
        curr.c -= dc[prev_dir];
    }
    
    cout << "YES\n";
    cout << path.size() << "\n";
    
    // Output path in correct order (reverse of traced path)
    for (int i = path.size() - 1; i >= 0; i--) {
        cout << dir_char[path[i]];
    }
    cout << "\n";
}

// Find shortest safe path using BFS
bool findEscapePath(const vector<string>& grid, 
                   const vector<vector<int>>& monster_time,
                   Position start, int n, int m) {
    vector<vector<int>> player_time(n, vector<int>(m, -1));
    vector<vector<int>> parent_dir(n, vector<int>(m, -1));
    queue<Position> q;
    
    // Initialize player's starting position
    player_time[start.r][start.c] = 0;
    q.push(start);
    
    while (!q.empty()) {
        Position curr = q.front();
        q.pop();
        
        // Check if we reached the boundary
        if (isBoundary(curr.r, curr.c, n, m)) {
            outputPath(parent_dir, start, curr);
            return true;
        }
        
        // Explore all 4 directions
        for (int dir = 0; dir < 4; dir++) {
            int nr = curr.r + dr[dir];
            int nc = curr.c + dc[dir];
            
            if (isValid(nr, nc, n, m) && 
                grid[nr][nc] != '#' && 
                player_time[nr][nc] == -1) {
                
                int new_time = player_time[curr.r][curr.c] + 1;
                
                // Only move if player arrives before any monster
                if (new_time < monster_time[nr][nc]) {
                    player_time[nr][nc] = new_time;
                    parent_dir[nr][nc] = dir;
                    q.push(Position(nr, nc));
                }
            }
        }
    }
    
    return false; // No safe path found
}

void solve() {
    int n, m;
    cin >> n >> m;
    
    // Read the grid
    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }
    
    // Parse grid to find start position and monsters
    Position start;
    vector<Position> monsters;
    parseGrid(grid, n, m, start, monsters);
    
    // Calculate minimum time for monsters to reach each cell
    vector<vector<int>> monster_time = calculateMonsterTimes(grid, monsters, n, m);
    
    // Check if starting position is immediately unsafe
    if (monster_time[start.r][start.c] <= 0) {
        cout << "NO\n";
        return;
    }
    
    // Try to find a safe escape path
    if (!findEscapePath(grid, monster_time, start, n, m)) {
        cout << "NO\n";
    }
}

int main() {
    fastIO();
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}