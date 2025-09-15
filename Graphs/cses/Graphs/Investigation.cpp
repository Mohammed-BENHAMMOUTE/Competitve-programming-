#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod = 1e9 + 7;
const ll INF = 1e18;

void solve() {
    int n, m; 
    cin >> n >> m;
    vector<vector<pair<int,int>>> adj(n+1);
    
    for (int i = 0; i < m; i++) {
        int x, y, w; 
        cin >> x >> y >> w;
        adj[x].push_back({y, w});
    }
    
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
    vector<ll> dist(n+1, INF);
    vector<ll> routes(n+1, 0);
    vector<ll> min_f(n+1, INF);
    vector<ll> max_f(n+1, 0);
    
    // Initialize starting node
    dist[1] = 0;
    routes[1] = 1;
    min_f[1] = 0;
    max_f[1] = 0;
    pq.push({0, 1});
    
    while (!pq.empty()) {
        auto [d, c] = pq.top();
        pq.pop();
        
        // Skip if we've already found a better path
        if (d > dist[c]) continue;
        
        for (auto nei : adj[c]) {
            int next = nei.first;
            int w = nei.second;
            ll new_dist = d + w;
            
            if (new_dist > dist[next]) continue; // Skip if worse path
            
            if (new_dist == dist[next]) {
                // Same distance - update routes and min/max flights
                routes[next] = (routes[next] + routes[c]) % mod;
                min_f[next] = min(min_f[next], min_f[c] + 1);
                max_f[next] = max(max_f[next], max_f[c] + 1);
            }
            
            if (new_dist < dist[next]) {
                // Better path found
                dist[next] = new_dist;
                routes[next] = routes[c];
                min_f[next] = min_f[c] + 1;
                max_f[next] = max_f[c] + 1;
                pq.push({new_dist, next});
            }
        }
    }
    
    // Output results
    if (dist[n] == INF) {
        cout << "-1" << endl; // No path exists
    } else {
        cout << dist[n] << " " << routes[n] << " " << min_f[n] << " " << max_f[n] << endl;
    }
}

int main() {
    solve();
    return 0;
}
