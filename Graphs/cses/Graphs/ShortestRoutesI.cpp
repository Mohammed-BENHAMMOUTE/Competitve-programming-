#include<bits/stdc++.h>
using namespace std;

struct Node {
    int vertex;
    long long distance;
    
    bool operator<(const Node& other) const {
        return distance > other.distance; // Min-heap
    }
};

void solve() {
    int n, m; 
    cin >> n >> m;
    
    vector<vector<pair<int, long long>>> adj(n + 1);
    vector<long long> dist(n + 1, LLONG_MAX);
    
    for(int i = 0; i < m; i++) {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }
    
    priority_queue<Node> pq;
    
    dist[1] = 0;
    pq.push({1, 0});
    
    while (!pq.empty()) {
        Node current = pq.top();
        pq.pop();
        
        int u = current.vertex;
        long long d = current.distance;
        
        // Skip if we've already found a shorter path
        if (d > dist[u]) continue;
        
        for (auto [v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({v, dist[v]});
            }
        }
    }
    
    // Print distances
    for (int i = 1; i <= n; i++) {
        cout << dist[i];
        if (i < n) cout << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
