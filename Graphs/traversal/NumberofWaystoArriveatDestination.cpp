#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;
const int MOD  = 1e9 + 7;
class Solution {
public:
    int countPaths(int n, const vector<vector<int>>& roads) {
        vector<vector<pair<long long,long long>>> adj(n);
        for(auto& road : roads) {
            adj[road[0]].push_back({road[1], road[2]});
            adj[road[1]].push_back({road[0], road[2]});
        }
        
        vector<long long> dist(n, LLONG_MAX);
        vector<long long> ways(n, 0);
        priority_queue<pair<long long,long long>, 
                      vector<pair<long long,long long>>, 
                      greater<>> pq;
        
        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0}); // {distance, node}
        
        while(!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            
            if(d > dist[u]) continue;
            
            for(auto [v, time] : adj[u]) {
                if(dist[v] > d + time) {
                    dist[v] = d + time;
                    ways[v] = ways[u];
                    pq.push({dist[v], v});
                }
                else if(dist[v] == d + time) {
                    ways[v] = (ways[v] + ways[u]) % MOD;
                }
            }
        }
        return ways[n-1];
    }
};