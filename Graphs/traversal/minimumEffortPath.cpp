#include <bits/stdc++.h>
using namespace std;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

class Solution {
public:
    int minimumEffortPath(vector<vector<int>> &heights) {
        int r = heights.size();
        int c = heights[0].size();
        vector<vector<int>> distances(r, vector<int>(c, INT_MAX));
        vector<vector<bool>> visited(r, vector<bool>(c, false));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {0, 0}});
        distances[0][0] = 0;

        while (!pq.empty()) {
            auto [w, cor] = pq.top();
            pq.pop();
            int x = cor.first, y = cor.second;
            if (visited[x][y]) continue;
            visited[x][y] = true;

            for (int i = 0; i < 4; i++) {
                int currX = x + dx[i];
                int currY = y + dy[i];
                if (currX >= 0 && currY >= 0 && currX < r && currY < c) {
                    int dist = max(w, abs(heights[x][y] - heights[currX][currY]));
                    if (dist < distances[currX][currY]) {
                        distances[currX][currY] = dist;
                        pq.push({dist, {currX, currY}});
                    }
                }
            }
        }
        return distances[r-1][c-1];
    }
};