#include<bits/stdc++.h>
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define endl "\n"
using namespace std;
class Solution {
public:
    int shortestPath(int source, int destination, vector<vector<int>> &adj) {
        int n = adj.size();
        vector<int> distance(n, INT_MAX);
        queue<int> q;
        q.push(source);
        distance[source] = 0;
        while (!q.empty()) {
            int current = q.front();
            q.pop();
            for (int neighbour : adj[current]) {
                if (distance[current] + 1 < distance[neighbour]) {
                    distance[neighbour] = distance[current] + 1;
                    q.push(neighbour);
                }
            }
        }
        return distance[destination] == INT_MAX ? -1 : distance[destination];
    }
};