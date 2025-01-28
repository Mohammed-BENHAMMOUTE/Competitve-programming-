#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;

class Solution {
public:
    bool isCyclic(int V, vector<vector<int>> adj) {
        vector<bool> visited(V, false);
        vector<bool> processed(V, false);
        
        for(int i = 0; i < V; i++) {
            if(!visited[i]) {
                if(dfs(i, adj, visited, processed)) {
                    return true;  // Cycle found
                }
            }
        }
        return false;  // No cycle found
    }
    
    bool dfs(int start, vector<vector<int>> &adj, vector<bool> &visited, vector<bool> &processed) {
        visited[start] = true;
        for(int neighbour : adj[start]) {
            if(!visited[neighbour]) {
                if(dfs(neighbour, adj, visited, processed)) {
                    return true;
                }
            }
            else if(!processed[neighbour]) {
                return true;
            }
        }
        processed[start] = true;
        return false;
    }
};