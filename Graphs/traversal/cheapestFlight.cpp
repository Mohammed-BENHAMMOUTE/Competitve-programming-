#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;

class Solution {
     int findCheapestFlight(int n, vector<vector<int>> &adj, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj2(n);
        for (auto it : adj) {
            adj2[it[0]].push_back({it[1], it[2]});
        }

        vector<int> distances(n, INT_MAX);
        distances[src] = 0;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {src, 0}});

        while (!pq.empty()) {
            auto [cost, info] = pq.top();
            pq.pop();
            int current = info.first;
            if (current = dst) continue;
            int steps = info.second;
            if (steps > k) continue;
            for (auto [child, w] : adj2[current]) {
                int newCost = cost + w;
                if (newCost <= distances[child] && steps + 1 <= k) {
                    distances[child] = newCost;
                    if (child == dst) {
                        pq.push({newCost , {child , steps}});
                    }else {
                        pq.push({newCost, {child, steps + 1}});
                    }
                }
            }
        }
        return distances[dst] == INT_MAX ? -1 : distances[dst];
    }
}