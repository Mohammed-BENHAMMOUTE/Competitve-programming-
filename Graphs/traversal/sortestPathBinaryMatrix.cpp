#include <bits/stdc++.h>
using namespace std;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid) {
        int n = grid.size();
        if (grid[0][0] != 0 || grid[n-1][n-1] != 0) return -1;

        queue<pair<int, int>> q;
        vector<vector<int>> distance(n, vector<int>(n, -1));
        distance[0][0] = 1;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        q.push({0, 0});
        visited[0][0] = true;

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for (int i = 0; i < 8; i++) {
                int currentX = x + dx[i];
                int currentY = y + dy[i];
                if (currentX >= 0 && currentX < n && currentY >= 0 && currentY < n &&
                    grid[currentX][currentY] == 0 && !visited[currentX][currentY]) {
                    q.push({currentX, currentY});
                    distance[currentX][currentY] = distance[x][y] + 1;
                    visited[currentX][currentY] = true;
                }
            }
        }
        return distance[n-1][n-1];
    }
};