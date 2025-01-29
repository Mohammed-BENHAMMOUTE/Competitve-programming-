#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"
using namespace std;


class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // Create adjacency list
        vector<vector<int>> adj(numCourses);
        for(auto& pre : prerequisites) {
            adj[pre[1]].push_back(pre[0]);
        }
        
        // Calculate indegree
        vector<int> indegree(numCourses, 0);
        for(int i = 0; i < numCourses; i++) {
            for(int x : adj[i]) {
                indegree[x]++;
            }
        }
        
        // Find starting nodes with indegree 0
        queue<int> q;
        for(int i = 0; i < numCourses; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
        
        // Perform topological sort
        vector<int> topoSort;
        while(!q.empty()) {
            int current = q.front(); 
            q.pop();
            topoSort.push_back(current);
            
            for(int neighbour : adj[current]) {
                indegree[neighbour]--;
                if(indegree[neighbour] == 0) {
                    q.push(neighbour);
                }
            }
        }
        
        // Check if valid order found
        return topoSort.size() == numCourses ? topoSort : vector<int>();
    }
};