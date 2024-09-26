#include <bits/stdc++.h>
using namespace std;

#define in freopen("in.txt","r",stdin);
#define out freopen("out.txt","w",stdout);
#define ios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define sz(v) ((long long)((v).size()))
#define all(v) ((v).begin()),((v).end())
#define allr(v) ((v).rbegin()),((v).rend())
#define clr(v, d) memset(v, d, sizeof(v))
#define MP make_pair
#define s  second
#define f  first
const int OO = (int) 1e9;
int dx[8] = { 0, 0, -1, 1, 1, 1, -1, -1 };
int dy[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };
long long R, C, ans;
string grid[101];
int dis[101][101][16];
bool vis[101][101][16];
queue<pair<pair<int, int>, int>> q;

// Check if the current cell is valid (within the grid boundaries)
bool valid(int i, int j) {
    return (i >= 0 && i < R && j >= 0 && j < C);
}

// Check if the current cell can be visited based on the current key combination
bool CheckC(char c, int K) {
    return ((c == 'B' && (K & 1)) || (c == 'Y' && (K & 2)) || (c == 'R' && (K & 4)) || (c == 'G' && (K & 8)) || (c == '.') || (c == 'b') || (c == 'y') || (c == 'r') || (c == 'g') || (c == 'X') || (c == '*'));
}

// Breadth-First Search (BFS) to find the minimum number of steps to reach the exit
void BFS() {
    long long keys, newKeys, k, l, m, n;
    char c;
    while (!q.empty()) {
        k = q.front().f.f, l = q.front().f.s, keys = newKeys = q.front().s;
        q.pop();

        // If the current cell is the exit, update the answer and return
        if (grid[k][l] == 'X') {
            ans = dis[k][l][keys];
            return;
        }

        // Update the key combination based on the current cell
        if (grid[k][l] == 'b') {
            newKeys |= 1;
        } else if (grid[k][l] == 'y') {
            newKeys |= 2;
        } else if (grid[k][l] == 'r') {
            newKeys |= 4;
        } else if (grid[k][l] == 'g') {
            newKeys |= 8;
        }

        // Explore the neighboring cells
        for (int x = 0; x < 4; x++) {
            m = k + dx[x];
            n = l + dy[x];
            if (valid(m, n) && !vis[m][n][newKeys]) {
                c = grid[m][n];
                if (CheckC(c, newKeys)) {
                    dis[m][n][newKeys] = dis[k][l][keys] + 1;
                    vis[m][n][newKeys] = 1;
                    q.push({{m, n}, newKeys});
                }
            }
        }
    }

    while (!q.empty()) {
        q.pop();
    }
}

int main() {
    while ((cin >> R >> C) && (R || C)) {
        ans = -1, clr(vis, 0), clr(dis, 0);

        // Read the grid and find the starting position
        for (int i = 0; i < R; i++) {
            cin >> grid[i];
            for (int j = 0; j < C; j++) {
                if (grid[i][j] == '*') {
                    q.push({{i, j}, 0});
                }
            }
        }

        // Perform the BFS to find the minimum number of steps
        BFS();

        // Print the result
        if (ans == -1) {
            cout << "The poor student is trapped!" << endl;
        } else {
            cout << "Escape possible in " << ans << " steps." << endl;
        }
    }
    return 0;
}