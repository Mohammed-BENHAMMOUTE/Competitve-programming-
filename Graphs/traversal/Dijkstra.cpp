#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

class Solution {
public:
    vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
        int n = adj.size();
        vector<int> dist(n, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, src});
        dist[src] = 0;

        while (!pq.empty()) {
            int distance = pq.top().first;
            int  parent = pq.top().second;
            pq.pop();
            for (auto it : adj[parent]) {
                int child = it.first;
                int currDistance = it.second;
                if (dist[parent] + currDistance < dist[child]) {
                    dist[child] = dist[parent] + currDistance;
                    pq.push({dist[child], child});
                }
            }
        }
        return dist;
    }
};