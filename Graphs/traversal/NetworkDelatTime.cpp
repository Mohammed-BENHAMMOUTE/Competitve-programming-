#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"
using namespace std;


class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n);
        // Build adjacency list
        for(const auto& time : times) {
            int u = time[0] - 1;  
            int v = time[1] - 1;
            int w = time[2];
            adj[u].push_back({v, w});
        }
        vector<int> distances(n, INT_MAX);
        distances[k-1] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        pq.push({0, k-1});
        while(!pq.empty()) {
            auto [dist, curr] = pq.top();
            pq.pop();
            if(dist > distances[curr]) continue;  
            for(auto [next, weight] : adj[curr]) {
                if(distances[next] > dist + weight) {
                    distances[next] = dist + weight;
                    pq.push({distances[next], next});
                }
            }
        }
        int maxDist = *max_element(distances.begin(), distances.end());
        return maxDist == INT_MAX ? -1 : maxDist;
    }
};
