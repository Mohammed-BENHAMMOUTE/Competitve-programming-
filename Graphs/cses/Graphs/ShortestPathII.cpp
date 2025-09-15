#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    
    // Initialize distance matrix with infinity
    vector<vector<long long>> dist(n + 1, vector<long long>(n + 1, LLONG_MAX));
    
    // Distance from a city to itself is 0
    for (int i = 1; i <= n; i++) {
        dist[i][i] = 0;
    }
    
    // Read roads (bidirectional)
    for (int i = 0; i < m; i++) {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        // Take minimum in case of multiple roads between same cities
        dist[a][b] = min(dist[a][b], c);
        dist[b][a] = min(dist[b][a], c);
    }
    
    // Floyd-Warshall algorithm
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][k] != LLONG_MAX && dist[k][j] != LLONG_MAX) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
    
    // Process queries
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        if (dist[a][b] == LLONG_MAX) {
            cout << -1 << "\n";
        } else {
            cout << dist[a][b] << "\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
