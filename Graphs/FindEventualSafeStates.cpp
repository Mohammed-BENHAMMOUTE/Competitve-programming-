#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> rev_graph(n);
        for(int i =0 ; i < n ; i++){
            for(int x : graph[i])
            {
                rev_graph[x].push_back(i);
            }
        }
        vector<int> indegree(n, 0);
        for(int i = 0; i < n ; i++){
            for(int x : rev_graph[i])
            {
                indegree[x]++;
            }
        }
        queue<int> pq;
        for(int i =0 ; i < n ; i++){
            if(indegree[i] == 0) pq.push(i);
        }
        vector<int> ans;
        while(!pq.empty()){
            int current = pq.front(); pq.pop();
            ans.push_back(current);
            for(int x : rev_graph[current]){
                indegree[x]--;
                if(indegree[x] == 0){
                    pq.push(x);
                }
            }
        }
        sort(ans.begin() , ans.end());
        return ans;
    }
};