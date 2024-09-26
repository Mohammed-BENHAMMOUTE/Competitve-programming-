#include <bits/stdc++.h>
using namespace std;

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

struct State {
    int x, y, tiles;
    State(int x, int y, int tiles) : x(x), y(y), tiles(tiles) {}
};

bool valid(int x, int y, int h, int w, vector<vector<char>>& grid) {
    return x >= 0 && x < h && y >= 0 && y < w && grid[x][y] != 'x';
}

int solve(int h, int w, vector<vector<char>>& grid) {
    int start_x, start_y;
    int dirty_tiles = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (grid[i][j] == 'o') {
                start_x = i, start_y = j;
            } else if (grid[i][j] == '*') {
                dirty_tiles++;
            }
        }
    }

    queue<State> q;
    vector<vector<int>> visited(h, vector<int>(w, 0));
    q.emplace(start_x, start_y, 0);
    visited[start_x][start_y] = 1;
    int moves = 0;
    int cleaned_tiles = 0;

    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            auto [x, y, tiles] = q.front();
            q.pop();

            if (grid[x][y] == '*') {
                tiles |= (1 << cleaned_tiles);
                cleaned_tiles++;
                grid[x][y] = '.';
            }

            if (cleaned_tiles == dirty_tiles) {
                return moves;
            }

            for (int j = 0; j < 4; j++) {
                int nx = x + dx[j];
                int ny = y + dy[j];
                if (valid(nx, ny, h, w, grid) && !(visited[nx][ny] & (1 << tiles))) {
                    visited[nx][ny] |= (1 << tiles);
                    q.emplace(nx, ny, tiles);
                }
            }
        }
        moves++;
    }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int w, h;
    while (cin >> w >> h && (w || h)) {
        vector<vector<char>> grid(h, vector<char>(w));
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> grid[i][j];
            }
        }
        cout << solve(h, w, grid) << "\n";
    }

    return 0;
}