#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;

class Solution {
public:
    vector<int> topologicalSort(vector<vector<int>> &adj) {
        int n = adj.size();
        vector<int> result;  
        priority_queue<int, vector<int>, greater<int>> pq;  
        vector<int> indegree(n, 0);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < adj[i].size(); j++) {
                indegree[adj[i][j]]++;
            }
        }
        for(int i = 0; i < n; i++) {
            if(indegree[i] == 0) {
                pq.push(i);
            }
        }
        while(!pq.empty()) {
            int current = pq.top();
            pq.pop();
            result.push_back(current);

            for(int next : adj[current]) {
                indegree[next]--;
                if(indegree[next] == 0) {
                    pq.push(next);
                }
            }
        }
        if(result.size() != n) { // cycle
            return {}; 
        }

        return result;
    }
};