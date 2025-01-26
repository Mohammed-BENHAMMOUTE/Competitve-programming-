#include <bits/stdc++.h>
using namespace std;

struct Cow {
    int x, y, p;
};

int main() {
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);
    
    int N;
    cin >> N;
    vector<Cow> cows(N);
    for (int i = 0; i < N; ++i) {
        cin >> cows[i].x >> cows[i].y >> cows[i].p;
    }
    
    vector<vector<int>> adj(N);
    for (int i = 0; i < N; ++i) {
        int xi = cows[i].x, yi = cows[i].y, pi = cows[i].p;
        int pi_sq = pi * pi;
        for (int j = 0; j < N; ++j) {
            int dx = xi - cows[j].x;
            int dy = yi - cows[j].y;
            int dist_sq = dx * dx + dy * dy;
            if (dist_sq <= pi_sq) {
                adj[i].push_back(j);
            }
        }
    }
    
    int max_count = 0;
    for (int i = 0; i < N; ++i) {
        vector<bool> visited(N, false);
        queue<int> q;
        q.push(i);
        visited[i] = true;
        int count = 0;
        
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            count++;
            for (int v : adj[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
        max_count = max(max_count, count);
    }
    
    cout << max_count << endl;
    return 0;
}