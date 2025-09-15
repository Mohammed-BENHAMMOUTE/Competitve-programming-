#include<bits/stdc++.h>
#include <functional>
#define ll long long
using namespace std;

void solve() {
    int n, m, k; 
    cin >> n >> m >> k;
    
    vector<vector<pair<int,ll>>> adj(n+1);
    for (int i = 0; i < m; i++) {
        int x, y;
        ll w;
        cin >> x >> y >> w;
        adj[x].push_back({y, w});
    }
    
    vector<vector<ll>> dist(n+1);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
    pq.push({0, 1});
    
    while(!pq.empty()) {
        ll d = pq.top().first;
        int current = pq.top().second; 
        pq.pop();
        
        // If we already have k distances, check if this one is worth adding
        if(dist[current].size() == k) {
            // Sort to find the actual largest element
            sort(dist[current].begin(), dist[current].end());
            if(d >= dist[current][k-1]) {
                continue; // This distance is not better than our k-th best
            }
            // Replace the worst (last) element with this better one
            dist[current][k-1] = d;
            // Re-sort to maintain order (could use insertion sort for efficiency)
            sort(dist[current].begin(), dist[current].end());
        } else {
            // We have less than k distances, just add it
            dist[current].push_back(d);
            // Keep sorted for efficient comparison later
            sort(dist[current].begin(), dist[current].end());
        }
        
        // Explore neighbors
        for(auto nei : adj[current]) {
            int next = nei.first;
            ll w = nei.second;
            
            if (dist[next].size() < k) {
                pq.push({w+d, next});
            } else {
                // dist[next] is already sorted from previous processing
                if(w+d < dist[next][k-1]) {
                    pq.push({w+d, next});
                }
            }
        }
    }
    
    // dist[n] is already sorted from the main loop
    for (int i = 0; i < k; i++) {
        cout << dist[n][i];
        if (i < k - 1) cout << " ";
    }
    cout << "\n";
}

int main() {
    solve();
    return 0;
}
